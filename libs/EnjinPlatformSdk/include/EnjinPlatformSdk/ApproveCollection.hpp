#ifndef ENJINPLATFORMSDK_APPROVECOLLECTION_HPP
#define ENJINPLATFORMSDK_APPROVECOLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for approving another account to transfer any tokens from a collection
/// account.
/// \remarks The block number where this approval will expire may be specified.
class ENJINPLATFORMSDK_EXPORT ApproveCollection : public GraphQlRequest<ApproveCollection, TransactionFragment>,
                                                  public HasIdempotencyKey<ApproveCollection>,
                                                  public HasSkipValidation<ApproveCollection>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ApproveCollection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ApproveCollection(const ApproveCollection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ApproveCollection(ApproveCollection&& other) noexcept;

    /// \brief Class destructor.
    ~ApproveCollection() override;

    /// \brief Sets the ID of the collection that will be approved.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveCollection& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the account that will be approved to operate the collection.
    /// \param op The account to become an operator.
    /// \return This request for chaining.
    [[maybe_unused]]
    ApproveCollection& SetOperator(SerializableStringPtr op);

    /// \brief Sets the block number where the approval will expire.
    /// \param expiration The block number.
    /// \return This request for chaining.
    /// \remarks If this parameter is null or otherwise unspecified, then the approval will not expire.
    [[maybe_unused]]
    ApproveCollection& SetExpiration(SerializableIntPtr expiration);

    ApproveCollection& operator=(const ApproveCollection& rhs);

    ApproveCollection& operator=(ApproveCollection&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_APPROVECOLLECTION_HPP
