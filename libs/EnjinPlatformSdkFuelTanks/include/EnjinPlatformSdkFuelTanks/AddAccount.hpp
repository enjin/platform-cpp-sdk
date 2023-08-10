#ifndef ENJINPLATFORMSDKFUELTANKS_ADDACCOUNT_HPP
#define ENJINPLATFORMSDKFUELTANKS_ADDACCOUNT_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for adding a new account to the fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT AddAccount : public GraphQlRequest<AddAccount, TransactionFragment>,
                                                    public HasIdempotencyKey<AddAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AddAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AddAccount(const AddAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AddAccount(AddAccount&& other) noexcept;

    /// \brief Class destructor.
    ~AddAccount() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    AddAccount& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the wallet account to be added to the fuel tank.
    /// \param userId The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    AddAccount& SetUserId(SerializableStringPtr userId);

    AddAccount& operator=(const AddAccount& rhs);

    AddAccount& operator=(AddAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_ADDACCOUNT_HPP
