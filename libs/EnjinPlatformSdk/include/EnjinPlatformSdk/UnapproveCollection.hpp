#ifndef ENJINPLATFORMSDK_UNAPPROVECOLLECTION_HPP
#define ENJINPLATFORMSDK_UNAPPROVECOLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation removing the approval of any specific account to make transfers from a
/// collection account.
class ENJINPLATFORMSDK_EXPORT UnapproveCollection : public GraphQlRequest<UnapproveCollection, TransactionFragment>,
                                                    public HasIdempotencyKey<UnapproveCollection>,
                                                    public HasSkipValidation<UnapproveCollection>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UnapproveCollection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UnapproveCollection(const UnapproveCollection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UnapproveCollection(UnapproveCollection&& other) noexcept;

    /// \brief Class destructor.
    ~UnapproveCollection() override;

    /// \brief Sets the ID of the collection that approval will be removed from.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UnapproveCollection& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the account that collection approval will be removed from.
    /// \param op The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    UnapproveCollection& SetOperator(SerializableStringPtr op);

    UnapproveCollection& operator=(const UnapproveCollection& rhs);

    UnapproveCollection& operator=(UnapproveCollection&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_UNAPPROVECOLLECTION_HPP
