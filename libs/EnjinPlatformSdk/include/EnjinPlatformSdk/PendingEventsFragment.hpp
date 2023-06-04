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

#ifndef ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP
#define ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief A fragment for requesting properties of a pending events returned by the platform.
class ENJINPLATFORMSDK_EXPORT PendingEventsFragment : public ConnectionFragment<>
{
public:
    /// \brief Constructs an instance of this class.
    PendingEventsFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    PendingEventsFragment(const PendingEventsFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PendingEventsFragment(PendingEventsFragment&& other) noexcept;

    /// \brief Class destructor.
    ~PendingEventsFragment() override;

    PendingEventsFragment& operator=(const PendingEventsFragment& rhs);

    PendingEventsFragment& operator=(PendingEventsFragment&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PENDINGEVENTSFRAGMENT_HPP
