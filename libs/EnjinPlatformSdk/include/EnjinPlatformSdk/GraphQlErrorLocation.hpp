#ifndef ENJINPLATFORMSDK_GRAPHQLERRORLOCATION_HPP
#define ENJINPLATFORMSDK_GRAPHQLERRORLOCATION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>

namespace enjin::platform::sdk
{
/// \brief Models the location of where an error in a GraphQL request occurred.
class ENJINPLATFORMSDK_EXPORT GraphQlErrorLocation : public JsonDeserializableBase
{
    std::optional<int32_t> line;
    std::optional<int32_t> column;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlErrorLocation();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GraphQlErrorLocation(const GraphQlErrorLocation& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GraphQlErrorLocation(GraphQlErrorLocation&& other) noexcept;

    /// \brief Class destructor.
    ~GraphQlErrorLocation() override;

    /// \brief Returns the column in the request where the error occurred.
    /// \return The column.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetColumn() const;

    /// \brief Returns the line in the request where the error occurred.
    /// \return The line.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetLine() const;

    GraphQlErrorLocation& operator=(const GraphQlErrorLocation& rhs);

    GraphQlErrorLocation& operator=(GraphQlErrorLocation&& rhs) noexcept;

    bool operator==(const GraphQlErrorLocation& rhs) const;

    bool operator!=(const GraphQlErrorLocation& rhs) const;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLERRORLOCATION_HPP
