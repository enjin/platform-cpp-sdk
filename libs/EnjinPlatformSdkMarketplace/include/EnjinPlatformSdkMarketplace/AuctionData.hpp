#ifndef ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATA_HPP
#define ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATA_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingData.hpp"
#include "EnjinPlatformSdkMarketplace/ListingType.hpp"
#include <memory>
#include <optional>

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the data for an auction listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AuctionData : public ListingData
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AuctionData();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AuctionData(const AuctionData& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AuctionData(AuctionData&& other) noexcept;

    /// \brief Class destructor.
    ~AuctionData() override;

    /// \brief Returns the type of the listing.
    /// \return The type.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ListingType>& GetType() const;

    /// \brief Returns the block number the auction starts at.
    /// \return The block number.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetStartBlock() const;

    /// \brief Returns the block number the auction ends at.
    /// \return The block number.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetEndBlock() const;

    AuctionData& operator=(const AuctionData& rhs);

    AuctionData& operator=(AuctionData&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATA_HPP
