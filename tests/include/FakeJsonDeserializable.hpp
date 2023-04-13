#ifndef ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP
#define ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP

#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>

namespace enjin::platform::sdk
{
/// \brief Fake JSON deserializable class for testing.
class [[maybe_unused]] FakeJsonDeserializable : public JsonDeserializableBase
{
    std::optional<bool> _field;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FakeJsonDeserializable();

    /// \brief Constructs an instance of this class with the given value for its field.
    /// \param field The value of the field.
    [[maybe_unused]]
    explicit FakeJsonDeserializable(bool field);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FakeJsonDeserializable(const FakeJsonDeserializable& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FakeJsonDeserializable(FakeJsonDeserializable&& other) noexcept;

    /// \brief Class destructor.
    ~FakeJsonDeserializable() override;

    FakeJsonDeserializable& operator=(const FakeJsonDeserializable& rhs);

    FakeJsonDeserializable& operator=(FakeJsonDeserializable&& rhs) noexcept;

    bool operator==(const FakeJsonDeserializable& rhs) const;

    bool operator!=(const FakeJsonDeserializable& rhs) const;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_FAKEJSONDESERIALIZABLE_HPP
