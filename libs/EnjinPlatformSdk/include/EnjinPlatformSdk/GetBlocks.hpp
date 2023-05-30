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

#ifndef ENJINPLATFORMSDK_GETBLOCKS_HPP
#define ENJINPLATFORMSDK_GETBLOCKS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/BlockFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of blocks optionally filtered by blockchain transaction IDs or blockchain
/// transaction hashes.
class ENJINPLATFORMSDK_EXPORT GetBlocks : public GraphQlRequest<GetBlocks, BlockConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBlocks();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBlocks(const GetBlocks& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBlocks(GetBlocks&& other) noexcept;

    /// \brief Class destructor.
    ~GetBlocks() override;

    /// \brief Sets the blockchain transaction IDs to filter to.
    /// \param numbers The transaction IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBlocks& SetNumber(SerializableStringArrayPtr numbers);

    /// \brief Sets the blockchain transaction hashes to filter to.
    /// \param hashes The transaction hashes.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBlocks& SetHashes(SerializableStringArrayPtr hashes);

    GetBlocks& operator=(const GetBlocks& rhs);

    GetBlocks& operator=(GetBlocks&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETBLOCKS_HPP
