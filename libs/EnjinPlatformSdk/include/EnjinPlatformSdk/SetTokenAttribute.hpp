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

#ifndef ENJINPLATFORMSDK_SETTOKENATTRIBUTE_HPP
#define ENJINPLATFORMSDK_SETTOKENATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for setting an attribute on a token.
class ENJINPLATFORMSDK_EXPORT SetTokenAttribute : public GraphQlRequest<SetTokenAttribute, TransactionFragment>,
                                                  public HasEncodableTokenId<SetTokenAttribute>,
                                                  public HasIdempotencyKey<SetTokenAttribute>,
                                                  public HasSkipValidation<SetTokenAttribute>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SetTokenAttribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SetTokenAttribute(const SetTokenAttribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SetTokenAttribute(SetTokenAttribute&& other) noexcept;

    /// \brief Class destructor.
    ~SetTokenAttribute() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetTokenAttribute& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attribute key.
    /// \param key The attribute key.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetTokenAttribute& SetKey(SerializableStringPtr key);

    /// \brief Sets the attribute value.
    /// \param value The attribute value.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetTokenAttribute& SetValue(SerializableStringPtr value);

    SetTokenAttribute& operator=(const SetTokenAttribute& rhs);

    SetTokenAttribute& operator=(SetTokenAttribute&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_SETTOKENATTRIBUTE_HPP
