#ifndef ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNT_HPP
#define ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNT_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for removing an account from a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT RemoveAccount : public GraphQlRequest<RemoveAccount, TransactionFragment>,
                                                       public HasIdempotencyKey<RemoveAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveAccount(const RemoveAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveAccount(RemoveAccount&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveAccount() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccount& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the wallet account that will be removed from the fuel tank.
    /// \param userId The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAccount& SetUserId(SerializableStringPtr userId);

    RemoveAccount& operator=(const RemoveAccount& rhs);

    RemoveAccount& operator=(RemoveAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_REMOVEACCOUNT_HPP
