#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGDATA_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGDATA_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the specialized data for a listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT ListingData : public virtual IJsonDeserializable
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ListingData(const ListingData& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ListingData(ListingData&& other) noexcept;

    /// \brief Class destructor.
    ~ListingData() override;

    ListingData& operator=(const ListingData& rhs);

    ListingData& operator=(ListingData&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override = 0;

    // endregion IJsonDeserializable

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ListingData();
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGDATA_HPP
