#ifndef ENJINPLATFORMSDK_GRAPHQLREQUESTBASE_HPP
#define ENJINPLATFORMSDK_GRAPHQLREQUESTBASE_HPP

#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdk/GraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract base class for GraphQL requests to extend from.
/// \tparam TRequest The request class.
template<class TRequest>
class GraphQlRequestBase : public GraphQlParameterHolder<TRequest>,
                           public GraphQlUploadHolder,
                           public IGraphQlRequest<TRequest>
{
    const std::string _name;
    const GraphQlRequestType _type;
    std::string _resultHeader;
    std::string _typeName;
    std::map<std::string, std::pair<std::string, SerializablePtr>> _variables;

    static constexpr char ColonSeparator[] = ": ";
    static constexpr char CommaSeparator[] = ", ";
    static constexpr char EmptyObject[] = "{}";

public:
    GraphQlRequestBase() = delete;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlRequestBase(const GraphQlRequestBase<TRequest>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlRequestBase(GraphQlRequestBase<TRequest>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlRequestBase() override = default;

    GraphQlRequestBase& operator=(const GraphQlRequestBase<TRequest>& rhs) = default;

    GraphQlRequestBase& operator=(GraphQlRequestBase<TRequest>&& rhs) noexcept = default;

    // region IGraphQlRequest

    [[maybe_unused]]
    [[nodiscard]]
    std::string GetName() const override
    {
        return _name;
    }

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue GetVariablesJson() const override
    {
        JsonValue json = JsonValue::FromJson(EmptyObject);

        for (const auto& [k, v] : _variables)
        {
            json.TrySetField(k, v.second->ToJson());
        }

        return json;
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasVariables() const override
    {
        return !_variables.empty();
    }

    TRequest& SetVariable(std::string name, std::string type, SerializablePtr value) override
    {
        if (value == nullptr)
        {
            _variables.erase(name);
        }
        else
        {
            std::pair<std::string, SerializablePtr> pair(std::move(type), std::move(value));
            _variables.emplace(std::move(name), std::move(pair));
        }

        return static_cast<TRequest&>(*this);
    }

    // endregion IGraphQlRequest

    // region IGraphQlUploadHolder

    [[maybe_unused]]
    [[nodiscard]]
    const std::set<std::string>& GetUploadParameterPaths() const override
    {
        return GraphQlUploadHolder::GetUploadParameterPaths();
    }

    // endregion IGraphQlUploadHolder

protected:
    /// \brief Base constructor to be used by GraphQL requests.
    /// \param name The name of the request.
    /// \param type The type of the request.
    /// \throws std::out_of_range If request type is not a valid value.
    GraphQlRequestBase(std::string name, GraphQlRequestType type)
        : _name(std::move(name)),
          _type(type)
    {
        _resultHeader = " { result: " + _name;

        switch (_type)
        {
            case GraphQlRequestType::Mutation:
                _typeName = "mutation";
                break;

            case GraphQlRequestType::Query:
                _typeName = "query";
                break;

            default:
                throw std::out_of_range("Request type is out of range");
        }
    }

    /// \brief Appends the necessary beginning portion for the compiled request to the given string stream, leaving only
    /// the closing brace and any fragment fields to be appended.
    /// \param ss The string stream to write to.
    void AppendHeader(std::stringstream& ss) const
    {
        ss << _typeName;
        AppendVariables(ss);

        ss << _resultHeader;
        AppendParameters(ss);
    }

private:
    /// \brief Appends any parameters to the stream being used to build the request header.
    /// \param ss The string stream.
    void AppendParameters(std::stringstream& ss) const
    {
        const bool hasVariables = HasVariables();
        const bool hasParameters = static_cast<const TRequest&>(*this).HasParameters();

        if (!hasVariables && !hasParameters)
        {
            return;
        }

        ss << "(";

        if (hasVariables)
        {
            const int count = _variables.size();
            int i = 0;

            for (const auto& [k, v] : _variables)
            {
                ss << k << ColonSeparator << "$" << k;

                if (i < count - 1)
                {
                    ss << CommaSeparator;
                }

                i++;
            }

            if (hasParameters)
            {
                ss << CommaSeparator;
            }
        }

        if (hasParameters)
        {
            ss << static_cast<const TRequest&>(*this).CompileParameters();
        }

        ss << ")";
    }

    /// \brief Appends any variables to the stream being used to build the request header.
    /// \param ss The string stream.
    void AppendVariables(std::stringstream& ss) const
    {
        if (!HasVariables())
        {
            return;
        }

        ss << " (";

        const int count = _variables.size();
        int i = 0;

        for (const auto& [k, v] : _variables)
        {
            ss << "$" << k << ColonSeparator << v.first;

            if (i < count - 1)
            {
                ss << CommaSeparator;
            }

            i++;
        }

        ss << ")";
    }
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLREQUESTBASE_HPP
