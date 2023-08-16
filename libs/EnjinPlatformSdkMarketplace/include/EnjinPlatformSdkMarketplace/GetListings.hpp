#ifndef ENJINPLATFORMSDKMARKETPLACE_GETLISTINGS_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETLISTINGS_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/AssetInputType.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceListingFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying market listings.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetListings
    : public GraphQlRequest<GetListings, MarketplaceListingConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetListings();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetListings(const GetListings& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetListings(GetListings&& other) noexcept;

    /// \brief Class destructor.
    ~GetListings() override;

    /// \brief Sets the internal IDs.
    /// \param ids The internal IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListings& SetIds(SerializableStringArrayPtr ids);

    /// \brief Sets the listing IDs.
    /// \param listingIds The listing IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListings& SetListingIds(SerializableStringArrayPtr listingIds);

    /// \brief Sets the wallet account.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListings& SetAccount(SerializableStringPtr account);

    /// \brief Sets the collection and token ID of the asset being sold.
    /// \param makeAssetId The collection and token ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListings& SetMakeAssetId(AssetInputTypePtr makeAssetId);

    /// \brief Sets the collection and token ID of the asset being requested.
    /// \param takeAssetId The collection and token ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetListings& SetTakeAssetId(AssetInputTypePtr takeAssetId);

    GetListings& operator=(const GetListings& rhs);

    GetListings& operator=(GetListings&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETLISTINGS_HPP
