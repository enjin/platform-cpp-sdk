#ifndef ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
#define ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <map>
#include <sstream>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL inputs which hold parameters.
/// \tparam THolder The type of the parameter holder. Must extend this class.
template<class THolder>
class GraphQlParameterHolder : public virtual IGraphQlParameterHolder<THolder>
{
    std::map<std::string, SerializablePtr> _parameters;

    static constexpr char ColonSeparator[] = ": ";
    static constexpr char CommaSeparator[] = ", ";

public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlParameterHolder(const GraphQlParameterHolder<THolder>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlParameterHolder(GraphQlParameterHolder<THolder>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlParameterHolder() override = default;

    GraphQlParameterHolder& operator=(const GraphQlParameterHolder<THolder>& rhs) = default;

    GraphQlParameterHolder& operator=(GraphQlParameterHolder<THolder>&& rhs) noexcept = default;

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override
    {
        if (!HasParameters())
        {
            return {};
        }

        std::stringstream ss;

        const int parametersCount = _parameters.size();
        int parameterIdx = 0;

        for (const auto& [k, v] : _parameters)
        {
            parameterIdx++;

            if (v == nullptr)
            {
                continue;
            }

            ss << k << ColonSeparator << v->ToString();

            if (parameterIdx < parametersCount)
            {
                ss << CommaSeparator;
            }
        }

        return ss.str();
    }

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override
    {
        return _parameters;
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameter(const std::string& key) const override
    {
        return _parameters.contains(key);
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return !_parameters.empty();
    }

    [[maybe_unused]]
    THolder& RemoveParameter(const std::string& key) override
    {
        _parameters.erase(key);

        return static_cast<THolder&>(*this);
    }

    [[maybe_unused]]
    THolder& SetParameter(std::string key, SerializablePtr value) override
    {
        if (value == nullptr)
        {
            _parameters.erase(key);
        }
        else
        {
            _parameters.emplace(key, value);
        }

        return static_cast<THolder&>(*this);
    }

    // endregion IGraphQlParameterHolder

protected:
    /// \brief Constructs an instance of this class.
    GraphQlParameterHolder() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
