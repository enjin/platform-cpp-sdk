#ifndef ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP
#define ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP

#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/GraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlParameter.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <stdexcept>
#include <string>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for complex GraphQL parameters.
/// \tparam TParameter The parameter type. Must extend this class.
template<class TParameter>
class GraphQlParameter : public GraphQlParameterHolder<TParameter>,
                         public GraphQlUploadHolder,
                         virtual public IGraphQlParameter<TParameter>
{
public:
    /// \brief Class destructor.
    ~GraphQlParameter() override = default;

    // region IGraphQlParameterHolder

    /// \brief Sets parameter to be stored by this parameter.
    /// \param key The parameter key.
    /// \param value The parameter value.
    /// \return This parameter for chaining.
    /// \throws std::invalid_argument If value is this instance.
    [[maybe_unused]]
    TParameter& SetParameter(std::string key, SerializablePtr value) override
    {
        if (this == value.get())
        {
            throw std::invalid_argument("Cannot pass caller for value parameter");
        }

        return GraphQlParameterHolder<TParameter>::SetParameter(std::move(key), std::move(value));
    }

    // endregion IGraphQlParameterHolder

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override
    {
        JsonValue json = JsonValue::FromJson("{}");

        for (const auto& [k, v] : GraphQlParameterHolder<TParameter>::GetParameters())
        {
            json.TrySetField(k, v->ToJson());
        }

        return json;
    }

    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override
    {
        return ToJson().ToString();
    }

    // endregion ISerializable

protected:
    /// \brief Constructs an instance of this class.
    GraphQlParameter() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP
