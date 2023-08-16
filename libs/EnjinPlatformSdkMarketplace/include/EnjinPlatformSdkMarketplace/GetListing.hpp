#ifndef ENJINPLATFORMSDKMARKETPLACE_GETLISTING_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETLISTING_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListingFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying a market listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetListing : public GraphQlRequest<GetListing, MarketplaceListingFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetListing();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetListing(const GetListing& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetListing(GetListing&& other) noexcept;

    /// \brief Class destructor.
    ~GetListing() override;

    /// \brief Sets the internal ID.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListing& SetId(SerializableStringPtr id);

    /// \brief Sets the listing ID.
    /// \param listingId The listing ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListing& SetListingId(SerializableStringPtr listingId);

    GetListing& operator=(const GetListing& rhs);

    GetListing& operator=(GetListing&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETLISTING_HPP
