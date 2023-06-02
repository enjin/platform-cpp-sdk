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

#ifndef ENJINPLATFORMSDK_ACKNOWLEDGEEVENTS_HPP
#define ENJINPLATFORMSDK_ACKNOWLEDGEEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for acknowledging cached events and removing them from the cache.
class ENJINPLATFORMSDK_EXPORT AcknowledgeEvents : public GraphQlRequest<AcknowledgeEvents>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AcknowledgeEvents();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AcknowledgeEvents(const AcknowledgeEvents& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AcknowledgeEvents(AcknowledgeEvents&& other) noexcept;

    /// \brief Class destructor.
    ~AcknowledgeEvents() override;

    /// \brief Sets the event UUIDs to acknowledge.
    /// \param uuids The event UUIDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    AcknowledgeEvents& SetUuids(SerializableStringArrayPtr uuids);

    AcknowledgeEvents& operator=(const AcknowledgeEvents& rhs);

    AcknowledgeEvents& operator=(AcknowledgeEvents&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_ACKNOWLEDGEEVENTS_HPP
