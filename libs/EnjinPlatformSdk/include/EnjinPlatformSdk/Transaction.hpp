//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ENJINPLATFORMSDK_TRANSACTION_HPP
#define ENJINPLATFORMSDK_TRANSACTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/Event.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/TransactionMethod.hpp"
#include "EnjinPlatformSdk/TransactionResult.hpp"
#include "EnjinPlatformSdk/TransactionState.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
// region Forward declarations

class Event;

class Wallet;

// endregion Forward declarations

/// \brief Models an Efinity transaction.
class ENJINPLATFORMSDK_EXPORT Transaction : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Transaction();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Transaction(const Transaction& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Transaction(Transaction&&) noexcept;

    /// \brief Class destructor.
    ~Transaction() override;

    /// \brief Returns the internal ID of this transaction.
    /// \return The internal ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetId() const;

    /// \brief Returns the on-chain ID of this transaction.
    /// \return The on-chain ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetTransactionId() const;

    /// \brief Returns the on-chain hash of this transaction.
    /// \return The on-chain hash.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetTransactionHash() const;

    /// \brief Returns the on-chain method used.
    /// \return The on-chain method.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TransactionMethod>& GetMethod() const;

    /// \brief Returns the state of this transaction.
    /// \return The transaction state.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TransactionState>& GetState() const;

    /// \brief Returns the result of this transaction.
    /// \return The transaction result.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TransactionResult>& GetResult() const;

    /// \brief Returns the encoded data of this transaction.
    /// \return The encoded data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetEncodedData() const;

    /// \brief Returns the wallet used for signing this transaction.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    /// \brief Returns the idempotency key set for this transaction.
    /// \return The idempotency key.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetIdempotencyKey() const;

    /// \brief Returns the events generated by this transaction.
    /// \return The events.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Connection<Event>>& GetEvents() const;

    Transaction& operator=(const Transaction& rhs);

    Transaction& operator=(Transaction&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_TRANSACTION_HPP
