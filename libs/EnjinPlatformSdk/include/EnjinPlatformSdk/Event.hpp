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

#ifndef ENJINPLATFORMSDK_EVENT_HPP
#define ENJINPLATFORMSDK_EVENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/EventParam.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
// region Forward declarations

class EventParam;

// endregion Forward declarations

/// \brief Models an Efinity event.
class ENJINPLATFORMSDK_EXPORT Event : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Event();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Event(const Event& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Event(Event&& other) noexcept;

    /// \brief Class destructor.
    ~Event() override;

    /// \brief Returns the phase of this event.
    /// \return The phase.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetPhase() const;

    /// \brief Returns the method lookup of this event.
    /// \return The method lookup.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetLookup() const;

    /// \brief Returns the pallet module.
    /// \return The pallet module.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetModuleId() const;

    /// \brief Returns the ID of this event.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetEventId() const;

    /// \brief Returns the parameters from this event.
    /// \return The parameters.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<EventParam>>& GetParams() const;

    Event& operator=(const Event& rhs);

    Event& operator=(Event&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_EVENT_HPP
