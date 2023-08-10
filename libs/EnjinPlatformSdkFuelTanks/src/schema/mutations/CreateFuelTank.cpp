#include "EnjinPlatformSdkFuelTanks/CreateFuelTank.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkFuelTanks/FuelTanksTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::fuelTanks;
using RequestType = GraphQlRequest<CreateFuelTank, TransactionFragment>;

[[maybe_unused]]
CreateFuelTank::CreateFuelTank()
    : RequestType("CreateFuelTank", GraphQlRequestType::Mutation),
      HasIdempotencyKey<CreateFuelTank>()
{
}

[[maybe_unused]]
CreateFuelTank::CreateFuelTank(const CreateFuelTank& other) = default;

[[maybe_unused]]
CreateFuelTank::CreateFuelTank(CreateFuelTank&& other) noexcept = default;

CreateFuelTank::~CreateFuelTank() = default;

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetName(SerializableStringPtr name)
{
    return RequestType::SetVariable("name", CoreTypes::String, std::move(name));
}

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetReservesExistentialDeposit(SerializableBoolPtr reservesExistentialDeposit)
{
    return RequestType::SetVariable("reservesExistentialDeposit",
                                    CoreTypes::Boolean,
                                    std::move(reservesExistentialDeposit));
}

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetReservesAccountCreationDeposit(SerializableBoolPtr reservesAccountCreationDeposit)
{
    return RequestType::SetVariable("reservesAccountCreationDeposit",
                                    CoreTypes::Boolean,
                                    std::move(reservesAccountCreationDeposit));
}

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetProvidesDeposit(SerializableBoolPtr providesDeposit)
{
    return RequestType::SetVariable("providesDeposit", CoreTypes::Boolean, std::move(providesDeposit));
}

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetAccountRules(AccountRuleInputTypePtr accountRules)
{
    return RequestType::SetVariable("accountRules", FuelTanksTypes::AccountRuleInputType, std::move(accountRules));
}

[[maybe_unused]]
CreateFuelTank& CreateFuelTank::SetDispatchRules(std::shared_ptr<SerializableArray<DispatchInputType>> dispatchRules)
{
    return RequestType::SetVariable("dispatchRules",
                                    FuelTanksTypes::DispatchRuleInputTypeArray,
                                    std::move(dispatchRules));
}

CreateFuelTank& CreateFuelTank::operator=(const CreateFuelTank& rhs) = default;

CreateFuelTank& CreateFuelTank::operator=(CreateFuelTank&& rhs) noexcept = default;
