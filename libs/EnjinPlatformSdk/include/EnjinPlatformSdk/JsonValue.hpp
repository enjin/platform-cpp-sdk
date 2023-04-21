#ifndef ENJINPLATFORMSDK_JSONVALUE_HPP
#define ENJINPLATFORMSDK_JSONVALUE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValueType.hpp"
#include <memory>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Class representing a JSON value.
class ENJINPLATFORMSDK_EXPORT JsonValue
{
    /// \brief The implementation of this class.
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

    /// \brief Adds the given element to this value if this value is an array.
    /// \param element The element to add.
    [[maybe_unused]]
    void AddArrayElement(const JsonValue& element);

    /// \brief Gets the array this value represents.
    /// \return The array.
    [[maybe_unused]]
    [[nodiscard]]
    std::vector<JsonValue> GetArray() const;

    /// \brief Gets an array field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    std::vector<JsonValue> GetArrayField(const std::string& key) const;

    /// \brief Gets the boolean this value represents.
    /// \return The boolean.
    [[maybe_unused]]
    [[nodiscard]]
    bool GetBool() const;

    /// \brief Gets a boolean field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    bool GetBoolField(const std::string& key) const;

    /// \brief Gets the double this value represents.
    /// \return The double.
    [[maybe_unused]]
    [[nodiscard]]
    double GetDouble() const;

    /// \brief Gets a double field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    double GetDoubleField(const std::string& key) const;

    /// \brief Gets the float this value represents.
    /// \return The float.
    [[maybe_unused]]
    [[nodiscard]]
    float GetFloat() const;

    /// \brief Gets a float field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    float GetFloatField(const std::string& key) const;

    /// \brief Gets the integer this value represents.
    /// \return The integer.
    [[maybe_unused]]
    [[nodiscard]]
    int32_t GetInt() const;

    /// \brief Gets a 32-bit integer field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    int32_t GetIntField(const std::string& key) const;

    /// \brief Gets an object field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    JsonValue GetObjectField(const std::string& key) const;

    /// \brief Gets the string this value represents.
    /// \return The string.
    [[maybe_unused]]
    [[nodiscard]]
    std::string GetString() const;

    /// \brief Gets a string field from this value-object.
    /// \param key The field key.
    /// \return The field value.
    /// \throws runtime_error Thrown if the field is unable to be gotten from this value.
    [[maybe_unused]]
    [[nodiscard]]
    std::string GetStringField(const std::string& key) const;

    /// \brief Gets the JSON type of this value.
    /// \return The JSON type.
    [[maybe_unused]]
    [[nodiscard]]
    JsonValueType GetValueType() const;

    /// \brief Determines whether this value-object has a field with the given key.
    /// \param key The field key.
    /// \return Whether the field is present.
    /// \remarks This function may return false if either this value is not an object or the field is not present in it.
    [[maybe_unused]]
    [[nodiscard]]
    bool HasObjectField(const std::string& key) const;

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

    /// \brief Determines whether this value represents a null.
    /// \return Whether this value represents a null.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsNull() const;

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

    /// \brief Removes an element at the given index from this value if this value is an array.
    /// \param index The index of the element to remove.
    /// \throws std::out_of_range If the index is out of range.
    [[maybe_unused]]
    void RemoveArrayElement(int index);

    /// \brief Converts this value into its string representation.
    /// \return The stringified representation of this value.
    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const;

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

    /// \brief Tries to get the value of the given 32-bit integer field.
    /// \param key The field key.
    /// \param outInt The output integer.
    /// \return Whether the field was retrieved.
    [[maybe_unused]]
    bool TryGetIntField(const std::string& key, int32_t& outInt) const;

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

    /// \brief Tries to set a field on this value-object with the given value.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, const JsonValue& value);

    /// \brief Tries to set a field on this value-object with the given array of values.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, const std::vector<JsonValue>& value);

    /// \brief Tries to set a field on this value-object with the given boolean.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, bool value);

    /// \brief Tries to set a field on this value-object with the given double.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, double value);

    /// \brief Tries to set a field on this value-object with the given float.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, float value);

    /// \brief Tries to set a field on this value-object with the given 32-bit integer.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, int32_t value);

    /// \brief Tries to set a field on this value-object with the given string.
    /// \param key The field key.
    /// \param value The field value.
    /// \return Whether the field was set.
    [[maybe_unused]]
    bool TrySetObjectField(const std::string& key, const std::string& value);

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
