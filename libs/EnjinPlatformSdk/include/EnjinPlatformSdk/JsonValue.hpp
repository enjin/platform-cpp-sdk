#ifndef ENJINPLATFORMSDK_JSONVALUE_HPP
#define ENJINPLATFORMSDK_JSONVALUE_HPP

#include "enjinplatformsdk_export.h"
#include <memory>
#include <string>
#include <vector>

namespace enjin::platform::sdk::json
{
/// \brief TODO
class ENJINPLATFORMSDK_EXPORT JsonValue
{
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    JsonValue();

    [[maybe_unused]]
    JsonValue(const JsonValue& other);

    [[maybe_unused]]
    JsonValue(JsonValue&& other) noexcept;

    ~JsonValue();

    [[maybe_unused]]
    [[nodiscard]]
    bool IsArray() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsBool() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsDouble() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsFloat() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsInt() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsInt64() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsNull() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsNumber() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsObject() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsString() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsUint() const;

    [[maybe_unused]]
    [[nodiscard]]
    bool IsUint64() const;

    [[maybe_unused]]
    bool TryGetArrayField(const std::string& key, std::vector<JsonValue>& outArray) const;

    [[maybe_unused]]
    bool TryGetBoolField(const std::string& key, bool& outBool) const;

    [[maybe_unused]]
    bool TryGetDoubleField(const std::string& key, double& outDouble) const;

    [[maybe_unused]]
    bool TryGetFloatField(const std::string& key, float& outFloat) const;

    [[maybe_unused]]
    bool TryGetIntField(const std::string& key, int32_t& outInt) const;

    [[maybe_unused]]
    bool TryGetInt64Field(const std::string& key, int64_t& outInt64) const;

    [[maybe_unused]]
    bool TryGetObjectField(const std::string& key, JsonValue& outValue) const;

    [[maybe_unused]]
    bool TryGetStringField(const std::string& key, std::string& outString) const;

    [[maybe_unused]]
    bool TryGetUintField(const std::string& key, uint32_t& outUint) const;

    [[maybe_unused]]
    bool TryGetUint64Field(const std::string& key, uint64_t& outUint64) const;

    JsonValue& operator=(const JsonValue& rhs);

    JsonValue& operator=(JsonValue&& rhs) noexcept;

    bool operator==(const JsonValue& rhs) const;

    bool operator!=(const JsonValue& rhs) const;

    [[maybe_unused]]
    static JsonValue FromJson(const std::string& json);

};
}

#endif //ENJINPLATFORMSDK_JSONVALUE_HPP
