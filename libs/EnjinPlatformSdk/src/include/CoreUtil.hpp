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

#ifndef ENJINPLATFORMSDK_COREUTIL_HPP
#define ENJINPLATFORMSDK_COREUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"

namespace enjin::platform::sdk
{
/// \brief Utility class for core schema handling.
class ENJINPLATFORMSDK_EXPORT CoreUtil final
{
public:
    CoreUtil() = delete;

    /// \brief Creates a platform request from the given GraphQL request.
    /// \param request The GraphQL request.
    /// \return The pointer holding the platform request.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestPtr CreateRequest(const IGraphQlRequest<>& request);
};
}

#endif //ENJINPLATFORMSDK_COREUTIL_HPP
