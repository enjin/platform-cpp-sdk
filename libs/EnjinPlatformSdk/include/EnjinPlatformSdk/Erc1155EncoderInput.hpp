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

#ifndef ENJINPLATFORMSDK_ERC1155ENCODERINPUT_HPP
#define ENJINPLATFORMSDK_ERC1155ENCODERINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class Erc1155EncoderInput;

/// \brief Definition for a pointer containing a ERC1155 encoder input.
using Erc1155EncoderInputPtr [[maybe_unused]] = std::shared_ptr<Erc1155EncoderInput>;

/// \brief Models a parameter for a ERC1155 style token ID.
class ENJINPLATFORMSDK_EXPORT Erc1155EncoderInput : public GraphQlParameter<Erc1155EncoderInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Erc1155EncoderInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Erc1155EncoderInput(const Erc1155EncoderInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Erc1155EncoderInput(Erc1155EncoderInput&& other) noexcept;

    /// \brief Class destructor.
    ~Erc1155EncoderInput() override;

    /// \brief Sets the 16 character hex formatted ERC1155 style token ID.
    /// \param tokenId The token ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    Erc1155EncoderInput& SetTokenId(SerializableStringPtr tokenId);

    /// \brief Sets the 64-bit integer index.
    /// \param index The index.
    /// \return This parameter for chaining.
    /// \remarks This will be converted to hex and concatenated with the token ID to make the final unique NFT ID.
    /// Defaults to 0 if not supplied.
    [[maybe_unused]]
    Erc1155EncoderInput& SetIndex(SerializableStringPtr index);

    Erc1155EncoderInput& operator=(const Erc1155EncoderInput& rhs);

    Erc1155EncoderInput& operator=(Erc1155EncoderInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_ERC1155ENCODERINPUT_HPP
