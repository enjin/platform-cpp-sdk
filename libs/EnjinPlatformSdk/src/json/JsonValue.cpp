#include "EnjinPlatformSdk/JsonValue.hpp"

#include "rapidjson/document.h"
#include <utility>

using namespace enjin::platform::sdk::json;
using namespace rapidjson;

class JsonValue::Impl
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
    bool IsArray() const
    {
        return document.IsArray();
    }

    [[nodiscard]]
    bool IsBool() const
    {
        return document.IsBool();
    }

    [[nodiscard]]
    bool IsDouble() const
    {
        return document.IsDouble();
    }

    [[nodiscard]]
    bool IsFloat() const
    {
        return document.IsFloat();
    }

    [[nodiscard]]
    bool IsInt() const
    {
        return document.IsInt();
    }

    [[nodiscard]]
    bool IsInt64() const
    {
        return document.IsInt64();
    }

    [[nodiscard]]
    bool IsNull() const
    {
        return document.IsNull();
    }

    [[nodiscard]]
    bool IsNumber() const
    {
        return document.IsNumber();
    }

    [[nodiscard]]
    bool IsObject() const
    {
        return document.IsObject();
    }

    [[nodiscard]]
    bool IsString() const
    {
        return document.IsString();
    }

    [[nodiscard]]
    bool IsUint() const
    {
        return document.IsUint();
    }

    [[nodiscard]]
    bool IsUint64() const
    {
        return document.IsUint64();
    }

    bool TryGetArrayField(const std::string& key, std::vector<JsonValue>& outArray) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsArray())
        {
            return false;
        }

        outArray.clear();

        for (const Value& el: iter->value.GetArray())
        {
            Document newDocument;
            newDocument.CopyFrom(el, newDocument.GetAllocator());

            JsonValue newValue;
            newValue._pimpl->document = std::move(newDocument);

            outArray.emplace_back(std::move(newValue));
        }

        return true;
    }

    bool TryGetBoolField(const std::string& key, bool& outBool) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsBool())
        {
            return false;
        }

        outBool = iter->value.GetBool();

        return true;
    }

    bool TryGetDoubleField(const std::string& key, double& outDouble) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsDouble())
        {
            return false;
        }

        outDouble = iter->value.GetDouble();

        return true;
    }

    bool TryGetFloatField(const std::string& key, float& outFloat) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsFloat())
        {
            return false;
        }

        outFloat = iter->value.GetFloat();

        return true;
    }

    bool TryGetIntField(const std::string& key, int32_t& outInt) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsInt())
        {
            return false;
        }

        outInt = iter->value.GetInt();

        return true;
    }

    bool TryGetInt64Field(const std::string& key, int64_t& outInt64) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsInt64())
        {
            return false;
        }

        outInt64 = iter->value.GetInt64();

        return true;
    }

    bool TryGetObjectField(const std::string& key, JsonValue& outValue) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsObject())
        {
            return false;
        }

        Document newDocument;
        newDocument.CopyFrom(iter->value, newDocument.GetAllocator());
        outValue._pimpl->document = std::move(newDocument);

        return true;
    }

    bool TryGetStringField(const std::string& key, std::string& outString) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsString())
        {
            return false;
        }

        outString = iter->value.GetString();

        return true;
    }

    bool TryGetUintField(const std::string& key, uint32_t& outUint) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsUint())
        {
            return false;
        }

        outUint = iter->value.GetUint();

        return true;
    }

    bool TryGetUint64Field(const std::string& key, uint64_t& outUint64) const
    {
        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsUint64())
        {
            return false;
        }

        outUint64 = iter->value.GetUint64();

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

