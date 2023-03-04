#ifndef ENJINPLATFORMSDK_JSONOBJECT_HPP
#define ENJINPLATFORMSDK_JSONOBJECT_HPP

#include "enjinplatformsdk_export.h"
#include <memory>
#include <string>

namespace enjin::platform::sdk::json
{
/// \brief TODO
class ENJINPLATFORMSDK_EXPORT JsonObject
{
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    JsonObject();

    [[maybe_unused]]
    JsonObject(const JsonObject& other);

    [[maybe_unused]]
    JsonObject(JsonObject&& other) noexcept;

    ~JsonObject();

    /* TODO: Get array field. (May have to be serialized) */

    [[maybe_unused]]
    [[nodiscard]]
    bool GetBoolField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    double GetDoubleField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    float GetFloatField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    int32_t GetIntField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    int64_t GetInt64Field(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    JsonObject GetObjectField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    std::string GetStringField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    uint32_t GetUintField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    uint64_t GetUint64Field(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasArrayField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasBoolField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasDoubleField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFloatField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasIntField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasInt64Field(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasNullField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasObjectField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasStringField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasUintField(const std::string& key) const;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasUint64Field(const std::string& key) const;

    /* TODO: Try-get array field. (May have to be serialized) */

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
    bool TryGetObjectField(const std::string& key, JsonObject& outObject) const;

    [[maybe_unused]]
    bool TryGetStringField(const std::string& key, std::string& outString) const;

    [[maybe_unused]]
    bool TryGetUintField(const std::string& key, uint32_t& outUint) const;

    [[maybe_unused]]
    bool TryGetUint64Field(const std::string& key, uint64_t& outUint64) const;

    JsonObject& operator=(const JsonObject& rhs);

    JsonObject& operator=(JsonObject&& rhs) noexcept;

    bool operator==(const JsonObject& rhs) const;

    bool operator!=(const JsonObject& rhs) const;

    [[maybe_unused]]
    static JsonObject FromJson(const std::string& json);

};
}

#endif //ENJINPLATFORMSDK_JSONOBJECT_HPP
