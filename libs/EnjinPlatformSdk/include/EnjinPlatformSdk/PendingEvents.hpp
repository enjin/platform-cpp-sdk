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

#ifndef ENJINPLATFORMSDK_PENDINGEVENTS_HPP
#define ENJINPLATFORMSDK_PENDINGEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models events that have been broadcasted, but not yet acknowledge.
class ENJINPLATFORMSDK_EXPORT PendingEvents : public Connection<JsonValue>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PendingEvents();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PendingEvents(const PendingEvents& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PendingEvents(PendingEvents&& other) noexcept;

    /// \brief Class destructor.
    ~PendingEvents() override;

    PendingEvents& operator=(const PendingEvents& rhs);

    PendingEvents& operator=(PendingEvents&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PENDINGEVENTS_HPP
