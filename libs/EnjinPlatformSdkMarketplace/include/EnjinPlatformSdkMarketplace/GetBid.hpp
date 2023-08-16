#ifndef ENJINPLATFORMSDKMARKETPLACE_GETBID_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETBID_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceBidFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying a market listing bid.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetBid : public GraphQlRequest<GetBid, MarketplaceBidFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBid();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBid(const GetBid& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBid(GetBid&& other) noexcept;

    /// \brief Class destructor.
    ~GetBid() override;

    /// \brief Sets the internal ID.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBid& SetId(SerializableStringPtr id);

    GetBid& operator=(const GetBid& rhs);

    GetBid& operator=(GetBid&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETBID_HPP
