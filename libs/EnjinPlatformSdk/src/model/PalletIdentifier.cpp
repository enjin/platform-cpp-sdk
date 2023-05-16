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

#include "EnjinPlatformSdk/PalletIdentifier.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<PalletIdentifier>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == "MARKETPLACE")
    {
        outField = PalletIdentifier::Marketplace;
    }
    else if (value == "MULTI_TOKENS")
    {
        outField = PalletIdentifier::MultiTokens;
    }
    else if (value == "FUEL_TANKS")
    {
        outField = PalletIdentifier::FuelTanks;
    }

    return outField.has_value();
}
