#ifndef ENJINPLATFORMSDKFUELTANKS_CREATEFUELTANK_HPP
#define ENJINPLATFORMSDKFUELTANKS_CREATEFUELTANK_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkFuelTanks/AccountRuleInputType.hpp"
#include "EnjinPlatformSdkFuelTanks/DispatchInputType.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for creating a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT CreateFuelTank : public GraphQlRequest<CreateFuelTank, TransactionFragment>,
                                                        public HasIdempotencyKey<CreateFuelTank>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateFuelTank();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateFuelTank(const CreateFuelTank& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateFuelTank(CreateFuelTank&& other) noexcept;

    /// \brief Class destructor.
    ~CreateFuelTank() override;

    /// \brief Sets the fuel tank name.
    /// \param name The name.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetName(SerializableStringPtr name);

    /// \brief Sets the flag for existential deposit.
    /// \param reservesExistentialDeposit The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetReservesExistentialDeposit(SerializableBoolPtr reservesExistentialDeposit);

    /// \brief Sets the flag for account creation deposit.
    /// \param reservesAccountCreationDeposit The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetReservesAccountCreationDeposit(SerializableBoolPtr reservesAccountCreationDeposit);

    /// \brief Sets the flag for deposit.
    /// \param providesDeposit The flag.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetProvidesDeposit(SerializableBoolPtr providesDeposit);

    /// \brief Sets the fuel tank account rules.
    /// \param accountRules The account rules.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetAccountRules(AccountRuleInputTypePtr accountRules);

    /// \brief Sets the fuel tank dispatch rules.
    /// \param dispatchRules The dispatch rules.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateFuelTank& SetDispatchRules(std::shared_ptr<SerializableArray<DispatchInputType>> dispatchRules);

    CreateFuelTank& operator=(const CreateFuelTank& rhs);

    CreateFuelTank& operator=(CreateFuelTank&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_CREATEFUELTANK_HPP
