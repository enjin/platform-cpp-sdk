#include "EnjinPlatformSdk/JsonValue.hpp"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <stdexcept>
#include <utility>

using namespace enjin::platform::sdk;
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

    void AddArrayElement(const JsonValue& element)
    {
        if (!IsArray())
        {
            return;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        document.PushBack(element._pimpl->document, allocator);
    }

    [[nodiscard]]
    std::vector<JsonValue> GetArray() const
    {
        if (!IsArray())
        {
            throw std::runtime_error("Cannot get array from non-array JsonValue");
        }

        std::vector<JsonValue> valueArray;

        for (const Value& el : document.GetArray())
        {
            Document newDocument;
            newDocument.CopyFrom(el, newDocument.GetAllocator());

            JsonValue newValue;
            newValue._pimpl->document = std::move(newDocument);

            valueArray.emplace_back(std::move(newValue));
        }

        return valueArray;
    }

    [[nodiscard]]
    std::vector<JsonValue> GetArrayField(const std::string& key) const
    {
        std::vector<JsonValue> value;

        if (TryGetArrayField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    bool GetBool() const
    {
        if (IsBool())
        {
            return document.GetBool();
        }

        throw std::runtime_error("Cannot get boolean from non-boolean JsonValue");
    }

    [[nodiscard]]
    bool GetBoolField(const std::string& key) const
    {
        bool value;

        if (TryGetBoolField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    double GetDouble() const
    {
        if (IsDouble())
        {
            return document.GetDouble();
        }

        throw std::runtime_error("Cannot get double from non-double JsonValue");
    }

    [[nodiscard]]
    double GetDoubleField(const std::string& key) const
    {
        double value;

        if (TryGetDoubleField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    float GetFloat() const
    {
        if (IsFloat())
        {
            return document.GetFloat();
        }

        throw std::runtime_error("Cannot get float from non-float JsonValue");
    }

    [[nodiscard]]
    float GetFloatField(const std::string& key) const
    {
        float value;

        if (TryGetFloatField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    int32_t GetInt() const
    {
        if (IsInt())
        {
            return document.GetInt();
        }

        throw std::runtime_error("Cannot get integer from non-integer JsonValue");
    }

    [[nodiscard]]
    int32_t GetIntField(const std::string& key) const
    {
        int32_t value;

        if (TryGetIntField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    JsonValue GetObjectField(const std::string& key) const
    {
        JsonValue value;

        if (TryGetObjectField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    std::string GetString() const
    {
        if (IsString())
        {
            return document.GetString();
        }

        throw std::runtime_error("Cannot get string from non-string JsonValue");
    }

    [[nodiscard]]
    std::string GetStringField(const std::string& key) const
    {
        std::string value;

        if (TryGetStringField(key, value))
        {
            return value;
        }

        throw std::runtime_error("Cannot get field '" + key + "' from this JSON value");
    }

    [[nodiscard]]
    JsonValueType GetValueType() const
    {
        switch (document.GetType())
        {
            case kNullType:
                return JsonValueType::Null;

            case kFalseType:
            case kTrueType:
                return JsonValueType::Bool;

            case kObjectType:
                return JsonValueType::Object;

            case kArrayType:
                return JsonValueType::Array;

            case kStringType:
                return JsonValueType::String;

            case kNumberType:
                return JsonValueType::Number;

            default:
                throw std::runtime_error("Unknown value type for JSON value");
        }
    }

    [[nodiscard]]
    bool HasObjectField(const std::string& key) const
    {
        return IsObject() && document.HasMember(key.c_str());
    }

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
    bool IsNull() const
    {
        return document.IsNull();
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

    void RemoveArrayElement(int index)
    {
        if (!IsArray())
        {
            return;
        }

        if (index < 0 || index >= document.Size())
        {
            throw std::out_of_range("Index out of range");
        }

        document.Erase(document.Begin() + index);
    }

    [[nodiscard]]
    std::string ToString() const
    {
        StringBuffer buffer;
        Writer<StringBuffer> writer(buffer);
        document.Accept(writer);

        return {buffer.GetString()};
    }

    bool TryGetArrayField(const std::string& key, std::vector<JsonValue>& outArray) const
    {
        if (!IsObject())
        {
            return false;
        }

        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsArray())
        {
            return false;
        }

        outArray.clear();

        for (const Value& el : iter->value.GetArray())
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
        if (!IsObject())
        {
            return false;
        }

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
        if (!IsObject())
        {
            return false;
        }

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
        if (!IsObject())
        {
            return false;
        }

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
        if (!IsObject())
        {
            return false;
        }

        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsInt())
        {
            return false;
        }

        outInt = iter->value.GetInt();

        return true;
    }

    bool TryGetObjectField(const std::string& key, JsonValue& outValue) const
    {
        if (!IsObject())
        {
            return false;
        }

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
        if (!IsObject())
        {
            return false;
        }

        Value::ConstMemberIterator iter = document.FindMember(key.c_str());

        if (iter == document.MemberEnd() || !iter->value.IsString())
        {
            return false;
        }

        outString = iter->value.GetString();

        return true;
    }

    bool TrySetObjectField(const std::string& key, const JsonValue& value)
    {
        if (!IsObject())
        {
            return false;
        }

        const char* kStr = key.c_str();

        if (document.HasMember(kStr))
        {
            document.RemoveMember(kStr);
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(kStr, allocator);
        Value v;

        v.CopyFrom(value._pimpl->document, allocator);
        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const std::vector<JsonValue>& value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(kArrayType);

        for (const JsonValue& el : value)
        {
            Value elValue;

            elValue.CopyFrom(el._pimpl->document, allocator);
            v.PushBack(elValue.Move(), allocator);
        }

        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const bool value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(value);

        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const double value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(value);

        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const float value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(value);

        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const int32_t value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(value);

        document.AddMember(k.Move(), v.Move(), allocator);

        return true;
    }

    bool TrySetObjectField(const std::string& key, const std::string& value)
    {
        if (!IsObject())
        {
            return false;
        }

        Document::AllocatorType& allocator = document.GetAllocator();
        Value k(key.c_str(), allocator);
        Value v(value.c_str(), allocator);

        document.AddMember(k.Move(), v.Move(), allocator);

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
void JsonValue::AddArrayElement(const JsonValue& element)
{
    _pimpl->AddArrayElement(element);
}

[[maybe_unused]]
std::vector<JsonValue> JsonValue::GetArray() const
{
    return _pimpl->GetArray();
}

[[maybe_unused]]
std::vector<JsonValue> JsonValue::GetArrayField(const std::string& key) const
{
    return _pimpl->GetArrayField(key);
}

[[maybe_unused]]
bool JsonValue::GetBool() const
{
    return _pimpl->GetBool();
}

[[maybe_unused]]
bool JsonValue::GetBoolField(const std::string& key) const
{
    return _pimpl->GetBoolField(key);
}

[[maybe_unused]]
double JsonValue::GetDouble() const
{
    return _pimpl->GetDouble();
}

[[maybe_unused]]
double JsonValue::GetDoubleField(const std::string& key) const
{
    return _pimpl->GetDoubleField(key);
}

[[maybe_unused]]
float JsonValue::GetFloat() const
{
    return _pimpl->GetFloat();
}

[[maybe_unused]]
float JsonValue::GetFloatField(const std::string& key) const
{
    return _pimpl->GetFloatField(key);
}

[[maybe_unused]]
int32_t JsonValue::GetInt() const
{
    return _pimpl->GetInt();
}

[[maybe_unused]]
int32_t JsonValue::GetIntField(const std::string& key) const
{
    return _pimpl->GetIntField(key);
}

[[maybe_unused]]
JsonValue JsonValue::GetObjectField(const std::string& key) const
{
    return _pimpl->GetObjectField(key);
}

[[maybe_unused]]
std::string JsonValue::GetString() const
{
    return _pimpl->GetString();
}

[[maybe_unused]]
std::string JsonValue::GetStringField(const std::string& key) const
{
    return _pimpl->GetStringField(key);
}

[[maybe_unused]]
JsonValueType JsonValue::GetValueType() const
{
    return _pimpl->GetValueType();
}

[[maybe_unused]]
bool JsonValue::HasObjectField(const std::string& key) const
{
    return _pimpl->HasObjectField(key);
}

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
bool JsonValue::IsNull() const
{
    return _pimpl->IsNull();
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
void JsonValue::RemoveArrayElement(const int index)
{
    _pimpl->RemoveArrayElement(index);
}

[[maybe_unused]]
std::string JsonValue::ToString() const
{
    return _pimpl->ToString();
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
bool JsonValue::TrySetObjectField(const std::string& key, const JsonValue& value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const std::vector<JsonValue>& value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const bool value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const double value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const float value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const int32_t value)
{
    return _pimpl->TrySetObjectField(key, value);
}

[[maybe_unused]]
bool JsonValue::TrySetObjectField(const std::string& key, const std::string& value)
{
    return _pimpl->TrySetObjectField(key, value);
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
