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

#ifndef ENJINPLATFORMSDK_ENCODABLETOKENIDINPUT_HPP
#define ENJINPLATFORMSDK_ENCODABLETOKENIDINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Erc1155EncoderInput.hpp"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableJsonValue.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class EncodableTokenIdInput;

/// \brief Definition for a pointer containing an encodable token ID input.
using EncodableTokenIdInputPtr [[maybe_unused]] = std::shared_ptr<EncodableTokenIdInput>;

/// \brief Models a parameter for setting parameters to encode a token ID.
class ENJINPLATFORMSDK_EXPORT EncodableTokenIdInput : public GraphQlParameter<EncodableTokenIdInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    EncodableTokenIdInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EncodableTokenIdInput(const EncodableTokenIdInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EncodableTokenIdInput(EncodableTokenIdInput&& other) noexcept;

    /// \brief Class destructor.
    ~EncodableTokenIdInput() override;

    /// \brief Sets an ERC1155 style token input to be used to create an integer representation.
    /// \param erc1155 The ERC1155 style input.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    EncodableTokenIdInput& SetErc1155(Erc1155EncoderInputPtr erc1155);

    /// \brief Sets an arbitrary object to be hashed into an integer.
    /// \param hash The object to hash.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    EncodableTokenIdInput& SetHash(SerializableJsonValuePtr hash);

    /// \brief Sets a 128-bit unsigned integer (the native format for Efinity).
    /// \param integer The integer.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    EncodableTokenIdInput& SetInteger(SerializableStringPtr integer);

    /// \brief Sets the string to be converted into the ID.
    /// \param stringId The string to convert.
    /// \return This parameter for chaining.
    /// \remarks Converts the string into a hex value, then converts the hex value into an integer. This encoding is
    /// reversible.
    [[maybe_unused]]
    EncodableTokenIdInput& SetStringId(SerializableStringPtr stringId);

    EncodableTokenIdInput& operator=(const EncodableTokenIdInput& rhs);

    EncodableTokenIdInput& operator=(EncodableTokenIdInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_ENCODABLETOKENIDINPUT_HPP
