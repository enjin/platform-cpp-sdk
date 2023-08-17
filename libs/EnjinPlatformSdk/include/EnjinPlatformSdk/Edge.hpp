#ifndef ENJINPLATFORMSDK_EDGE_HPP
#define ENJINPLATFORMSDK_EDGE_HPP

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models an edge for an entry in a pagination.
/// \tparam T The type within the pagination.
template<class T>
class Edge : public JsonDeserializableBase
{
    std::optional<T> _node;
    std::optional<std::string> _cursor;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Edge() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Edge(const Edge<T>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Edge(Edge<T>&& other) noexcept = default;

    /// \brief Class destructor.
    ~Edge() override = default;

    /// \brief Returns the item on the current cursor.
    /// \return The item.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<T>& GetNode() const
    {
        return _node;
    }

    /// \brief Returns the current cursor.
    /// \return The current cursor.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCursor() const
    {
        return _cursor;
    }

    Edge& operator=(const Edge<T>& rhs) = default;

    Edge& operator=(Edge<T>&& rhs) noexcept = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "node", _node);
        JsonUtil::TryGetField(json, "cursor", _cursor);
    }

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_EDGE_HPP
