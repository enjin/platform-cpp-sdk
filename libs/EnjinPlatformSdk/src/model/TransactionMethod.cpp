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

#include "EnjinPlatformSdk/TransactionMethod.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char ApproveCollection[] = "ApproveCollection";
constexpr char ApproveToken[] = "ApproveToken";
constexpr char BatchMint[] = "BatchMint";
constexpr char BatchSetAttribute[] = "BatchSetAttribute";
constexpr char BatchTransfer[] = "BatchTransfer";
constexpr char Burn[] = "Burn";
constexpr char CreateCollection[] = "CreateCollection";
constexpr char CreateToken[] = "CreateToken";
constexpr char DestroyCollection[] = "DestroyCollection";
constexpr char Freeze[] = "Freeze";
constexpr char MintToken[] = "MintToken";
constexpr char MutateCollection[] = "MutateCollection";
constexpr char MutateToken[] = "MutateToken";
constexpr char OperatorTransferToken[] = "OperatorTransferToken";
constexpr char RemoveAllAttributes[] = "RemoveAllAttributes";
constexpr char RemoveCollectionAttribute[] = "RemoveCollectionAttribute";
constexpr char RemoveTokenAttribute[] = "RemoveTokenAttribute";
constexpr char SetCollectionAttribute[] = "SetCollectionAttribute";
constexpr char SetTokenAttribute[] = "SetTokenAttribute";
constexpr char SimpleTransferToken[] = "SimpleTransferToken";
constexpr char Thaw[] = "Thaw";
constexpr char TransferAllBalance[] = "TransferAllBalance";
constexpr char TransferBalance[] = "TransferBalance";
constexpr char UnapproveCollection[] = "UnapproveCollection";
constexpr char UnapproveToken[] = "UnapproveToken";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TransactionMethod value)
{
    switch (value)
    {
        case TransactionMethod::ApproveCollection:
            return ApproveCollection;

        case TransactionMethod::ApproveToken:
            return ApproveToken;

        case TransactionMethod::BatchMint:
            return BatchMint;

        case TransactionMethod::BatchSetAttribute:
            return BatchSetAttribute;

        case TransactionMethod::BatchTransfer:
            return BatchTransfer;

        case TransactionMethod::Burn:
            return Burn;

        case TransactionMethod::CreateCollection:
            return CreateCollection;

        case TransactionMethod::CreateToken:
            return CreateToken;

        case TransactionMethod::DestroyCollection:
            return DestroyCollection;

        case TransactionMethod::Freeze:
            return Freeze;

        case TransactionMethod::MintToken:
            return MintToken;

        case TransactionMethod::MutateCollection:
            return MutateCollection;

        case TransactionMethod::MutateToken:
            return MutateToken;

        case TransactionMethod::OperatorTransferToken:
            return OperatorTransferToken;

        case TransactionMethod::RemoveAllAttributes:
            return RemoveAllAttributes;

        case TransactionMethod::RemoveCollectionAttribute:
            return RemoveCollectionAttribute;

        case TransactionMethod::RemoveTokenAttribute:
            return RemoveTokenAttribute;

        case TransactionMethod::SetCollectionAttribute:
            return SetCollectionAttribute;

        case TransactionMethod::SetTokenAttribute:
            return SetTokenAttribute;

        case TransactionMethod::SimpleTransferToken:
            return SimpleTransferToken;

        case TransactionMethod::Thaw:
            return Thaw;

        case TransactionMethod::TransferAllBalance:
            return TransferAllBalance;

        case TransactionMethod::TransferBalance:
            return TransferBalance;

        case TransactionMethod::UnapproveCollection:
            return UnapproveCollection;

        case TransactionMethod::UnapproveToken:
            return UnapproveToken;

        default:
            throw std::out_of_range("Value out of range for TransactionMethod enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TransactionMethod>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == ApproveCollection)
    {
        outField = TransactionMethod::ApproveCollection;
    }
    else if (value == ApproveToken)
    {
        outField = TransactionMethod::ApproveToken;
    }
    else if (value == BatchMint)
    {
        outField = TransactionMethod::BatchMint;
    }
    else if (value == BatchSetAttribute)
    {
        outField = TransactionMethod::BatchSetAttribute;
    }
    else if (value == BatchTransfer)
    {
        outField = TransactionMethod::BatchTransfer;
    }
    else if (value == Burn)
    {
        outField = TransactionMethod::Burn;
    }
    else if (value == CreateCollection)
    {
        outField = TransactionMethod::CreateCollection;
    }
    else if (value == CreateToken)
    {
        outField = TransactionMethod::CreateToken;
    }
    else if (value == DestroyCollection)
    {
        outField = TransactionMethod::DestroyCollection;
    }
    else if (value == Freeze)
    {
        outField = TransactionMethod::Freeze;
    }
    else if (value == MintToken)
    {
        outField = TransactionMethod::MintToken;
    }
    else if (value == MutateCollection)
    {
        outField = TransactionMethod::MutateCollection;
    }
    else if (value == MutateToken)
    {
        outField = TransactionMethod::MutateToken;
    }
    else if (value == OperatorTransferToken)
    {
        outField = TransactionMethod::OperatorTransferToken;
    }
    else if (value == RemoveAllAttributes)
    {
        outField = TransactionMethod::RemoveAllAttributes;
    }
    else if (value == RemoveCollectionAttribute)
    {
        outField = TransactionMethod::RemoveCollectionAttribute;
    }
    else if (value == RemoveTokenAttribute)
    {
        outField = TransactionMethod::RemoveTokenAttribute;
    }
    else if (value == SetCollectionAttribute)
    {
        outField = TransactionMethod::SetCollectionAttribute;
    }
    else if (value == SetTokenAttribute)
    {
        outField = TransactionMethod::SetTokenAttribute;
    }
    else if (value == SimpleTransferToken)
    {
        outField = TransactionMethod::SimpleTransferToken;
    }
    else if (value == Thaw)
    {
        outField = TransactionMethod::Thaw;
    }
    else if (value == TransferAllBalance)
    {
        outField = TransactionMethod::TransferAllBalance;
    }
    else if (value == TransferBalance)
    {
        outField = TransactionMethod::TransferBalance;
    }
    else if (value == UnapproveCollection)
    {
        outField = TransactionMethod::UnapproveCollection;
    }
    else if (value == UnapproveToken)
    {
        outField = TransactionMethod::UnapproveToken;
    }

    return outField.has_value();
}
