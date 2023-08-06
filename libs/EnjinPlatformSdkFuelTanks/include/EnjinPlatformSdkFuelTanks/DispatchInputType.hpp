#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHINPUTTYPE_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHINPUTTYPE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/SerializableJsonValue.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchCall.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class DispatchInputType;

/// \brief Definition for a pointer containing a DispatchInputType.
using DispatchInputTypePtr [[maybe_unused]] = std::shared_ptr<DispatchInputType>;

class ENJINPLATFORMSDKFUELTANKS_EXPORT DispatchInputType : public GraphQlParameter<DispatchInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DispatchInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DispatchInputType(const DispatchInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DispatchInputType(DispatchInputType&& other) noexcept;

    /// \brief Class destructor.
    ~DispatchInputType() override;

    /// \brief Sets the dispatch call options.
    /// \param call The call option.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchInputType& SetCall(DispatchCall call);

    /// \brief Sets the GraphQL query required to query the 'id' and 'encodedData' from the result.
    /// \param query The GraphQL query.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchInputType& SetQuery(SerializableStringPtr query);

    /// \brief Sets the GraphQL query variables.
    /// \param variables The GraphQL variables.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    DispatchInputType& SetVariables(SerializableJsonValuePtr variables);

    DispatchInputType& operator=(const DispatchInputType& rhs);

    DispatchInputType& operator=(DispatchInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHINPUTTYPE_HPP
