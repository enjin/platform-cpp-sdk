#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the mutable state of a listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT ListingState : public virtual IJsonDeserializable
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ListingState(const ListingState& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ListingState(ListingState&& other) noexcept;

    /// \brief Class destructor.
    ~ListingState() override;

    ListingState& operator=(const ListingState& rhs);

    ListingState& operator=(ListingState&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override = 0;

    // endregion IJsonDeserializable

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ListingState();
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATE_HPP
