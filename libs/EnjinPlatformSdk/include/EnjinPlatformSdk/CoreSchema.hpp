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

#ifndef ENJINPLATFORMSDK_CORESCHEMA_HPP
#define ENJINPLATFORMSDK_CORESCHEMA_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountVerified.hpp"
#include "EnjinPlatformSdk/GetAccountVerified.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include <future>

namespace enjin::platform::sdk
{
// region Queries

/// \brief TODO
/// \param client
/// \param request
/// \return
[[maybe_unused]]
[[nodiscard]]
ENJINPLATFORMSDK_EXPORT
std::future<PlatformResponsePtr<GraphQlResponse<AccountVerified>>> SendGetAccountVerified(
    PlatformClient& client,
    const GetAccountVerified& request);

// endregion Queries

// region Mutations

// endregion Mutations
}

#endif //ENJINPLATFORMSDK_CORESCHEMA_HPP
