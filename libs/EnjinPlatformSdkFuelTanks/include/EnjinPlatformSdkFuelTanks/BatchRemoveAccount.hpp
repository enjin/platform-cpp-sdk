#ifndef ENJINPLATFORMSDKFUELTANKS_BATCHREMOVEACCOUNT_HPP
#define ENJINPLATFORMSDKFUELTANKS_BATCHREMOVEACCOUNT_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
/// \brief A request to act as a mutation for removing accounts from the fuel tank in a batch.
class ENJINPLATFORMSDKFUELTANKS_EXPORT BatchRemoveAccount
    : public GraphQlRequest<BatchRemoveAccount, TransactionFragment>,
      public HasIdempotencyKey<BatchRemoveAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BatchRemoveAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BatchRemoveAccount(const BatchRemoveAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BatchRemoveAccount(BatchRemoveAccount&& other) noexcept;

    /// \brief Class destructor.
    ~BatchRemoveAccount() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchRemoveAccount& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the wallet accounts that will be removed from the fuel tank.
    /// \param userIds The accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchRemoveAccount& SetUserIds(SerializableStringArrayPtr userIds);

    BatchRemoveAccount& operator=(const BatchRemoveAccount& rhs);

    BatchRemoveAccount& operator=(BatchRemoveAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_BATCHREMOVEACCOUNT_HPP
