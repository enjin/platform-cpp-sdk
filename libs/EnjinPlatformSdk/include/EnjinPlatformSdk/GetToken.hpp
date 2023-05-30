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

#ifndef ENJINPLATFORMSDK_GETTOKEN_HPP
#define ENJINPLATFORMSDK_GETTOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TokenFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a token from a collection using its token ID.
class ENJINPLATFORMSDK_EXPORT GetToken : public GraphQlRequest<GetToken, TokenFragment>,
                                         public HasEncodableTokenId<GetToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetToken(const GetToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetToken(GetToken&& other) noexcept;

    /// \brief Class destructor.
    ~GetToken() override;

    /// \brief Sets the token collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetToken& SetCollectionId(SerializableStringPtr collectionId);

    GetToken& operator=(const GetToken& rhs);

    GetToken& operator=(GetToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETTOKEN_HPP
