#ifndef ENJINPLATFORMSDKFUELTANKS_BATCHADDACCOUNT_HPP
#define ENJINPLATFORMSDKFUELTANKS_BATCHADDACCOUNT_HPP

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
/// \brief A request to act as a mutation for adding new accounts to the fuel tank in a batch.
class ENJINPLATFORMSDKFUELTANKS_EXPORT BatchAddAccount : public GraphQlRequest<BatchAddAccount, TransactionFragment>,
                                                         public HasIdempotencyKey<BatchAddAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BatchAddAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BatchAddAccount(const BatchAddAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BatchAddAccount(BatchAddAccount&& other) noexcept;

    /// \brief Class destructor.
    ~BatchAddAccount() override;

    /// \brief Sets the wallet address of the fuel tank.
    /// \param tankId The address.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchAddAccount& SetTankId(SerializableStringPtr tankId);

    /// \brief Sets the wallet accounts that will be added to the fuel tank.
    /// \param userIds The accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchAddAccount& SetUserIds(SerializableStringArrayPtr userIds);

    BatchAddAccount& operator=(const BatchAddAccount& rhs);

    BatchAddAccount& operator=(BatchAddAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_BATCHADDACCOUNT_HPP
