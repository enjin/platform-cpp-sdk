#ifndef ENJINPLATFORMSDK_REMOVEALLATTRIBUTES_HPP
#define ENJINPLATFORMSDK_REMOVEALLATTRIBUTES_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for removing all attributes from the given collection or token.
class ENJINPLATFORMSDK_EXPORT RemoveAllAttributes : public GraphQlRequest<RemoveAllAttributes, TransactionFragment>,
                                                    public HasEncodableTokenId<RemoveAllAttributes>,
                                                    public HasIdempotencyKey<RemoveAllAttributes>,
                                                    public HasSkipValidation<RemoveAllAttributes>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveAllAttributes();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveAllAttributes(const RemoveAllAttributes& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveAllAttributes(RemoveAllAttributes&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveAllAttributes() override;

    /// \brief Sets the ID of the collection to remove attributes from.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveAllAttributes& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attribute count used to calculate the weight of the on-chain extrinsic.
    /// \param attributeCount The attribute count.
    /// \return This request for chaining.
    /// \remarks This is an advanced feature and is used to calculate the weight of the on-chain extrinsic. Putting a
    /// value in that is not equal to the on-chain attribute count will lead to the transaction failing. When empty, the
    /// attribute count will be auto calculated from data stored in the local database.
    [[maybe_unused]]
    RemoveAllAttributes& SetAttributeCount(SerializableIntPtr attributeCount);

    RemoveAllAttributes& operator=(const RemoveAllAttributes& rhs);

    RemoveAllAttributes& operator=(RemoveAllAttributes&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_REMOVEALLATTRIBUTES_HPP
