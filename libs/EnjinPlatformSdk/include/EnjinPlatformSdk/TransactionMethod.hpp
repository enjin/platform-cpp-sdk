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

#ifndef ENJINPLATFORMSDK_TRANSACTIONMETHOD_HPP
#define ENJINPLATFORMSDK_TRANSACTIONMETHOD_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Enum values representing the currently supported transactions.
enum class TransactionMethod
{
    /// \brief Indicates the transaction method is ApproveCollection.
    ApproveCollection,

    /// \brief Indicates the transaction method is ApproveToken.
    ApproveToken,

    /// \brief Indicates the transaction method is BatchMint.
    BatchMint,

    /// \brief Indicates the transaction method is BatchSetAttribute.
    BatchSetAttribute,

    /// \brief Indicates the transaction method is BatchTransfer.
    BatchTransfer,

    /// \brief Indicates the transaction method is Burn.
    Burn,

    /// \brief Indicates the transaction method is CreateCollection.
    CreateCollection,

    /// \brief Indicates the transaction method is CreateToken.
    CreateToken,

    /// \brief Indicates the transaction method is DestroyCollection.
    DestroyCollection,

    /// \brief Indicates the transaction method is Freeze.
    Freeze,

    /// \brief Indicates the transaction method is MintToken.
    MintToken,

    /// \brief Indicates the transaction method is MutateCollection.
    MutateCollection,

    /// \brief Indicates the transaction method is MutateToken.
    MutateToken,

    /// \brief Indicates the transaction method is OperatorTransferToken.
    OperatorTransferToken,

    /// \brief Indicates the transaction method is RemoveAllAttributes.
    RemoveAllAttributes,

    /// \brief Indicates the transaction method is RemoveCollectionAttribute.
    RemoveCollectionAttribute,

    /// \brief Indicates the transaction method is RemoveTokenAttribute.
    RemoveTokenAttribute,

    /// \brief Indicates the transaction method is SetCollectionAttribute.
    SetCollectionAttribute,

    /// \brief Indicates the transaction method is SetTokenAttribute.
    SetTokenAttribute,

    /// \brief Indicates the transaction method is SimpleTransferToken.
    SimpleTransferToken,

    /// \brief Indicates the transaction method is Thaw.
    Thaw,

    /// \brief Indicates the transaction method is TransferAllBalance.
    TransferAllBalance,

    /// \brief Indicates the transaction method is TransferBalance.
    TransferBalance,

    /// \brief Indicates the transaction method is UnapproveCollection.
    UnapproveCollection,

    /// \brief Indicates the transaction method is UnapproveToken.
    UnapproveToken,
};

/// \brief Returns the string name of the given enum value.
/// \param value The enum value.
/// \return The string name.
/// \throws std::out_of_range Thrown if the given value is out of range.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
std::string ToString(TransactionMethod value);

/// \brief Tries to get the specified field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
[[maybe_unused]]
ENJINPLATFORMSDK_EXPORT
bool TryGetField(const JsonValue& json, const std::string& key, std::optional<TransactionMethod>& outField);
}

#endif //ENJINPLATFORMSDK_TRANSACTIONMETHOD_HPP
