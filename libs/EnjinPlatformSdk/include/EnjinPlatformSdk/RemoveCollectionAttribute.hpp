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

#ifndef ENJINPLATFORMSDK_REMOVECOLLECTIONATTRIBUTE_HPP
#define ENJINPLATFORMSDK_REMOVECOLLECTIONATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for removing an attribute from the specified collection.
class ENJINPLATFORMSDK_EXPORT RemoveCollectionAttribute
    : public GraphQlRequest<RemoveCollectionAttribute, TransactionFragment>,
      public HasIdempotencyKey<RemoveCollectionAttribute>,
      public HasSkipValidation<RemoveCollectionAttribute>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveCollectionAttribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveCollectionAttribute(const RemoveCollectionAttribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveCollectionAttribute(RemoveCollectionAttribute&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveCollectionAttribute() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveCollectionAttribute& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attribute key.
    /// \param key The attribute key.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveCollectionAttribute& SetKey(SerializableStringPtr key);

    RemoveCollectionAttribute& operator=(const RemoveCollectionAttribute& rhs);

    RemoveCollectionAttribute& operator=(RemoveCollectionAttribute&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_REMOVECOLLECTIONATTRIBUTE_HPP
