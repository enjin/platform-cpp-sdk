#ifndef ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNTRULEDATA_HPP
#define ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNTRULEDATA_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchRuleEnum.hpp"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for removing account rule from a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT RemoveAccountRuleData
    : public GraphQlRequest<RemoveAccountRuleData, TransactionFragment>,
      public HasIdempotencyKey<RemoveAccountRuleData>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveAccountRuleData();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveAccountRuleData(const RemoveAccountRuleData& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveAccountRuleData(RemoveAccountRuleData&& other) noexcept;

    /// \brief Class destructor.
    [[maybe_unused]]
    ~RemoveAccountRuleData() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccountRuleData& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the wallet account.
    /// \param userId The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccountRuleData& SetUserId(SerializableStringPtr userId);

    /// \brief Sets the rule set ID.
    /// \param ruleSetId The ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccountRuleData& SetRuleSetId(SerializableStringPtr ruleSetId);

    /// \brief Sets the dispatch rule options.
    /// \param rule The rule options.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccountRuleData& SetRule(DispatchRuleEnum rule);

    RemoveAccountRuleData& operator=(const RemoveAccountRuleData& rhs);

    RemoveAccountRuleData& operator=(RemoveAccountRuleData&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNTRULEDATA_HPP
