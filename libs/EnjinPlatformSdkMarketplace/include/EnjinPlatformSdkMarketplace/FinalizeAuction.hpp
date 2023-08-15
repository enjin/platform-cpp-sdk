#ifndef ENJINPLATFORMSDKMARKETPLACE_FINALIZEAUCTION_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FINALIZEAUCTION_HPP

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
/// \brief A request to act as a mutation for finalizing an auction.
/// \remarks This will end the auction and transfer funds. The request will fail if the auction is not over.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FinalizeAuction : public GraphQlRequest<FinalizeAuction, TransactionFragment>,
                                                           public HasIdempotencyKey<FinalizeAuction>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FinalizeAuction();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FinalizeAuction(const FinalizeAuction& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FinalizeAuction(FinalizeAuction&& other) noexcept;

    /// \brief Class destructor.
    ~FinalizeAuction() override;

    /// \brief Sets the listing ID.
    /// \param listingId The listing ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    FinalizeAuction& SetListing(SerializableStringPtr listingId);

    FinalizeAuction& operator=(const FinalizeAuction& rhs);

    FinalizeAuction& operator=(FinalizeAuction&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FINALIZEAUCTION_HPP
