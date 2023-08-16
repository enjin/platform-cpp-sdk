#ifndef ENJINPLATFORMSDKMARKETPLACE_GETBIDS_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETBIDS_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBidFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying market listing bids.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetBids : public GraphQlRequest<GetBids, MarketplaceBidConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBids();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBids(const GetBids& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBids(GetBids&& other) noexcept;

    /// \brief Class destructor.
    ~GetBids() override;

    /// \brief Sets the internal IDs.
    /// \param ids The internal IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBids& SetIds(SerializableStringArrayPtr ids);

    /// \brief Sets the wallet accounts.
    /// \param accounts The wallet accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBids& SetAccounts(SerializableStringArrayPtr accounts);

    /// \brief Sets the listing IDs.
    /// \param listingIds The listing IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBids& SetListingIds(SerializableStringArrayPtr listingIds);

    GetBids& operator=(const GetBids& rhs);

    GetBids& operator=(GetBids&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETBIDS_HPP
