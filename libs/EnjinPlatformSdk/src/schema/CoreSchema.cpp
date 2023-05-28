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

#include "EnjinPlatformSdk/CoreSchema.hpp"

#include "EnjinPlatformSdk/PlatformRequest.hpp"

using namespace enjin::platform::sdk;

PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request)
{
    return PlatformRequest::Builder()
        .SetPath("/graphql")
        .AddOperation(request.Compile(), request.GetVariablesWithoutTypes())
        .Build();
}

// region Queries

[[maybe_unused]]
[[nodiscard]]
std::future<PlatformResponsePtr<GraphQlResponse<AccountVerified>>> enjin::platform::sdk::SendGetAccountVerified(
    PlatformClient& client,
    const GetAccountVerified& request)
{
    return client.SendRequest<GraphQlResponse<AccountVerified>>(CreateRequest(request));
}

// endregion Queries

// region Mutations

// endregion Mutations
