#ifndef ENJINPLATFORMSDK_SERIALIZABLEARRAY_HPP
#define ENJINPLATFORMSDK_SERIALIZABLEARRAY_HPP

#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <initializer_list>
#include <iterator>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Class for holding a collection of serializable type and being serializable itself.
/// \tparam T The type held by this array. Must implement ISerializable.
template<class T>
class SerializableArray : public ISerializable
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
    SerializableArray(const SerializableArray& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SerializableArray(SerializableArray&& other) noexcept = default;

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
        if (index < 0 || index >= Length())
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

    SerializableArray& operator=(const SerializableArray& rhs) = default;

    SerializableArray& operator=(SerializableArray&& rhs) noexcept = default;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override
    {
        JsonValue json = JsonValue::FromJson("[]");

        for (const T& el : _array)
        {
            json.AddArrayElement(el.ToJson());
        }

        return json;
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
