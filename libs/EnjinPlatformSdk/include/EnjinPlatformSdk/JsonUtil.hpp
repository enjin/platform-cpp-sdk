#ifndef ENJINPLATFORMSDK_JSONUTIL_HPP
#define ENJINPLATFORMSDK_JSONUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Utility class for handling JSON values.
class ENJINPLATFORMSDK_EXPORT JsonUtil final
{
public:
    JsonUtil() = delete;

    /// \brief Tries to get the specified field from the given JSON value-object.
    /// \tparam T The field type. Must implement IJsonDeserializable.
    /// \param json The JSON value-object.
    /// \param key The field key.
    /// \param outField The out optional to emplace the value to.
    /// \return Whether the field was retrieved.
    /// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
    template<class T>
    [[maybe_unused]]
    static bool TryGetField(const JsonValue& json, const std::string& key, std::optional<T>& outField)
    {
        static_assert(std::is_base_of<IJsonDeserializable, T>::value,
                      "Type T does not implement IJsonDeserializable");

        JsonValue value;

        if (!json.TryGetObjectField(key, value))
        {
            outField.reset();

            return false;
        }

        T newField;
        newField.Deserialize(value);
        outField = std::move(newField);

        return true;
    }

    /// \brief Tries to get the specified array field from the given JSON value-object.
    /// \tparam T The field type. Must implement IJsonDeserializable.
    /// \param json The JSON value-object.
    /// \param key The field key.
    /// \param outField The out optional to emplace the value to.
    /// \return Whether the field was retrieved.
    /// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
    template<class T>
    [[maybe_unused]]
    static bool TryGetField(const JsonValue& json, const std::string& key, std::optional<std::vector<T>>& outField)
    {
        static_assert(std::is_base_of<IJsonDeserializable, T>::value,
                      "Type T does not implement IJsonDeserializable");

        std::vector<JsonValue> valueArray;

        if (!json.TryGetArrayField(key, valueArray))
        {
            outField.reset();

            return false;
        }

        std::vector<T> newField;
        newField.reserve(valueArray.size());

        for (const JsonValue& value : valueArray)
        {
            T el;
            el.Deserialize(value);
            newField.emplace_back(std::move(el));
        }

        outField = std::move(newField);

        return true;
    }
};

// region TryGetField specializations

/// \brief Tries to get the specified boolean field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<bool>& outField)
{
    bool newField;

    if (json.TryGetBoolField(key, newField))
    {
        outField = newField;

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified double field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<double>& outField)
{
    double newField;

    if (json.TryGetDoubleField(key, newField))
    {
        outField = newField;

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified float field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<float>& outField)
{
    float newField;

    if (json.TryGetFloatField(key, newField))
    {
        outField = newField;

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified 32-bit integer field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<int32_t>& outField)
{
    int32_t newField;

    if (json.TryGetIntField(key, newField))
    {
        outField = newField;

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified JSON value field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<JsonValue>& outField)
{
    JsonValue newField;

    if (json.TryGetObjectField(key, newField))
    {
        outField = std::move(newField);

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified array field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json,
                                  const std::string& key,
                                  std::optional<std::vector<JsonValue>>& outField)
{
    std::vector<JsonValue> newField;

    if (json.TryGetArrayField(key, newField))
    {
        outField = std::move(newField);

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified string field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json, const std::string& key, std::optional<std::string>& outField)
{
    std::string newField;

    if (json.TryGetStringField(key, newField))
    {
        outField = std::move(newField);

        return true;
    }

    outField.reset();

    return false;
}

/// \brief Tries to get the specified string array field from the given JSON value-object.
/// \param json The JSON value-object.
/// \param key The field key.
/// \param outField The out optional to emplace the value to.
/// \return Whether the field was retrieved.
/// \remarks If the field is not retrieved, then the out optional will be cleared of any data it holds.
template<>
[[maybe_unused]]
inline bool JsonUtil::TryGetField(const JsonValue& json,
                                  const std::string& key,
                                  std::optional<std::vector<std::string>>& outField)
{
    std::vector<JsonValue> valueArray;

    if (!json.TryGetArrayField(key, valueArray))
    {
        outField.reset();

        return false;
    }

    std::vector<std::string> newField;
    newField.reserve(valueArray.size());

    for (const JsonValue& value : valueArray)
    {
        newField.emplace_back(value.GetString());
    }

    outField = std::move(newField);

    return true;
}

// endregion TryGetField specializations
}

#endif //ENJINPLATFORMSDK_JSONUTIL_HPP
