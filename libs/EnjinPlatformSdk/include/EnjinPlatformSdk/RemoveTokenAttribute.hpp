#ifndef ENJINPLATFORMSDK_REMOVETOKENATTRIBUTE_HPP
#define ENJINPLATFORMSDK_REMOVETOKENATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for removing an attribute from the specified token.
class ENJINPLATFORMSDK_EXPORT RemoveTokenAttribute : public GraphQlRequest<RemoveTokenAttribute, TransactionFragment>,
                                                     public HasEncodableTokenId<RemoveTokenAttribute>,
                                                     public HasIdempotencyKey<RemoveTokenAttribute>,
                                                     public HasSkipValidation<RemoveTokenAttribute>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveTokenAttribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveTokenAttribute(const RemoveTokenAttribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveTokenAttribute(RemoveTokenAttribute&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveTokenAttribute() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveTokenAttribute& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attribute key.
    /// \param key The attribute key.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveTokenAttribute& SetKey(SerializableStringPtr key);

    RemoveTokenAttribute& operator=(const RemoveTokenAttribute& rhs);

    RemoveTokenAttribute& operator=(RemoveTokenAttribute&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_REMOVETOKENATTRIBUTE_HPP
