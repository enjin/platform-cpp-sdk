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

#include "EnjinPlatformSdk/Block.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"

using namespace enjin::platform::sdk;

// region Impl

class Block::Impl : public JsonDeserializableBase
{
public:
    std::optional<int32_t> id;
    std::optional<std::string> number;
    std::optional<std::string> hash;
    std::optional<bool> synced;
    std::optional<bool> failed;
    std::optional<std::string> exception;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<int32_t>& GetId() const
    {
        return id;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetNumber() const
    {
        return number;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetHash() const
    {
        return hash;
    }

    [[nodiscard]]
    const std::optional<bool>& GetSynced() const
    {
        return synced;
    }

    [[nodiscard]]
    const std::optional<bool>& GetFailed() const
    {
        return failed;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetException() const
    {
        return exception;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "id", id);
        JsonUtil::TryGetField(json, "number", number);
        JsonUtil::TryGetField(json, "hash", hash);
        JsonUtil::TryGetField(json, "synced", synced);
        JsonUtil::TryGetField(json, "failed", failed);
        JsonUtil::TryGetField(json, "exception", exception);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region Block

[[maybe_unused]]
Block::Block()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
Block::Block(const Block& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
Block::Block(Block&& other) noexcept = default;

Block::~Block() = default;

[[maybe_unused]]
const std::optional<int32_t>& Block::GetId() const
{
    return _pimpl->GetId();
}

[[maybe_unused]]
const std::optional<std::string>& Block::GetNumber() const
{
    return _pimpl->GetNumber();
}

[[maybe_unused]]
const std::optional<std::string>& Block::GetHash() const
{
    return _pimpl->GetHash();
}

[[maybe_unused]]
const std::optional<bool>& Block::GetSynced() const
{
    return _pimpl->GetSynced();
}

[[maybe_unused]]
const std::optional<bool>& Block::GetFailed() const
{
    return _pimpl->GetFailed();
}

[[maybe_unused]]
const std::optional<std::string>& Block::GetException() const
{
    return _pimpl->GetException();
}

Block& Block::operator=(const Block& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

Block& Block::operator=(Block&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void Block::Deserialize(const JsonValue& json)
{
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion Block
