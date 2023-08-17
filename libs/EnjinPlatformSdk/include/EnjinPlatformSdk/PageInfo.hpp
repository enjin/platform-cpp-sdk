#ifndef ENJINPLATFORMSDK_PAGEINFO_HPP
#define ENJINPLATFORMSDK_PAGEINFO_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models information for a page of data.
class ENJINPLATFORMSDK_EXPORT PageInfo : public JsonDeserializableBase
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PageInfo();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PageInfo(const PageInfo& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PageInfo(PageInfo&& other) noexcept;

    /// \brief Class destructor.
    ~PageInfo() override;

    /// \brief Returns whether the cursor has more pages after the current page.
    /// \return Whether the cursor has more pages after the current page.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetHasNextPage() const;

    /// \brief Returns whether the cursor has more pages before the current page.
    /// \return Whether the cursor has more pages before the current page.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetHasPreviousPage() const;

    /// \brief Returns the previous cursor.
    /// \return The previous cursor.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetStartCursor() const;

    /// \brief Returns the next cursor.
    /// \return The next cursor.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetEndCursor() const;

    PageInfo& operator=(const PageInfo& rhs);

    PageInfo& operator=(PageInfo&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_PAGEINFO_HPP
