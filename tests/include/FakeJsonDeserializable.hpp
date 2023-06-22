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

#ifndef ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP
#define ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP

#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include <memory>
#include <optional>

namespace enjin::platform::sdk
{
/// \brief Fake JSON deserializable class for testing.
class FakeJsonDeserializable : virtual public IJsonDeserializable
{
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FakeJsonDeserializable();

    /// \brief Constructs an instance of this class with the given value for its field.
    /// \param field The value of the field.
    [[maybe_unused]]
    explicit FakeJsonDeserializable(bool field);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FakeJsonDeserializable(const FakeJsonDeserializable& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FakeJsonDeserializable(FakeJsonDeserializable&& other) noexcept;

    /// \brief Class destructor.
    ~FakeJsonDeserializable() override;

    FakeJsonDeserializable& operator=(const FakeJsonDeserializable& rhs);

    FakeJsonDeserializable& operator=(FakeJsonDeserializable&& rhs) noexcept;

    bool operator==(const FakeJsonDeserializable& rhs) const;

    bool operator!=(const FakeJsonDeserializable& rhs) const;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP
