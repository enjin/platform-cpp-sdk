#ifndef ENJINPLATFORMSDK_TRANSFERBALANCE_HPP
#define ENJINPLATFORMSDK_TRANSFERBALANCE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation to transfer a balance from one account to another.
/// \remarks The parameter set through the <see cref="SetKeepAlive"/> method may be passed to check if the account will
/// be left with at least the existential deposit.
class ENJINPLATFORMSDK_EXPORT TransferBalance : public GraphQlRequest<TransferBalance, TransactionFragment>,
                                                public HasIdempotencyKey<TransferBalance>,
                                                public HasSkipValidation<TransferBalance>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TransferBalance();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TransferBalance(const TransferBalance& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TransferBalance(TransferBalance&& other) noexcept;

    /// \brief Class destructor.
    ~TransferBalance() override;

    /// \brief Sets the recipient account that will receive the transfer.
    /// \param recipient The recipient account.
    /// \return This request for chaining.
    [[maybe_unused]]
    TransferBalance& SetRecipient(SerializableStringPtr recipient);

    /// \brief Sets the amount to transfer.
    /// \param amount The amount.
    /// \return This request for chaining.
    [[maybe_unused]]
    TransferBalance& SetAmount(SerializableStringPtr amount);

    /// \brief Sets whether the transaction will be kept from failing if the balance drops below the minimum requirement.
    /// \param keepAlive Whether the transaction will be kept from failing.
    /// \return This request for chaining.
    /// \remarks The parameter defaults to false if not set.
    [[maybe_unused]]
    TransferBalance& SetKeepAlive(SerializableBoolPtr keepAlive);

    /// \brief Sets the signing wallet for the transaction.
    /// \param signingAccount The signing wallet account.
    /// \return This request for chaining.
    /// \remarks The account defaults to wallet daemon if not specified.
    [[maybe_unused]]
    TransferBalance& SetSigningAccount(SerializableStringPtr signingAccount);

    TransferBalance& operator=(const TransferBalance& rhs);

    TransferBalance& operator=(TransferBalance&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TRANSFERBALANCE_HPP
