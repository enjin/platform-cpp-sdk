#ifndef ENJINPLATFORMSDK_CREATECOLLECTION_HPP
#define ENJINPLATFORMSDK_CREATECOLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AttributeInput.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/MarketPolicy.hpp"
#include "EnjinPlatformSdk/MintPolicy.hpp"
#include "EnjinPlatformSdk/MultiTokenIdInput.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for creating a new on-chain collection.
/// \remarks The new collection ID will be returned in the transaction events after being finalized on-chain.
class ENJINPLATFORMSDK_EXPORT CreateCollection : public GraphQlRequest<CreateCollection, TransactionFragment>,
                                                 public HasIdempotencyKey<CreateCollection>,
                                                 public HasSkipValidation<CreateCollection>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateCollection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateCollection(const CreateCollection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateCollection(CreateCollection&& other) noexcept;

    /// \brief Class destructor.
    ~CreateCollection() override;

    /// \brief Sets the mint policy for tokens in this collection.
    /// \param mintPolicy The mint policy.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateCollection& SetMintPolicy(MintPolicyPtr mintPolicy);

    /// \brief Sets the market policy for the collection.
    /// \param marketPolicy The market policy.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateCollection& SetMarketPolicy(MarketPolicyPtr marketPolicy);

    /// \brief Sets the explicit royalty currencies for tokens in the collection.
    /// \param explicitRoyaltyCurrencies The royalty currencies.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateCollection& SetExplicitRoyaltyCurrencies(
        std::shared_ptr<SerializableArray<MultiTokenIdInput>> explicitRoyaltyCurrencies);

    /// \brief Sets the initial attributes for the collection.
    /// \param attributes The attributes.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateCollection& SetAttributes(std::shared_ptr<SerializableArray<AttributeInput>> attributes);

    CreateCollection& operator=(const CreateCollection& rhs);

    CreateCollection& operator=(CreateCollection&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_CREATECOLLECTION_HPP
