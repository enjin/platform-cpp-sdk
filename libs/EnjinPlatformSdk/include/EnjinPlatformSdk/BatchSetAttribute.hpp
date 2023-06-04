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

#ifndef ENJINPLATFORMSDK_BATCHSETATTRIBUTE_HPP
#define ENJINPLATFORMSDK_BATCHSETATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AttributeInput.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for setting multiple attributes on a collection or token in one transaction.
/// \remarks The continueOnFailure flag may be used to allow all valid attributes to be set while skipping invalid
/// attributes so that they may be fixed and attempted again in another transaction.
class ENJINPLATFORMSDK_EXPORT BatchSetAttribute : public GraphQlRequest<BatchSetAttribute, TransactionFragment>,
                                                  public HasEncodableTokenId<BatchSetAttribute>,
                                                  public HasIdempotencyKey<BatchSetAttribute>,
                                                  public HasSkipValidation<BatchSetAttribute>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BatchSetAttribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BatchSetAttribute(const BatchSetAttribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BatchSetAttribute(BatchSetAttribute&& other) noexcept;

    /// \brief Class destructor.
    ~BatchSetAttribute() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchSetAttribute& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attributes.
    /// \param attributes The attributes.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchSetAttribute& SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes);

    BatchSetAttribute& operator=(const BatchSetAttribute& rhs);

    BatchSetAttribute& operator=(BatchSetAttribute&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_BATCHSETATTRIBUTE_HPP
