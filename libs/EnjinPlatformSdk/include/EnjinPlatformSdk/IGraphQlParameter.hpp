#ifndef ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <memory>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlParameter;

/// \brief Definition for a pointer containing a GraphQL parameter type.
using GraphQlParameterPtr [[maybe_unused]] = std::unique_ptr<IGraphQlParameter<>>;

/// \brief Interface for complex GraphQL parameters.
template<class...>
class IGraphQlParameter : public IGraphQlParameterHolder<>,
                          public IGraphQlUploadHolder,
                          public ISerializable
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameter() override = default;
};

/// \brief Interface for setting inner parameters for complex GraphQL parameters.
/// \tparam TParameter The parameter type. Must implement this interface.
template<class TParameter>
class IGraphQlParameter<TParameter> : public IGraphQlParameter<>,
                                      public IGraphQlParameterHolder<TParameter>
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameter() override = default;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP
