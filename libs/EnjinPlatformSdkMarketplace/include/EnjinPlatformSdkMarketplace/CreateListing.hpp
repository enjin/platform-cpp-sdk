#ifndef ENJINPLATFORMSDKMARKETPLACE_CREATELISTING_HPP
#define ENJINPLATFORMSDKMARKETPLACE_CREATELISTING_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdkMarketplace/AuctionDataInputType.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
/// \brief A request to act as a mutation for canceling a listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT CreateListing : public GraphQlRequest<CreateListing, TransactionFragment>,
                                                         public HasIdempotencyKey<CreateListing>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateListing();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateListing(const CreateListing& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateListing(CreateListing&& other) noexcept;

    /// \brief Class destructor.
    ~CreateListing() override;

    /// \brief Sets the seller account.
    /// \param account The seller account.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetAccount(SerializableStringPtr account);

    /// \brief Sets the collection and token ID of the asset being sold.
    /// \param makeAssetId The collection and token ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetMakeAssetId(MultiTokenIdInputPtr makeAssetId);

    /// \brief Sets the collection and token ID of the asset being requested.
    /// \param takeAsset The collection and token ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetTakeAssetId(MultiTokenIdInputPtr takeAsset);

    /// \brief Sets the number of units being sold.
    /// \param amount The number of units.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetAmount(SerializableStringPtr amount);

    /// \brief Sets the requested price for each unit. If it’s an auction, this is the minimum bid.
    /// \param price The requested price.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetPrice(SerializableStringPtr price);

    /// \brief Sets the salt for the listing.
    /// \param salt The salt.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetSalt(SerializableStringPtr salt);

    /// \brief Sets the data for an auction.
    /// \param auctionData The auction data.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateListing& SetAuctionData(AuctionDataInputTypePtr auctionData);

    CreateListing& operator=(const CreateListing& rhs);

    CreateListing& operator=(CreateListing&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_CREATELISTING_HPP
