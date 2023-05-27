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

#ifndef ENJINPLATFORMSDK_EVENTFRAGMENT_HPP
#define ENJINPLATFORMSDK_EVENTFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/EventParamFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declaration

class EventParamFragment;

using EventParamFragmentPtr = std::shared_ptr<EventParamFragment>;

// endregion Forward declaration

class EventFragment;

/// \brief Definition for a pointer containing an event fragment.
using EventFragmentPtr [[maybe_unused]] = std::shared_ptr<EventFragment>;

/// \brief Definition for an event connection fragment.
using EventConnectionFragment [[maybe_unused]] = ConnectionFragment<EventFragment>;

/// \brief Definition for a pointer containing an event connection fragment.
using EventConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<EventConnectionFragment>;

/// \brief A fragment for requesting properties of an event returned by the platform.
class ENJINPLATFORMSDK_EXPORT EventFragment : public IGraphQlFragment<EventFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    EventFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EventFragment(const EventFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EventFragment(EventFragment&& other) noexcept;

    /// \brief Class destructor.
    ~EventFragment() override;

    /// \brief Sets whether the event is to be returned with its phase property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventFragment& WithPhase(bool isIncluded = true);

    /// \brief Sets whether the event is to be returned with its lookUp property
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventFragment& WithLookup(bool isIncluded = true);

    /// \brief Sets whether the event is to be returned with its moduleId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventFragment& WithModuleId(bool isIncluded = true);

    /// \brief Sets whether the event is to be returned with its eventId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventFragment& WithEventId(bool isIncluded = true);

    /// \brief Sets the event parameter fragment to be used for getting the params property of the event.
    /// \param fragment The eventParam fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventFragment& WithParams(EventParamFragmentPtr fragment);

    EventFragment& operator=(const EventFragment& rhs);

    EventFragment& operator=(EventFragment&& rhs) noexcept;

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override;

    [[maybe_unused]]
    EventFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    EventFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override;

    [[maybe_unused]]
    EventFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    EventFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_EVENTFRAGMENT_HPP
