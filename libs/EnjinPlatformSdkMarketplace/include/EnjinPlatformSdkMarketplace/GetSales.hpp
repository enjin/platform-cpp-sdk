#ifndef ENJINPLATFORMSDKMARKETPLACE_GETSALES_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETSALES_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceSaleFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying market listing sales.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetSales : public GraphQlRequest<GetSales, MarketplaceSaleConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetSales();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetSales(const GetSales& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetSales(GetSales&& other) noexcept;

    /// \brief Class destructor.
    ~GetSales() override;

    /// \brief Sets the internal IDs.
    /// \param ids The internal IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetSales& SetIds(SerializableStringArrayPtr ids);

    /// \brief Sets the wallet accounts.
    /// \param accounts The wallet accounts.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetSales& SetAccounts(SerializableStringArrayPtr accounts);

    /// \brief Sets the listing IDs.
    /// \param listingIds The listing IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetSales& SetListingIds(SerializableStringArrayPtr listingIds);

    GetSales& operator=(const GetSales& rhs);

    GetSales& operator=(GetSales&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETSALES_HPP
