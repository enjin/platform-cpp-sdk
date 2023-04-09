#ifndef ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
#define ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/IStringSerializable.hpp"
#include <map>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL inputs which hold parameters.
/// \tparam THolder The type of the parameter holder. Must extend this class.
template<class THolder>
class GraphQlParameterHolder : public IGraphQlParameterHolder<THolder>
{
    std::map<std::string, std::vector<StringSerializablePtr>> _listedParameters;
    std::map<std::string, StringSerializablePtr> _nonListedParameters;

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

    /// \brief Returns the parameters that are comprised of arrays.
    /// \return The array parameters.
    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, std::vector<StringSerializablePtr>>& GetListedParameters() const
    {
        return _listedParameters;
    }

    /// \brief Returns the parameters that are not comprised of arrays.
    /// \return The non-array parameters.
    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, StringSerializablePtr>& GetNonListedParameters() const
    {
        return _nonListedParameters;
    }

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

        const int parametersCount = _nonListedParameters.size() + _listedParameters.size();
        int parameterIdx = 0;

        for (const auto& [k, v] : _nonListedParameters)
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

        for (const auto& [k, v] : _listedParameters)
        {
            ss << k << ": [";

            const int subParametersCount = v.size();
            int subParameterIdx = 0;

            for (const StringSerializablePtr& subParameter : v)
            {
                subParameterIdx++;

                if (subParameter == nullptr)
                {
                    continue;
                }

                ss << subParameter->ToString();

                if (subParameterIdx < subParametersCount)
                {
                    ss << CommaSeparator;
                }
            }

            ss << "]";

            if (parameterIdx < parametersCount - 1)
            {
                ss << CommaSeparator;
            }

            parameterIdx++;
        }

        return ss.str();
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return !_nonListedParameters.empty() || !_listedParameters.empty();
    }

    [[maybe_unused]]
    THolder& SetParameter(std::string key, StringSerializablePtr value) override
    {
        _listedParameters.erase(key);

        if (value == nullptr)
        {
            _nonListedParameters.erase(key);
        }
        else
        {
            _nonListedParameters.emplace(key, value);
        }

        return static_cast<THolder&>(*this);
    }

    [[maybe_unused]]
    THolder& SetParameter(std::string key, std::vector<StringSerializablePtr> values) override
    {
        _nonListedParameters.erase(key);
        _listedParameters.emplace(key, values);

        return static_cast<THolder&>(*this);
    }

    // endregion IGraphQlParameterHolder

protected:
    /// \brief Constructs an instance of this class.
    GraphQlParameterHolder() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
