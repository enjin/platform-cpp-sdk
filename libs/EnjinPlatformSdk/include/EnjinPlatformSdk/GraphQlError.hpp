#ifndef ENJINPLATFORMSDK_GRAPHQLERROR_HPP
#define ENJINPLATFORMSDK_GRAPHQLERROR_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlErrorLocation.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Models an error in a GraphQL response.
class ENJINPLATFORMSDK_EXPORT GraphQlError : public JsonDeserializableBase
{
    std::optional<std::string> _message;
    std::optional<JsonValue> _extensions;
    std::optional<std::vector<GraphQlErrorLocation>> _locations;
    std::optional<std::vector<std::string>> _path;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlError();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GraphQlError(const GraphQlError& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GraphQlError(GraphQlError&& other) noexcept;

    /// \brief Class destructor.
    ~GraphQlError() override;

    /// \brief Returns the extension containing other information regarding this error.
    /// \return The extension.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetExtensions() const;

    /// \brief Returns the locations in the request where this error occurred.
    /// \return The locations.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<GraphQlErrorLocation>>& GetLocations() const;

    /// \brief Returns the message for this error.
    /// \return The message.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetMessage() const;

    /// \brief Returns the path in the request where this error occurred.
    /// \return The path.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<std::string>>& GetPath() const;

    GraphQlError& operator=(const GraphQlError& rhs);

    GraphQlError& operator=(GraphQlError&& rhs) noexcept;

    bool operator==(const GraphQlError& rhs) const;

    bool operator!=(const GraphQlError& rhs) const;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLERROR_HPP
