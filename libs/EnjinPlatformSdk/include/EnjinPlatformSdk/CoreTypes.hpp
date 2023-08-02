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

#ifndef ENJINPLATFORMSDK_CORETYPES_HPP
#define ENJINPLATFORMSDK_CORETYPES_HPP

#include "enjinplatformsdk_export.h"

namespace enjin::platform::sdk
{
/// \brief Contains fields describing variable types used in the platform's Core API.
class ENJINPLATFORMSDK_EXPORT CoreTypes final
{
public:
    // AttributeInput

    /// \brief String for AttributeInput type.
    [[maybe_unused]]
    static constexpr char AttributeInput[] = "AttributeInput!";

    /// \brief String for an array of AttributeInput type.
    [[maybe_unused]]
    static constexpr char AttributeInputArray[] = "[AttributeInput!]!";

    // BigInt

    /// \brief String for BigInt type.
    [[maybe_unused]]
    static constexpr char BigInt[] = "BigInt!";

    /// \brief String for an array of BigInt type.
    [[maybe_unused]]
    static constexpr char BigIntArray[] = "[BigInt!]!";

    // Boolean

    /// \brief String for Boolean type.
    [[maybe_unused]]
    static constexpr char Boolean[] = "Boolean!";

    /// \brief String for an array of Boolean type.
    [[maybe_unused]]
    static constexpr char BooleanArray[] = "[Boolean!]!";

    // BurnParamsInput

    /// \brief String for BurnParamsInput type.
    [[maybe_unused]]
    static constexpr char BurnParamsInput[] = "BurnParamsInput!";

    /// \brief String for an array of BurnParamsInput type.
    [[maybe_unused]]
    static constexpr char BurnParamsInputArray[] = "[BurnParamsInput!]!";

    // CollectionMutationInput

    /// \brief String for CollectionMutationInput type.
    [[maybe_unused]]
    static constexpr char CollectionMutationInput[] = "CollectionMutationInput!";

    /// \brief String for an array of CollectionMutationInput type.
    [[maybe_unused]]
    static constexpr char CollectionMutationInputArray[] = "[CollectionMutationInput!]!";

    // CreateTokenParams

    /// \brief String for CreateTokenParams type.
    [[maybe_unused]]
    static constexpr char CreateTokenParams[] = "CreateTokenParams!";

    /// \brief String for an array of CreateTokenParams type.
    [[maybe_unused]]
    static constexpr char CreateTokenParamsArray[] = "[CreateTokenParams!]!";

    // CryptoSignatureType

    /// \brief String for CryptoSignatureType type.
    [[maybe_unused]]
    static constexpr char CryptoSignatureType[] = "CryptoSignatureType!";

    /// \brief String for an array of CryptoSignatureType type.
    [[maybe_unused]]
    static constexpr char CryptoSignatureTypeArray[] = "[CryptoSignatureType!]!";

    // DateTime

    /// \brief String for DateTime type.
    [[maybe_unused]]
    static constexpr char DateTime[] = "DateTime!";

    /// \brief String for an array of DateTime type.
    [[maybe_unused]]
    static constexpr char DateTimeArray[] = "[DateTime!]!";

    // EncodableTokenIdInput

    /// \brief String for EncodableTokenIdInput type.
    [[maybe_unused]]
    static constexpr char EncodableTokenIdInput[] = "EncodableTokenIdInput!";

    /// \brief String for an array of EncodableTokenIdInput type.
    [[maybe_unused]]
    static constexpr char EncodableTokenIdInputArray[] = "[EncodableTokenIdInput!]!";

    // FreezeType

    /// \brief String for FreezeType type.
    [[maybe_unused]]
    static constexpr char FreezeType[] = "FreezeType!";

    /// \brief String for an array of FreezeType type.
    [[maybe_unused]]
    static constexpr char FreezeTypeArray[] = "[FreezeType!]!";

    // Int

    /// \brief String for Int type.
    [[maybe_unused]]
    static constexpr char Int[] = "Int!";

    /// \brief String for an array of Int type.
    [[maybe_unused]]
    static constexpr char IntArray[] = "[Int!]!";

    // IntegerRangeString

    /// \brief String for IntegerRangeString type.
    [[maybe_unused]]
    static constexpr char IntegerRangeString[] = "IntegerRangeString!";

    /// \brief String for an array of IntegerRangeString type.
    [[maybe_unused]]
    static constexpr char IntegerRangeStringArray[] = "[IntegerRangeString!]!";

