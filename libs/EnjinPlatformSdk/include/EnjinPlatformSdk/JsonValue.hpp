#ifndef ENJINPLATFORMSDK_JSONVALUE_HPP
#define ENJINPLATFORMSDK_JSONVALUE_HPP

#include "enjinplatformsdk_export.h"
#include <memory>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Class representing a JSON value.
class ENJINPLATFORMSDK_EXPORT JsonValue
{
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Initializes a new JsonValue.
    JsonValue();

    /// \brief Copy constructor for this class.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    JsonValue(const JsonValue& other);

    /// \brief Move constructor for this class.
    /// \param other The other instance to move.
    [[maybe_unused]]
    JsonValue(JsonValue&& other) noexcept;

    /// \brief Class destructor.
    ~JsonValue();

    /// \brief Gets the array this value represents.
    /// \return The array.
    [[maybe_unused]]
    [[nodiscard]]
    std::vector<JsonValue> GetArray() const;

    /// \brief Gets the boolean this value represents.
    /// \return The boolean.
    [[maybe_unused]]
    [[nodiscard]]
    bool GetBool() const;

    /// \brief Gets the double this value represents.
    /// \return The double.
    [[maybe_unused]]
    [[nodiscard]]
    double GetDouble() const;

    /// \brief Gets the float this value represents.
    /// \return The float.
    [[maybe_unused]]
    [[nodiscard]]
    float GetFloat() const;

    /// \brief Gets the integer this value represents.
    /// \return The integer.
    [[maybe_unused]]
    [[nodiscard]]
    int32_t GetInt() const;

    /// \brief Gets the long integer this value represents.
    /// \return The long integer.
    [[maybe_unused]]
    [[nodiscard]]
    int64_t GetInt64() const;

    /// \brief Gets the string this value represents.
    /// \return The string.
    [[maybe_unused]]
    [[nodiscard]]
    std::string GetString() const;

    /// \brief Gets the unsigned integer this value represents.
    /// \return The unsigned integer.
    [[maybe_unused]]
    [[nodiscard]]
    uint32_t GetUint() const;

    /// \brief Gets the unsigned long integer this value represents.
    /// \return The unsigned long integer.
    [[maybe_unused]]
    [[nodiscard]]
    uint64_t GetUint64() const;

    /// \brief Determines whether this value represents an array.
    /// \return Whether this value represents an array.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsArray() const;

    /// \brief Determines whether this value represents a bool.
    /// \return Whether this value represents a bool.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsBool() const;

    /// \brief Determines whether this value represents a double.
    /// \return Whether this value represents a double.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsDouble() const;

    /// \brief Determines whether this value represents a float.
    /// \return Whether this value represents a float.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsFloat() const;

    /// \brief Determines whether this value represents an integer.
    /// \return Whether this value represents an integer.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsInt() const;

    /// \brief Determines whether this value represents a long integer.
    /// \return Whether this value represents a long integer.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsInt64() const;

    /// \brief Determines whether this value represents a null.
    /// \return Whether this value represents a null.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsNull() const;

    /// \brief Determines whether this value represents a number.
    /// \return Whether this value represents a number.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsNumber() const;

    /// \brief Determines whether this value represents an object.
    /// \return Whether this value represents an object.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsObject() const;

    /// \brief Determines whether this value represents a string.
    /// \return Whether this value represents a string.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsString() const;

    /// \brief Determines whether this value represents an unsigned integer.
    /// \return Whether this value represents an unsigned integer.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsUint() const;

    /// \brief Determines whether this value represents an unsigned long integer.
    /// \return Whether this value represents an unsigned long integer.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsUint64() const;

    /// \brief Tries to get the value of the given array field.
    /// \param key The field key.
    /// \param outArray The output array.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetArrayField(const std::string& key, std::vector<JsonValue>& outArray) const;

    /// \brief Tries to get the value of the given boolean field.
    /// \param key The field key.
    /// \param outBool The output boolean.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetBoolField(const std::string& key, bool& outBool) const;

    /// \brief Tries to get the value of the given double field.
    /// \param key The field key.
    /// \param outDouble The output double.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetDoubleField(const std::string& key, double& outDouble) const;

    /// \brief Tries to get the value of the given float field.
    /// \param key The field key.
    /// \param outFloat The output float.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetFloatField(const std::string& key, float& outFloat) const;

    /// \brief Tries to get the value of the given integer field.
    /// \param key The field key.
    /// \param outInt The output integer.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetIntField(const std::string& key, int32_t& outInt) const;

    /// \brief Tries to get the value of the given long integer field.
    /// \param key The field key.
    /// \param outInt64 The output long integer.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetInt64Field(const std::string& key, int64_t& outInt64) const;

    /// \brief Tries to get the value of the given object field.
    /// \param key The field key.
    /// \param outValue The output value.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetObjectField(const std::string& key, JsonValue& outValue) const;

    /// \brief Tries to get the value of the given string field.
    /// \param key The field key.
    /// \param outString The output string.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetStringField(const std::string& key, std::string& outString) const;

    /// \brief Tries to get the value of the given unsigned integer field.
    /// \param key The field key.
    /// \param outUint The output unsigned integer.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetUintField(const std::string& key, uint32_t& outUint) const;

    /// \brief Tries to get the value of the given unsigned long integer field.
    /// \param key The field key.
    /// \param outUint64 The output unsigned long integer.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetUint64Field(const std::string& key, uint64_t& outUint64) const;

    JsonValue& operator=(const JsonValue& rhs);

    JsonValue& operator=(JsonValue&& rhs) noexcept;

    bool operator==(const JsonValue& rhs) const;

    bool operator!=(const JsonValue& rhs) const;

    /// \brief Creates a new value from a serialized JSON type.
    /// \param json The serialized JSON.
    /// \return The created value.
    /// \remarks If the JSON is invalid, then the value will be a null value type.
    [[maybe_unused]]
    [[nodiscard]]
    static JsonValue FromJson(const std::string& json);

};
}

#endif //ENJINPLATFORMSDK_JSONVALUE_HPP
