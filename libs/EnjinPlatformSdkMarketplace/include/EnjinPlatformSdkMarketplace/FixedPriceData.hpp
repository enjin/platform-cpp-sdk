#ifndef ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATA_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATA_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingData.hpp"
#include "EnjinPlatformSdkMarketplace/ListingType.hpp"
#include <memory>
#include <optional>

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the data for a fixed price listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FixedPriceData : public ListingData
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FixedPriceData();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FixedPriceData(const FixedPriceData& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FixedPriceData(FixedPriceData&& other) noexcept;

    /// \brief Class destructor.
    ~FixedPriceData() override;

    /// \brief Returns the type of the listing.
    /// \return The type.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ListingType>& GetType() const;

    FixedPriceData& operator=(const FixedPriceData& rhs);

    FixedPriceData& operator=(FixedPriceData&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICEDATA_HPP
