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

#include "EnjinPlatformSdk/TransactionResult.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char ExtrinsicSuccess[] = "EXTRINSIC_SUCCESS";
constexpr char ExtrinsicFailed[] = "EXTRINSIC_FAILED";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TransactionResult value)
{
    switch (value)
    {
        case TransactionResult::ExtrinsicSuccess:
            return ExtrinsicSuccess;

        case TransactionResult::ExtrinsicFailed:
            return ExtrinsicFailed;

        default:
            throw std::out_of_range("Value out of range for TransactionResult enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TransactionResult>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == "EXTRINSIC_SUCCESS")
    {
        outField = TransactionResult::ExtrinsicSuccess;
    }
    else if (value == "EXTRINSIC_FAILED")
    {
        outField = TransactionResult::ExtrinsicFailed;
    }

    return outField.has_value();
}