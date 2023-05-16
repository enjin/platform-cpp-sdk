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

using namespace enjin::platform::sdk;

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

    if (value == "ApproveCollection")
    {
        outField = TransactionMethod::ApproveCollection;
    }
    else if (value == "ApproveToken")
    {
        outField = TransactionMethod::ApproveToken;
    }
    else if (value == "BatchMint")
    {
        outField = TransactionMethod::BatchMint;
    }
    else if (value == "BatchSetAttribute")
    {
        outField = TransactionMethod::BatchSetAttribute;
    }
    else if (value == "BatchTransfer")
    {
        outField = TransactionMethod::BatchTransfer;
    }
    else if (value == "Burn")
    {
        outField = TransactionMethod::Burn;
    }
    else if (value == "CreateCollection")
    {
        outField = TransactionMethod::CreateCollection;
    }
    else if (value == "CreateToken")
    {
        outField = TransactionMethod::CreateToken;
    }
    else if (value == "DestroyCollection")
    {
        outField = TransactionMethod::DestroyCollection;
    }
    else if (value == "Freeze")
    {
        outField = TransactionMethod::Freeze;
    }
    else if (value == "MintToken")
    {
        outField = TransactionMethod::MintToken;
    }
    else if (value == "MutateCollection")
    {
        outField = TransactionMethod::MutateCollection;
    }
    else if (value == "MutateToken")
    {
        outField = TransactionMethod::MutateToken;
    }
    else if (value == "OperatorTransferToken")
    {
        outField = TransactionMethod::OperatorTransferToken;
    }
    else if (value == "RemoveAllAttributes")
    {
        outField = TransactionMethod::RemoveAllAttributes;
    }
    else if (value == "RemoveCollectionAttribute")
    {
        outField = TransactionMethod::RemoveCollectionAttribute;
    }
    else if (value == "RemoveTokenAttribute")
    {
        outField = TransactionMethod::RemoveTokenAttribute;
    }
    else if (value == "SetCollectionAttribute")
    {
        outField = TransactionMethod::SetCollectionAttribute;
    }
    else if (value == "SetTokenAttribute")
    {
        outField = TransactionMethod::SetTokenAttribute;
    }
    else if (value == "SimpleTransferToken")
    {
        outField = TransactionMethod::SimpleTransferToken;
    }
    else if (value == "Thaw")
    {
        outField = TransactionMethod::Thaw;
    }
    else if (value == "TransferAllBalance")
    {
        outField = TransactionMethod::TransferAllBalance;
    }
    else if (value == "TransferBalance")
    {
        outField = TransactionMethod::TransferBalance;
    }
    else if (value == "UnapproveCollection")
    {
        outField = TransactionMethod::UnapproveCollection;
    }
    else if (value == "UnapproveToken")
    {
        outField = TransactionMethod::UnapproveToken;
    }

    return outField.has_value();
}