    // MarketPolicy

    /// \brief String for MarketPolicy type.
    [[maybe_unused]]
    static constexpr char MarketPolicy[] = "MarketPolicy!";

    /// \brief String for an array of MarketPolicy type.
    [[maybe_unused]]
    static constexpr char MarketPolicyArray[] = "[MarketPolicy!]!";

    // MintPolicy

    /// \brief String for MintPolicy type.
    [[maybe_unused]]
    static constexpr char MintPolicy[] = "MintPolicy!";

    /// \brief String for an array of MintPolicy type.
    [[maybe_unused]]
    static constexpr char MintPolicyArray[] = "[MintPolicy!]!";

    // MintRecipient

    /// \brief String for MintRecipient type.
    [[maybe_unused]]
    static constexpr char MintRecipient[] = "MintRecipient!";

    /// \brief String for an array of MintRecipient type.
    [[maybe_unused]]
    static constexpr char MintRecipientArray[] = "[MintRecipient!]!";

    // MintTokenParams

    /// \brief String for MintTokenParams type.
    [[maybe_unused]]
    static constexpr char MintTokenParams[] = "MintTokenParams!";

    /// \brief String for an array of MintTokenParams type.
    [[maybe_unused]]
    static constexpr char MintTokenParamsArray[] = "[MintTokenParams!]!";

    // MultiTokenIdInput

    /// \brief String for MultiTokenIdInput type.
    [[maybe_unused]]
    static constexpr char MultiTokenIdInput[] = "MultiTokenIdInput!";

    /// \brief String for an array of MultiTokenIdInput type.
    [[maybe_unused]]
    static constexpr char MultiTokenIdInputArray[] = "[MultiTokenIdInput!]!";

    // OperatorTransferParams

    /// \brief String for OperatorTransferParams type.
    [[maybe_unused]]
    static constexpr char OperatorTransferParams[] = "OperatorTransferParams!";

    /// \brief String for an array of OperatorTransferParams type.
    [[maybe_unused]]
    static constexpr char OperatorTransferParamsArray[] = "[OperatorTransferParams!]!";

    // SimpleTransferParams

    /// \brief String for SimpleTransferParams type.
    [[maybe_unused]]
    static constexpr char SimpleTransferParams[] = "SimpleTransferParams!";

    /// \brief String for an array of SimpleTransferParams type.
    [[maybe_unused]]
    static constexpr char SimpleTransferParamsArray[] = "[SimpleTransferParams!]!";

    // String

    /// \brief String for String type.
    [[maybe_unused]]
    static constexpr char String[] = "String!";

    /// \brief String for an array of String type.
    [[maybe_unused]]
    static constexpr char StringArray[] = "[String!]!";

    // TokenMutationInput

    /// \brief String for TokenMutationInput type.
    [[maybe_unused]]
    static constexpr char TokenMutationInput[] = "TokenMutationInput!";

    /// \brief String for an array of TokenMutationInput type.
    [[maybe_unused]]
    static constexpr char TokenMutationInputArray[] = "[TokenMutationInput!]!";

    // TransactionMethod

    /// \brief String for TransactionMethod type.
    [[maybe_unused]]
    static constexpr char TransactionMethod[] = "TransactionMethod!";

    /// \brief String for an array of TransactionMethod type.
    [[maybe_unused]]
    static constexpr char TransactionMethodArray[] = "[TransactionMethod!]!";

    // TransactionResult

    /// \brief String for TransactionResult type.
    [[maybe_unused]]
    static constexpr char TransactionResult[] = "TransactionResult!";

    /// \brief String for an array of TransactionResult type.
    [[maybe_unused]]
    static constexpr char TransactionResultArray[] = "[TransactionResult!]!";

    // TransactionState

    /// \brief String for TransactionState type.
    [[maybe_unused]]
    static constexpr char TransactionState[] = "TransactionState!";

    /// \brief String for an array of TransactionState type.
    [[maybe_unused]]
    static constexpr char TransactionStateArray[] = "[TransactionState!]!";

    // TransferRecipient

    /// \brief String for TransferRecipient type.
    [[maybe_unused]]
    static constexpr char TransferRecipient[] = "TransferRecipient!";

    /// \brief String for an array of TransferRecipient type.
    [[maybe_unused]]
    static constexpr char TransferRecipientArray[] = "[TransferRecipient!]!";

    CoreTypes() = delete;
};
}

#endif //ENJINPLATFORMSDK_CORETYPES_HPP
