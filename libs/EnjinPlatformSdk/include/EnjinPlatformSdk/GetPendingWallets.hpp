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

#ifndef ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP
#define ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of wallet accounts which have yet to be verified.
class ENJINPLATFORMSDK_EXPORT GetPendingWallets : public GraphQlRequest<GetPendingWallets, WalletConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetPendingWallets();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetPendingWallets(const GetPendingWallets& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetPendingWallets(GetPendingWallets&& other) noexcept;

    /// \brief Class destructor.
    ~GetPendingWallets() override;

    GetPendingWallets& operator=(const GetPendingWallets& rhs);

    GetPendingWallets& operator=(GetPendingWallets&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETPENDINGWALLETS_HPP