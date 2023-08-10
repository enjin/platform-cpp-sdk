#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANK_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANK_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/Account.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdkFuelTanks/AccountRule.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchRule.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk::fuelTanks
{
// region Forward declarations

class AccountRule;

class DispatchRule;

// endregion Forward declarations

/// \brief Models a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTank : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FuelTank();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FuelTank(const FuelTank& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FuelTank(FuelTank&& other) noexcept;

    /// \brief Class destructor.
    ~FuelTank() override;

    /// \brief Returns the account of this fuel tank.
    /// \return The account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Account>& GetTankId() const;

    /// \brief Returns the name of this fuel tank.
    /// \return The name.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetName() const;

    /// \brief Returns the flag for existential deposit.
    /// \return The flag.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetReserveExistentialDeposit() const;

    /// \brief Returns the flag for account creation deposit.
    /// \return The flag.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetReserveAccountCreationDeposit() const;

    /// \brief Returns the flag for deposit.
    /// \return The flag.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetProvidesDeposit() const;

    /// \brief Returns the flag for frozen state.
    /// \return The flag.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const;

    /// \brief Returns the number of accounts.
    /// \return The number of accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetAccountCount() const;

    /// \brief Returns the wallet account for this fuel tank.
    /// \return The wallet account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetOwner() const;

    /// \brief Returns the accounts for this fuel tank.
    /// \return The accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<Wallet>>& GetAccounts() const;

    /// \brief Returns the account rules for this fuel tank.
    /// \return The rules.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<AccountRule>>& GetAccountRules() const;

    /// \brief Returns the dispatch rules for this fuel tank.
    /// \return The rules.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<DispatchRule>>& GetDispatchRules() const;

    FuelTank& operator=(const FuelTank& rhs);

    FuelTank& operator=(FuelTank&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANK_HPP
