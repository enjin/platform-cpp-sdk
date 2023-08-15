#ifndef ENJINPLATFORMSDKMARKETPLACE_GETSALE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_GETSALE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdkMarketplace/MarketplaceSaleFragment.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request for querying a market listing sale.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT GetSale : public GraphQlRequest<GetSale, MarketplaceSaleFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetSale();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetSale(const GetSale& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetSale(GetSale&& other) noexcept;

    /// \brief Class destructor.
    ~GetSale() override;

    /// \brief Sets the internal ID.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetSale& SetId(SerializableStringPtr id);

    GetSale& operator=(const GetSale& rhs);

    GetSale& operator=(GetSale&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_GETSALE_HPP
