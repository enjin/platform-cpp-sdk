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

#ifndef ENJINPLATFORMSDK_CREATETOKENPARAMS_HPP
#define ENJINPLATFORMSDK_CREATETOKENPARAMS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TokenMarketBehaviorInput.hpp"
#include "EnjinPlatformSdk/TokenMintCap.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class CreateTokenParams;

/// \brief Definition for a pointer containing a create token params.
using CreateTokenParamsPtr [[maybe_unused]] = std::shared_ptr<CreateTokenParams>;

/// \brief Models a parameter for the parameters to create a token.
class ENJINPLATFORMSDK_EXPORT CreateTokenParams : public GraphQlParameter<CreateTokenParams>,
                                                  public HasEncodableTokenId<CreateTokenParams>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateTokenParams();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateTokenParams(const CreateTokenParams& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateTokenParams(CreateTokenParams&& other) noexcept;

    /// \brief Class destructor.
    ~CreateTokenParams() override;

    /// \brief Sets the initial supply of tokens to mint to the specified recipient. Must not exceed the token cap if
    /// set.
    /// \param initialSupply The initial supply.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CreateTokenParams& SetInitialSupply(SerializableStringPtr initialSupply);

    /// \brief Sets the price of each token.
    /// \param unitPrice The price per token.
    /// \return This parameter for chaining.
    /// \remarks The price cannot be zero and the product of the unit price and the total supply must be greater than
    /// the token account deposit.
    [[maybe_unused]]
    CreateTokenParams& SetUnitPrice(SerializableStringPtr unitPrice);

    /// \brief Sets the token cap (if required). A cap of 1 will create this token as a single mint type to produce an
    /// NFT.
    /// \param cap The token cap setting.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CreateTokenParams& SetCap(TokenMintCapPtr cap);

    /// \brief Sets the market behavior for the token.
    /// \param behavior The market behavior.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CreateTokenParams& SetBehavior(TokenMarketBehaviorInputPtr behavior);

    /// \brief Sets whether the token can be listed in the marketplace.
    /// \param listingForbidden Whether the token can be listed in the marketplace.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    CreateTokenParams& SetListingForbidden(SerializableBoolPtr listingForbidden);

    CreateTokenParams& operator=(const CreateTokenParams& rhs);

    CreateTokenParams& operator=(CreateTokenParams&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_CREATETOKENPARAMS_HPP
