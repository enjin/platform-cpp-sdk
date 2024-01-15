#ifndef ENJINPLATFORMSDK_FREEZE_HPP
#define ENJINPLATFORMSDK_FREEZE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/FreezeType.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for freezing a collection, token, collection account, or token account.
/// \remarks Tokens cannot be transferred or burned if they are frozen. Freezing a collection or collection account will
/// freeze all the tokens in it.
class ENJINPLATFORMSDK_EXPORT Freeze : public GraphQlRequest<Freeze, TransactionFragment>,
                                       public HasEncodableTokenId<Freeze>,
                                       public HasIdempotencyKey<Freeze>,
                                       public HasSkipValidation<Freeze>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Freeze();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Freeze(const Freeze& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Freeze(Freeze&& other) noexcept;

    /// \brief Class destructor.
    ~Freeze() override;

    /// \brief Sets the type of freezing to do.
    /// \param freezeType The freezing type.
    /// \return This request for chaining.
    [[maybe_unused]]
    Freeze& SetFreezeType(FreezeType freezeType);

    /// \brief Sets the freeze state type.
    /// \param freezeState The freeze state type.
    /// \return This request for chaining.
    [[maybe_unused]]
    Freeze& SetFreezeState(FreezeState freezeState);

    /// \brief Sets the collection ID to freeze.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    /// \deprecated This function is now deprecated and will be removed in a future release.  Use SetCollectionId(SerializableStringPtr collectionId) instead.
    [[maybe_unused]]
    Freeze& SetCollection(SerializableStringPtr collectionId);

    /// \brief Sets the collection ID to freeze.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    Freeze& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the collection account to freeze.
    /// \param collectionAccount The collection account.
    /// \return This request for chaining.
    [[maybe_unused]]
    Freeze& SetCollectionAccount(SerializableStringPtr collectionAccount);

    /// \brief Sets the token account to freeze.
    /// \param tokenAccount The token account.
    /// \return This request for chaining.
    [[maybe_unused]]
    Freeze& SetTokeAccount(SerializableStringPtr tokenAccount);

    Freeze& operator=(const Freeze& rhs);

    Freeze& operator=(Freeze&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_FREEZE_HPP
