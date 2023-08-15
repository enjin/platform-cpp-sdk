#ifndef ENJINPLATFORMSDKMARKETPLACE_CANCELLISTING_HPP
#define ENJINPLATFORMSDKMARKETPLACE_CANCELLISTING_HPP

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
/// \brief A request to act as a mutation for canceling a listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT CancelListing : public GraphQlRequest<CancelListing, TransactionFragment>,
                                                         public HasIdempotencyKey<CancelListing>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CancelListing();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CancelListing(const CancelListing& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CancelListing(CancelListing&& other) noexcept;

    /// \brief Class destructor.
    ~CancelListing() override;

    /// \brief Sets the listing ID.
    /// \param listingId The listing ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CancelListing& SetListingId(SerializableStringPtr listingId);

    CancelListing& operator=(const CancelListing& rhs);

    CancelListing& operator=(CancelListing&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_CANCELLISTING_HPP
