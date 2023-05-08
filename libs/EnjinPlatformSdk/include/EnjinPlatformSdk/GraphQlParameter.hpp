#ifndef ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP
#define ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP

#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/GraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlParameter.hpp"
#include <stdexcept>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for complex GraphQL parameters.
/// \tparam TParameter The parameter type. Must extend this class.
template<class TParameter>
class GraphQlParameter : public GraphQlParameterHolder<TParameter>,
                         public GraphQlUploadHolder,
                         public IGraphQlParameter<TParameter>
{
public:
    /// \brief Class destructor.
    ~GraphQlParameter() override = default;

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override
    {
        return GraphQlParameterHolder<TParameter>::CompileParameters();
    }

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override
    {
        return GraphQlParameterHolder<TParameter>::GetParameters();
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return GraphQlParameterHolder<TParameter>::HasParameters();
    }

    [[maybe_unused]]
    TParameter& RemoveParameter(const std::string& key) override
    {
        return GraphQlParameterHolder<TParameter>::RemoveParameter(key);
    }

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

    // region IGraphQlUploadHolder

    [[maybe_unused]]
    [[nodiscard]]
    const std::set<std::string>& GetUploadParameterPaths() const override
    {
        return GraphQlUploadHolder::GetUploadParameterPaths();
    }

    // endregion IGraphQlUploadHolder

protected:
    /// \brief Constructs an instance of this class.
    GraphQlParameter() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLPARAMETER_HPP