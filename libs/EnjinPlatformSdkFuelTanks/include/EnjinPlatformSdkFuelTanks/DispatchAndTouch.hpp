#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHANDTOUCH_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHANDTOUCH_HPP

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
/// \brief Similar mutation as Dispatch, but creates an account for origin if it does not exist.
class ENJINPLATFORMSDKFUELTANKS_EXPORT DispatchAndTouch : public GraphQlRequest<DispatchAndTouch, TransactionFragment>,
                                                          public HasIdempotencyKey<DispatchAndTouch>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DispatchAndTouch();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DispatchAndTouch(const DispatchAndTouch& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DispatchAndTouch(DispatchAndTouch&& other) noexcept;

    /// \brief Class destructor.
    ~DispatchAndTouch() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    DispatchAndTouch& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    DispatchAndTouch& SetRuleSetId(SerializableStringPtr ruleSetId);

    /// \brief Sets the dispatch call.
    /// \param dispatch The dispatch call.
    /// \return This request for chaining.
    [[maybe_unused]]
    DispatchAndTouch& SetDispatch(DispatchInputTypePtr dispatch);

    /// \brief Sets the flag for paying the remaining fee. May default to false by the platform if not set.
    /// \param paysRemainingFee The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    DispatchAndTouch& SetPaysRemainingFee(SerializableBoolPtr paysRemainingFee);

    DispatchAndTouch& operator=(const DispatchAndTouch& rhs);

    DispatchAndTouch& operator=(DispatchAndTouch&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHANDTOUCH_HPP
