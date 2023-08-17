#ifndef ENJINPLATFORMSDK_SETCOLLECTIONATTRIBUTE_HPP
#define ENJINPLATFORMSDK_SETCOLLECTIONATTRIBUTE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for setting an attribute on a collection.
class ENJINPLATFORMSDK_EXPORT SetCollectionAttribute
    : public GraphQlRequest<SetCollectionAttribute, TransactionFragment>,
      public HasIdempotencyKey<SetCollectionAttribute>,
      public HasSkipValidation<SetCollectionAttribute>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SetCollectionAttribute();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SetCollectionAttribute(const SetCollectionAttribute& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SetCollectionAttribute(SetCollectionAttribute&& other) noexcept;

    /// \brief Class destructor.
    ~SetCollectionAttribute() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetCollectionAttribute& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the attribute key.
    /// \param key The attribute key.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetCollectionAttribute& SetKey(SerializableStringPtr key);

    /// \brief Sets the attribute value.
    /// \param value The attribute value.
    /// \return This request for chaining.
    [[maybe_unused]]
    SetCollectionAttribute& SetValue(SerializableStringPtr value);

    SetCollectionAttribute& operator=(const SetCollectionAttribute& rhs);

    SetCollectionAttribute& operator=(SetCollectionAttribute&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_SETCOLLECTIONATTRIBUTE_HPP
