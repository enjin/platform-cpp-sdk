#ifndef ENJINPLATFORMSDK_MINTTOKEN_HPP
#define ENJINPLATFORMSDK_MINTTOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/MintTokenParams.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for minting more of an existing token.
/// \remarks This operation only applies to tokens which have a supply cap greater than 1.
class ENJINPLATFORMSDK_EXPORT MintToken : public GraphQlRequest<MintToken, TransactionFragment>,
                                          public HasIdempotencyKey<MintToken>,
                                          public HasSkipValidation<MintToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MintToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MintToken(const MintToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MintToken(MintToken&& other) noexcept;

    /// \brief Class destructor.
    ~MintToken() override;

    /// \brief Sets the recipient account that will receive the transfer.
    /// \param recipient The recipient account.
    /// \return This request for chaining.
    [[maybe_unused]]
    MintToken& SetRecipient(SerializableStringPtr recipient);

    /// \brief Sets the collection ID to mint from.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    MintToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the parameters for minting the token.
    /// \param params The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    MintToken& SetParams(MintTokenParamsPtr params);

    MintToken& operator=(const MintToken& rhs);

    MintToken& operator=(MintToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MINTTOKEN_HPP
