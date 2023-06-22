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

#include "FakeJsonDeserializable.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class FakeJsonDeserializable::Impl : public JsonDeserializableBase
{
public:
    std::optional<bool> field;

    Impl() = default;

    explicit Impl(const bool field)
        : field(field)
    {
    }

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    bool operator==(const Impl& rhs) const
    {
        return static_cast<const JsonDeserializableBase&>(*this) == rhs
               && field == rhs.field;
    }

    bool operator!=(const Impl& rhs) const
    {
        return !(rhs == *this);
    }

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "field", field);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region FakeJsonDeserializable

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const bool field)
    : _pimpl(std::make_unique<Impl>(field))
{
}

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(const FakeJsonDeserializable& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
FakeJsonDeserializable::FakeJsonDeserializable(FakeJsonDeserializable&& other) noexcept = default;

FakeJsonDeserializable::~FakeJsonDeserializable() = default;

FakeJsonDeserializable& FakeJsonDeserializable::operator=(const FakeJsonDeserializable& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

FakeJsonDeserializable& FakeJsonDeserializable::operator=(FakeJsonDeserializable&& rhs) noexcept = default;

bool FakeJsonDeserializable::operator==(const FakeJsonDeserializable& rhs) const
{
    return *_pimpl == *rhs._pimpl;
}

bool FakeJsonDeserializable::operator!=(const FakeJsonDeserializable& rhs) const
{
    return *_pimpl != *rhs._pimpl;
}

// region IJsonDeserializable

[[maybe_unused]]
void FakeJsonDeserializable::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion FakeJsonDeserializable
