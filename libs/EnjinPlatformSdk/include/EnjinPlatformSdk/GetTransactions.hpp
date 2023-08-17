#ifndef ENJINPLATFORMSDK_GETTRANSACTIONS_HPP
#define ENJINPLATFORMSDK_GETTRANSACTIONS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdk/TransactionMethod.hpp"
#include "EnjinPlatformSdk/TransactionResult.hpp"
#include "EnjinPlatformSdk/TransactionState.hpp"
#include <vector>

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of transactions optionally filtered by transaction IDs, transaction hashes,
/// methods, states, results, or accounts.
class ENJINPLATFORMSDK_EXPORT GetTransactions : public GraphQlRequest<GetTransactions, TransactionConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetTransactions();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetTransactions(const GetTransactions& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetTransactions(GetTransactions&& other) noexcept;

    /// \brief Class destructor.
    ~GetTransactions() override;

    /// \brief Sets the idempotency keys to filter to.
    /// \param idempotencyKeys The idempotency keys.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetIdempotencyKeys(SerializableStringArrayPtr idempotencyKeys);

    /// \brief Sets the blockchain transaction IDs to filter to.
    /// \param transactionIds The transaction IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetTransactionIds(SerializableStringArrayPtr transactionIds);

    /// \brief Sets the blockchain transaction hashes to filter to.
    /// \param transactionHashes The transaction hashes.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetTransactionHashes(SerializableStringArrayPtr transactionHashes);

    /// \brief Sets the transaction methods to filter to.
    /// \param methods The transaction methods.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetMethods(const std::vector<TransactionMethod>& methods);

    /// \brief Sets the transaction states to filter to.
    /// \param states The transaction states.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetStates(const std::vector<TransactionState>& states);

    /// \brief Sets the transaction results to filter to.
    /// \param results The transaction results.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetResults(const std::vector<TransactionResult>& results);

    /// \brief Sets the wallet accounts to filter to.
    /// \param accounts The wallet accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTransactions& SetAccounts(SerializableStringArrayPtr accounts);

    GetTransactions& operator=(const GetTransactions& rhs);

    GetTransactions& operator=(GetTransactions&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETTRANSACTIONS_HPP
