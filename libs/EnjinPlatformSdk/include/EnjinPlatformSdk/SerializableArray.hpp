#ifndef ENJINPLATFORMSDK_SERIALIZABLEARRAY_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEARRAY_HPP

#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableDouble.hpp"
#include "EnjinPlatformSdk/SerializableFloat.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableJsonValue.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <initializer_list>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace enjin::platform::sdk
{
template<class...>
class SerializableArray;

/// \brief Defines a serializable array containing serializable boolean values.
using SerializableBoolArray [[maybe_unused]] = SerializableArray<SerializableBool>;

/// \brief Defines a pointer for a serializable boolean value array.
using SerializableBoolArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableBoolArray>;

/// \brief Defines a serializable array containing serializable double-precision floating-point values.
using SerializableDoubleArray [[maybe_unused]] = SerializableArray<SerializableDouble>;

/// \brief Defines a pointer for a serializable double-precision floating-point value array.
using SerializableDoubleArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableDoubleArray>;

/// \brief Defines a serializable array containing serializable floating-point values.
using SerializableFloatArray [[maybe_unused]] = SerializableArray<SerializableFloat>;

/// \brief Defines a pointer for a serializable floating-point value array.
using SerializableFloatArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableFloatArray>;

/// \brief Defines a serializable array containing serializable 32-bit integer values.
using SerializableIntArray [[maybe_unused]] = SerializableArray<SerializableInt>;

/// \brief Defines a pointer for a serializable 32-bit integer array.
using SerializableIntArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableIntArray>;

/// \brief Defines a serializable array containing serializable JSON values.
using SerializableJsonValueArray [[maybe_unused]] = SerializableArray<SerializableJsonValue>;

/// \brief Defines a pointer for a serializable JSON value array.
using SerializableJsonValueArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableJsonValueArray>;

/// \brief Defines a serializable array containing serializable string values.
using SerializableStringArray [[maybe_unused]] = SerializableArray<SerializableString>;

/// \brief Defines a pointer for a serializable string array.
using SerializableStringArrayPtr [[maybe_unused]] = std::shared_ptr<SerializableStringArray>;

/// \brief Class for holding a collection of serializable type and being serializable itself.
/// \tparam T The type held by this array. Must implement ISerializable.
template<class T>
class SerializableArray<T> : public ISerializable
{
    static_assert(std::is_base_of<ISerializable, T>::value,
                  "Type T does not implement ISerializable");

    std::vector<T> _array;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SerializableArray() = default;

    /// \brief Constructs an instance of this class from the given initializer list.
    /// \param init The initializer list.
    [[maybe_unused]]
    SerializableArray(std::initializer_list<T> init)
        : _array(init)
    {
    }

    /// \brief Constructs an instance of this class from the given vector.
    /// \param vector The vector.
    [[maybe_unused]]
    explicit SerializableArray(std::vector<T> vector)
        : _array(std::move(vector))
    {
    }

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SerializableArray(const SerializableArray<T>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableArray(SerializableArray<T>&& other) noexcept = default;

    /// \brief Class destructor.
    ~SerializableArray() override = default;

    /// \brief Clears this array.
    [[maybe_unused]]
    void Clear()
    {
        _array.clear();
    }

    /// \brief Determines whether this array is empty.
    /// \return Whether this array is empty.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsEmpty() const
    {
        return _array.empty();
    }

    /// \brief Returns the length of this array.
    /// \return The length.
    [[maybe_unused]]
    [[nodiscard]]
    size_t Length() const
    {
        return _array.size();
    }

    /// \brief Pushes the given element to the back of this array.
    /// \param el The element to push.
    [[maybe_unused]]
    void PushBack(T el)
    {
        _array.push_back(std::move(el));
    }

    /// \brief Removes an element at the given index from this array.
    /// \param index The index of the element to remove.
    /// \throws std::out_of_range If the index is out of range.
    [[maybe_unused]]
    void RemoveAt(size_t index)
    {
        if (index >= Length())
        {
            throw std::out_of_range("Index out of range");
        }

        auto iter = _array.begin();
        std::advance(iter, index);

        _array.erase(iter);
    }

    constexpr T& operator[](size_t index)
    {
        return _array[index];
    }

    constexpr const T& operator[](size_t index) const
    {
        return _array[index];
    }

    SerializableArray& operator=(const SerializableArray<T>& rhs) = default;

    SerializableArray& operator=(SerializableArray<T>&& rhs) noexcept = default;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override
    {
        std::vector<JsonValue> json_array;

        for (const T& el : _array)
        {
            json_array.push_back(el.ToJson());
        }

        return JsonValue::FromArray(json_array);
    }

    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override
    {
        return ToJson().ToString();
    }

    // endregion ISerializable
};
}

#endif //ENJINPLATFORMSDK_SERIALIZABLEARRAY_HPP
