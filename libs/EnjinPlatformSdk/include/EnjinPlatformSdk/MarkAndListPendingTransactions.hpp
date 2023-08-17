#ifndef ENJINPLATFORMSDK_MARKANDLISTPENDINGTRANSACTIONS_HPP
#define ENJINPLATFORMSDK_MARKANDLISTPENDINGTRANSACTIONS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A requesting to act as a mutation for getting a list of new pending transactions and marking them as
/// processing.
class ENJINPLATFORMSDK_EXPORT MarkAndListPendingTransactions
    : public GraphQlRequest<MarkAndListPendingTransactions, TransactionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarkAndListPendingTransactions();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarkAndListPendingTransactions(const MarkAndListPendingTransactions& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarkAndListPendingTransactions(MarkAndListPendingTransactions&& other) noexcept;

    /// \brief Class destructor.
    ~MarkAndListPendingTransactions() override;

    /// \brief Sets the accounts to filter the transactions.
    /// \param accounts The accounts to filter.
    /// \return This request for chaining.
    [[maybe_unused]]
    MarkAndListPendingTransactions& SetAccounts(SerializableStringArrayPtr accounts);

    /// \brief Sets whether the transactions are to be marked as processing. Defaults to true if not specified.
    /// \param markAsProcessing Whether the transactions are to be marked as processing.
    /// \return This request for chaining.
    [[maybe_unused]]
    MarkAndListPendingTransactions& SetMarkAsProcessing(SerializableBoolPtr markAsProcessing);

    MarkAndListPendingTransactions& operator=(const MarkAndListPendingTransactions& rhs);

    MarkAndListPendingTransactions& operator=(MarkAndListPendingTransactions&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MARKANDLISTPENDINGTRANSACTIONS_HPP
