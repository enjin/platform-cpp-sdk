#ifndef ENJINPLATFORMSDKFUELTANKS_AccountRuleInputTypeINPUTTYPE_HPP
#define ENJINPLATFORMSDKFUELTANKS_AccountRuleInputTypeINPUTTYPE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class AccountRuleInputType;

/// \brief Definition for a pointer containing a AccountRuleInputType.
using AccountRuleInputTypePtr [[maybe_unused]] = std::shared_ptr<AccountRuleInputType>;

/// \brief Models a parameter for account rules of a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT AccountRuleInputType : public GraphQlParameter<AccountRuleInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountRuleInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountRuleInputType(const AccountRuleInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountRuleInputType(AccountRuleInputType&& other) noexcept;

    /// \brief Class destructor.
    ~AccountRuleInputType() override;

    /// \brief Sets the wallet accounts that are allowed to use the fuel tank.
    /// \param whitelistedCallers The allowed accounts.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AccountRuleInputType& SetWhitelistedCallers(SerializableStringArrayPtr whitelistedCallers);

    /// \brief Sets the specific token the wallet account(s) must have to use the fuel tank.
    /// \param requireToken The required token.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AccountRuleInputType& SetRequireToken(MultiTokenIdInputPtr requireToken);

    AccountRuleInputType& operator=(const AccountRuleInputType& rhs);

    AccountRuleInputType& operator=(AccountRuleInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_AccountRuleInputTypeINPUTTYPE_HPP