JsonValue::JsonValue()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
JsonValue::JsonValue(const JsonValue& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
JsonValue::JsonValue(JsonValue&& other) noexcept
    : _pimpl(std::exchange(other._pimpl, nullptr))
{
}

JsonValue::~JsonValue() = default;

[[maybe_unused]]
bool JsonValue::IsArray() const
{
    return _pimpl->IsArray();
}

[[maybe_unused]]
bool JsonValue::IsBool() const
{
    return _pimpl->IsBool();
}

[[maybe_unused]]
bool JsonValue::IsDouble() const
{
    return _pimpl->IsDouble();
}

[[maybe_unused]]
bool JsonValue::IsFloat() const
{
    return _pimpl->IsFloat();
}

[[maybe_unused]]
bool JsonValue::IsInt() const
{
    return _pimpl->IsInt();
}

[[maybe_unused]]
bool JsonValue::IsInt64() const
{
    return _pimpl->IsInt64();
}

[[maybe_unused]]
bool JsonValue::IsNull() const
{
    return _pimpl->IsNull();
}

[[maybe_unused]]
bool JsonValue::IsNumber() const
{
    return _pimpl->IsNumber();
}

[[maybe_unused]]
bool JsonValue::IsObject() const
{
    return _pimpl->IsObject();
}

[[maybe_unused]]
bool JsonValue::IsString() const
{
    return _pimpl->IsString();
}

[[maybe_unused]]
bool JsonValue::IsUint() const
{
    return _pimpl->IsUint();
}

[[maybe_unused]]
bool JsonValue::IsUint64() const
{
    return _pimpl->IsUint64();
}

[[maybe_unused]]
bool JsonValue::TryGetArrayField(const std::string& key, std::vector<JsonValue>& outArray) const
{
    return _pimpl->TryGetArrayField(key, outArray);
}

[[maybe_unused]]
bool JsonValue::TryGetBoolField(const std::string& key, bool& outBool) const
{
    return _pimpl->TryGetBoolField(key, outBool);
}

[[maybe_unused]]
bool JsonValue::TryGetDoubleField(const std::string& key, double& outDouble) const
{
    return _pimpl->TryGetDoubleField(key, outDouble);
}

[[maybe_unused]]
bool JsonValue::TryGetFloatField(const std::string& key, float& outFloat) const
{
    return _pimpl->TryGetFloatField(key, outFloat);
}

[[maybe_unused]]
bool JsonValue::TryGetIntField(const std::string& key, int32_t& outInt) const
{
    return _pimpl->TryGetIntField(key, outInt);
}

[[maybe_unused]]
bool JsonValue::TryGetInt64Field(const std::string& key, int64_t& outInt64) const
{
    return _pimpl->TryGetInt64Field(key, outInt64);
}

[[maybe_unused]]
bool JsonValue::TryGetObjectField(const std::string& key, JsonValue& outValue) const
{
    return _pimpl->TryGetObjectField(key, outValue);
}

[[maybe_unused]]
bool JsonValue::TryGetStringField(const std::string& key, std::string& outString) const
{
    return _pimpl->TryGetStringField(key, outString);
}

[[maybe_unused]]
bool JsonValue::TryGetUintField(const std::string& key, uint32_t& outUint) const
{
    return _pimpl->TryGetUintField(key, outUint);
}

[[maybe_unused]]
bool JsonValue::TryGetUint64Field(const std::string& key, uint64_t& outUint64) const
{
    return _pimpl->TryGetUint64Field(key, outUint64);
}

JsonValue& JsonValue::operator=(const JsonValue& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

JsonValue& JsonValue::operator=(JsonValue&& rhs) noexcept
{
    _pimpl = std::exchange(rhs._pimpl, nullptr);

    return *this;
}

bool JsonValue::operator==(const JsonValue& rhs) const
{
    return *_pimpl == *rhs._pimpl;
}

bool JsonValue::operator!=(const JsonValue& rhs) const
{
    return *_pimpl != *rhs._pimpl;
}

[[maybe_unused]]
JsonValue JsonValue::FromJson(const std::string& json)
{
    Document document;
    document.Parse(json.c_str());

    JsonValue jsonValue;
    jsonValue._pimpl->document = std::move(document);

    return jsonValue;
}
