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

#ifndef ENJINPLATFORMSDK_BLOCK_HPP
#define ENJINPLATFORMSDK_BLOCK_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a blockchain block.
class ENJINPLATFORMSDK_EXPORT Block : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Block();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Block(const Block& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Block(Block&& other) noexcept;

    /// \brief Class destructor.
    ~Block() override;

    /// \brief Returns the internal ID of this block.
    /// \return The internal ID of this block.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetId() const;

    /// \brief Returns the on-chain block number.
    /// \return The on-chain block number.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetNumber() const;

    /// \brief Returns the on-chain block hash.
    /// \return The on-chain block hash.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetHash() const;

    /// \brief Returns whether this block was already synced.
    /// \return Whether this block was already synced.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetSynced() const;

    /// \brief Returns whether this block failed to be processed.
    /// \return Whether this block failed to be processed.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetFailed() const;

    /// \brief Returns the exception that happened when processing this block, if one exists.
    /// \return The exception.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetException() const;

    Block& operator=(const Block& rhs);

    Block& operator=(Block&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_BLOCK_HPP
