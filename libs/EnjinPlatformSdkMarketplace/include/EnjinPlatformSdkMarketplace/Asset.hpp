#ifndef ENJINPLATFORMSDKMARKETPLACE_ASSET_HPP
#define ENJINPLATFORMSDKMARKETPLACE_ASSET_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the state of a marketplace listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT Asset : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Asset();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Asset(const Asset& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Asset(Asset&& other) noexcept;

    /// \brief Class destructor.
    ~Asset() override;

    /// \brief Returns the collection ID of this asset.
    /// \return The collection ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetCollectionId() const;

    /// \brief Returns the token ID of this asset.
    /// \return The token ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetTokenId() const;

    Asset& operator=(const Asset& rhs);

    Asset& operator=(Asset&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_ASSET_HPP
