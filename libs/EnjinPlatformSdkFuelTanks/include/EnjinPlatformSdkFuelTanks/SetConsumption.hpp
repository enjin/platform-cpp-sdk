#ifndef ENJINPLATFORMSDKFUELTANKS_SETCONSUMPTION_HPP
#define ENJINPLATFORMSDKFUELTANKS_SETCONSUMPTION_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation to force set the consumption of a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT SetConsumption : public GraphQlRequest<SetConsumption, TransactionFragment>,
                                                        public HasIdempotencyKey<SetConsumption>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SetConsumption();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SetConsumption(const SetConsumption& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SetConsumption(SetConsumption&& other) noexcept;

    /// \brief Class destructor.
    ~SetConsumption() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetConsumption& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetIf The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetConsumption& SetRuleSetId(SerializableStringPtr ruleSetIf);

    /// \brief Sets the wallet account to be added to the fuel tank.
    /// \param userId The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetConsumption& SetUserId(SerializableStringPtr userId);

    /// \brief Sets the total consumption.
    /// \param totalConsumed The total consumption.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetConsumption& SetTotalConsumed(SerializableStringPtr totalConsumed);

    /// \brief Sets the last reset block.
    /// \param lastResetBlock The last reset block.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetConsumption& SetLastResetBlock(SerializableIntPtr lastResetBlock);

    SetConsumption& operator=(const SetConsumption& rhs);

    SetConsumption& operator=(SetConsumption&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_SETCONSUMPTION_HPP
