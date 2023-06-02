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

#ifndef ENJINPLATFORMSDK_THAW_HPP
#define ENJINPLATFORMSDK_THAW_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/FreezeType.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation to thaw a previously frozen collection or token.
class ENJINPLATFORMSDK_EXPORT Thaw : public GraphQlRequest<Thaw, TransactionFragment>,
                                     public HasEncodableTokenId<Thaw>,
                                     public HasIdempotencyKey<Thaw>,
                                     public HasSkipValidation<Thaw>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Thaw();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Thaw(const Thaw& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Thaw(Thaw&& other) noexcept;

    /// \brief Class destructor.
    ~Thaw() override;

    /// \brief Sets the type of thawing to do.
    /// \param freezeType The thawing type.
    /// \return This request for chaining.
    [[maybe_unused]]
    Thaw& SetFreezeType(FreezeType freezeType);

    /// \brief Sets the collection ID to thaw.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    Thaw& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the collection account to thaw.
    /// \param collectionAccount The collection account.
    /// \return This request for chaining.
    [[maybe_unused]]
    Thaw& SetCollectionAccount(SerializableStringPtr collectionAccount);

    /// \brief Sets the token account to thaw.
    /// \param tokenAccount The token account.
    /// \return This request for chaining.
    [[maybe_unused]]
    Thaw& SetTokenAccount(SerializableStringPtr tokenAccount);

    Thaw& operator=(const Thaw& rhs);

    Thaw& operator=(Thaw&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_THAW_HPP
