#ifndef ENJINPLATFORMSDKMARKETPLACE_FILLLISTING_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FILLLISTING_HPP

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
/// \brief A request to act as a mutation for filling a fixed price listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FillListing : public GraphQlRequest<FillListing, TransactionFragment>,
                                                       public HasIdempotencyKey<FillListing>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FillListing();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FillListing(const FillListing& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FillListing(FillListing&& other) noexcept;

    /// \brief Class destructor.
    ~FillListing() override;

    /// \brief Sets the listing ID.
    /// \param listingIds The listing ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    FillListing& SetListing(SerializableStringPtr listingIds);

    /// \brief Sets the number of units being sold.
    /// \param amount The number of units.
    /// \return This request for chaining.
    [[maybe_unused]]
    FillListing& SetAmount(SerializableStringPtr amount);

    FillListing& operator=(const FillListing& rhs);

    FillListing& operator=(FillListing&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FILLLISTING_HPP
