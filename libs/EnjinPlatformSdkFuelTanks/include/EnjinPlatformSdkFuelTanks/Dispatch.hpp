#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCH_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCH_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchInputType.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation to dispatch a call using the tankId subject to the rules of ruleSetId.
class ENJINPLATFORMSDKFUELTANKS_EXPORT Dispatch : public GraphQlRequest<Dispatch, TransactionFragment>,
                                                  public HasIdempotencyKey<Dispatch>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Dispatch();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Dispatch(const Dispatch& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Dispatch(Dispatch&& other) noexcept;

    /// \brief Class destructor.
    ~Dispatch() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    Dispatch& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    Dispatch& SetRuleSetId(SerializableStringPtr ruleSetId);

    /// \brief Sets the dispatch call.
    /// \param dispatch The dispatch call.
    /// \return This request for chaining.
    [[maybe_unused]]
    Dispatch& SetDispatch(DispatchInputTypePtr dispatch);

    /// \brief Sets the flag for paying the remaining fee. May default to false by the platform if not set.
    /// \param paysRemainingFee The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    Dispatch& SetPaysRemainingFee(SerializableBoolPtr paysRemainingFee);

    Dispatch& operator=(const Dispatch& rhs);

    Dispatch& operator=(Dispatch&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCH_HPP
