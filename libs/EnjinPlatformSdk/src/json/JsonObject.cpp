#include "EnjinPlatformSdk/JsonObject.hpp"

#include "rapidjson/document.h"
#include <stdexcept>
#include <utility>

using namespace enjin::platform::sdk::json;
using namespace rapidjson;

class JsonObject::Impl
{
public:
    Document document;

    Impl() = default;

    Impl(const Impl& other)
    {
        document.CopyFrom(other.document, document.GetAllocator());
    }

    Impl(Impl&& other) noexcept = default;

    ~Impl() = default;

    [[nodiscard]]
    bool GetBoolField(const std::string& key) const
    {
        bool newBool;
        if (TryGetBoolField(key, newBool))
        {
            return newBool;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    double GetDoubleField(const std::string& key) const
    {
        double newDouble;
        if (TryGetDoubleField(key, newDouble))
        {
            return newDouble;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    float GetFloatField(const std::string& key) const
    {
        float newFloat;
        if (TryGetFloatField(key, newFloat))
        {
            return newFloat;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    int32_t GetIntField(const std::string& key) const
    {
        int32_t newInt;
        if (TryGetIntField(key, newInt))
        {
            return newInt;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    int64_t GetInt64Field(const std::string& key) const
    {
        int64_t newInt64;
        if (TryGetInt64Field(key, newInt64))
        {
            return newInt64;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    JsonObject GetObjectField(const std::string& key) const
    {
        JsonObject newObject;
        if (TryGetObjectField(key, newObject))
        {
            return newObject;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    std::string GetStringField(const std::string& key) const
    {
        std::string newString;
        if (TryGetStringField(key, newString))
        {
            return newString;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    uint32_t GetUintField(const std::string& key) const
    {
        uint32_t newUint;
        if (TryGetUintField(key, newUint))
        {
            return newUint;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    uint64_t GetUint64Field(const std::string& key) const
    {
        uint64_t newUint64;
        if (TryGetUint64Field(key, newUint64))
        {
            return newUint64;
        }

        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    [[nodiscard]]
    bool HasArrayField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsArray();
    }

    [[nodiscard]]
    bool HasBoolField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsBool();
    }

    [[nodiscard]]
    bool HasDoubleField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsDouble();
    }

    [[nodiscard]]
    bool HasFloatField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsFloat();
    }

    [[nodiscard]]
    bool HasIntField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsInt();
    }

    [[nodiscard]]
    bool HasInt64Field(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsInt64();
    }

    [[nodiscard]]
    bool HasObjectField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsObject();
    }

    [[nodiscard]]
    bool HasStringField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsString();
    }

    [[nodiscard]]
    bool HasUintField(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsUint();
    }

    [[nodiscard]]
    bool HasUint64Field(const std::string& key) const
    {
        return document.HasMember(key.c_str()) && document[key.c_str()].IsUint64();
    }

    bool TryGetBoolField(const std::string& key, bool& outBool) const
    {
        if (!HasBoolField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outBool = member.GetBool();

        return true;
    }

    bool TryGetDoubleField(const std::string& key, double& outDouble) const
    {
        if (!HasDoubleField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outDouble = member.GetDouble();

        return true;
    }

    bool TryGetFloatField(const std::string& key, float& outFloat) const
    {
        if (!HasFloatField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outFloat = member.GetFloat();

        return true;
    }

    bool TryGetIntField(const std::string& key, int32_t& outInt) const
    {
        if (!HasIntField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outInt = member.GetInt();

        return true;
    }

    bool TryGetInt64Field(const std::string& key, int64_t& outInt64) const
    {
        if (!HasInt64Field(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outInt64 = member.GetInt64();

        return true;
    }

    bool TryGetObjectField(const std::string& key, JsonObject& outObject) const
    {
        if (!HasObjectField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        Document newDocument;
        newDocument.CopyFrom(member, newDocument.GetAllocator());
        outObject._pimpl->document = std::move(newDocument);

        return true;
    }

    bool TryGetStringField(const std::string& key, std::string& outString) const
    {
        if (!HasStringField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outString = member.GetString();

        return true;
    }

    bool TryGetUintField(const std::string& key, uint32_t& outUint) const
    {
        if (!HasUintField(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outUint = member.GetUint();

        return true;
    }

    bool TryGetUint64Field(const std::string& key, uint64_t& outUint64) const
    {
        if (!HasUint64Field(key))
        {
            return false;
        }

        const auto& member = document[key.c_str()];
        outUint64 = member.GetUint64();

        return true;
    }

    Impl& operator=(const Impl& rhs)
    {
        document.CopyFrom(rhs.document, document.GetAllocator());

        return *this;
    }

    Impl& operator=(Impl&& rhs) noexcept = default;

    bool operator==(const Impl& rhs) const
    {
        return document == rhs.document;
    }

    bool operator!=(const Impl& rhs) const
    {
        return !(rhs == *this);
    }
};

JsonObject::JsonObject()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
JsonObject::JsonObject(const JsonObject& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
JsonObject::JsonObject(JsonObject&& other) noexcept
    : _pimpl(std::exchange(other._pimpl, nullptr))
{
}

JsonObject::~JsonObject() = default;

[[maybe_unused]]
bool JsonObject::GetBoolField(const std::string& key) const
{
    return _pimpl->GetBoolField(key);
}

[[maybe_unused]]
double JsonObject::GetDoubleField(const std::string& key) const
{
    return _pimpl->GetDoubleField(key);
}

[[maybe_unused]]
float JsonObject::GetFloatField(const std::string& key) const
{
    return _pimpl->GetFloatField(key);
}

[[maybe_unused]]
int32_t JsonObject::GetIntField(const std::string& key) const
{
    return _pimpl->GetIntField(key);
}

[[maybe_unused]]
int64_t JsonObject::GetInt64Field(const std::string& key) const
{
    return _pimpl->GetInt64Field(key);
}

[[maybe_unused]]
JsonObject JsonObject::GetObjectField(const std::string& key) const
{
    return _pimpl->GetObjectField(key);
}

[[maybe_unused]]
std::string JsonObject::GetStringField(const std::string& key) const
{
    return _pimpl->GetStringField(key);
}

[[maybe_unused]]
uint32_t JsonObject::GetUintField(const std::string& key) const
{
    return _pimpl->GetUintField(key);
}

[[maybe_unused]]
uint64_t JsonObject::GetUint64Field(const std::string& key) const
{
    return _pimpl->GetUint64Field(key);
}

[[maybe_unused]]
bool JsonObject::HasArrayField(const std::string& key) const
{
    return _pimpl->HasArrayField(key);
}

[[maybe_unused]]
bool JsonObject::HasBoolField(const std::string& key) const
{
    return _pimpl->HasBoolField(key);
}

[[maybe_unused]]
bool JsonObject::HasDoubleField(const std::string& key) const
{
    return _pimpl->HasDoubleField(key);
}

[[maybe_unused]]
bool JsonObject::HasFloatField(const std::string& key) const
{
    return _pimpl->HasFloatField(key);
}

[[maybe_unused]]
bool JsonObject::HasIntField(const std::string& key) const
{
    return _pimpl->HasIntField(key);
}

[[maybe_unused]]
bool JsonObject::HasInt64Field(const std::string& key) const
{
    return _pimpl->HasInt64Field(key);
}

[[maybe_unused]]
bool JsonObject::HasObjectField(const std::string& key) const
{
    return _pimpl->HasObjectField(key);
}

[[maybe_unused]]
bool JsonObject::HasStringField(const std::string& key) const
{
    return _pimpl->HasStringField(key);
}

[[maybe_unused]]
bool JsonObject::HasUintField(const std::string& key) const
{
    return _pimpl->HasUintField(key);
}

[[maybe_unused]]
bool JsonObject::HasUint64Field(const std::string& key) const
{
    return _pimpl->HasUint64Field(key);
}

[[maybe_unused]]
bool JsonObject::TryGetBoolField(const std::string& key, bool& outBool) const
{
    return _pimpl->TryGetBoolField(key, outBool);
}

[[maybe_unused]]
bool JsonObject::TryGetDoubleField(const std::string& key, double& outDouble) const
{
    return _pimpl->TryGetDoubleField(key, outDouble);
}

[[maybe_unused]]
bool JsonObject::TryGetFloatField(const std::string& key, float& outFloat) const
{
    return _pimpl->TryGetFloatField(key, outFloat);
}

[[maybe_unused]]
bool JsonObject::TryGetIntField(const std::string& key, int32_t& outInt) const
{
    return _pimpl->TryGetIntField(key, outInt);
}

[[maybe_unused]]
bool JsonObject::TryGetInt64Field(const std::string& key, int64_t& outInt64) const
{
    return _pimpl->TryGetInt64Field(key, outInt64);
}

[[maybe_unused]]
bool JsonObject::TryGetObjectField(const std::string& key, JsonObject& outObject) const
{
    return _pimpl->TryGetObjectField(key, outObject);
}

[[maybe_unused]]
bool JsonObject::TryGetStringField(const std::string& key, std::string& outString) const
{
    return _pimpl->TryGetStringField(key, outString);
}

[[maybe_unused]]
bool JsonObject::TryGetUintField(const std::string& key, uint32_t& outUint) const
{
    return _pimpl->TryGetUintField(key, outUint);
}

[[maybe_unused]]
bool JsonObject::TryGetUint64Field(const std::string& key, uint64_t& outUint64) const
{
    return _pimpl->TryGetUint64Field(key, outUint64);
}

JsonObject& JsonObject::operator=(const JsonObject& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

JsonObject& JsonObject::operator=(JsonObject&& rhs) noexcept
{
    _pimpl = std::exchange(rhs._pimpl, nullptr);

    return *this;
}

bool JsonObject::operator==(const JsonObject& rhs) const
{
    return *_pimpl == *rhs._pimpl;
}

bool JsonObject::operator!=(const JsonObject& rhs) const
{
    return *_pimpl != *rhs._pimpl;
}

[[maybe_unused]]
JsonObject JsonObject::FromJson(const std::string& json)
{
    JsonObject jsonObject;
    Document document;
    document.Parse(json.c_str());

    if (!document.IsObject())
    {
        throw std::runtime_error(""); // TODO: Error message and/or type.
    }

    jsonObject._pimpl->document = std::move(document);

    return jsonObject;
}
