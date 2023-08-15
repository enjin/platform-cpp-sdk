#ifndef ENJINPLATFORMSDKMARKETPLACE_PLACEBID_HPP
#define ENJINPLATFORMSDKMARKETPLACE_PLACEBID_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request to act as a mutation for placing a bid on a listing.
/// \remarks The listing must be an auction, and it must be currently active.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT PlaceBid : public GraphQlRequest<PlaceBid, TransactionFragment>,
                                                    public HasIdempotencyKey<PlaceBid>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PlaceBid();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PlaceBid(const PlaceBid& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PlaceBid(PlaceBid&& other) noexcept;

    /// \brief Class destructor.
    ~PlaceBid() override;

    /// \brief Sets the listing ID.
    /// \param listingId The listing ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    PlaceBid& SetListingId(SerializableStringPtr listingId);

    /// \brief Sets the bid amount.
    /// \param price The amount.
    /// \return This request for chaining.
    [[maybe_unused]]
    PlaceBid& SetPrice(SerializableStringPtr price);

    PlaceBid& operator=(const PlaceBid& rhs);

    PlaceBid& operator=(PlaceBid&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_PLACEBID_HPP
