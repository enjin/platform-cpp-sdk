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

#ifndef ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP
#define ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/PendingEventsFragment.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a list of events that were broadcasted but not yet acknowledged.
class ENJINPLATFORMSDK_EXPORT GetPendingEvents : public GraphQlRequest<GetPendingEvents, PendingEventsFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetPendingEvents();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetPendingEvents(const GetPendingEvents& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetPendingEvents(GetPendingEvents&& other) noexcept;

    /// \brief Class destructor.
    ~GetPendingEvents() override;

    /// \brief Sets whether to automatically acknowledge all returned events.
    /// \param acknowledgeEvents Whether to acknowledge all returned events.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetPendingEvents& SetAcknowledgeEvents(SerializableBoolPtr acknowledgeEvents);

    GetPendingEvents& operator=(const GetPendingEvents& rhs);

    GetPendingEvents& operator=(GetPendingEvents&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETPENDINGEVENTS_HPP
