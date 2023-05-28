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

#ifndef ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP
#define ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"

namespace enjin::platform::sdk
{
class ENJINPLATFORMSDK_EXPORT GetAccountVerified : public GraphQlRequest<GetAccountVerified>
{
public:
    GetAccountVerified();

    GetAccountVerified(const GetAccountVerified& other);

    GetAccountVerified(GetAccountVerified&& other) noexcept;

    ~GetAccountVerified() override;

    GetAccountVerified& operator=(const GetAccountVerified& rhs);

    GetAccountVerified& operator=(GetAccountVerified&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETACCOUNTVERIFIED_HPP
