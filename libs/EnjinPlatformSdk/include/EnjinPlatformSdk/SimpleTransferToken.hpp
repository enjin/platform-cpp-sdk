#ifndef ENJINPLATFORMSDK_SIMPLETRANSFERTOKEN_HPP
#define ENJINPLATFORMSDK_SIMPLETRANSFERTOKEN_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/SimpleTransferParams.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for transferring a single token to a recipient account.
class ENJINPLATFORMSDK_EXPORT SimpleTransferToken : public GraphQlRequest<SimpleTransferToken, TransactionFragment>,
                                                    public HasIdempotencyKey<SimpleTransferToken>,
                                                    public HasSkipValidation<SimpleTransferToken>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SimpleTransferToken();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SimpleTransferToken(const SimpleTransferToken& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SimpleTransferToken(SimpleTransferToken&& other) noexcept;

    /// \brief Class destructor.
    ~SimpleTransferToken() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    SimpleTransferToken& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the recipient account that will receive the transfer.
    /// \param recipient The recipient account.
    /// \return This request for chaining.
    [[maybe_unused]]
    SimpleTransferToken& SetRecipient(SerializableStringPtr recipient);

    /// \brief Sets the parameters for the transfer.
    /// \param params The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    SimpleTransferToken& SetParams(SimpleTransferParamsPtr params);

    /// \brief Sets the signing wallet for the transaction.
    /// \param signingAccount The signing wallet account.
    /// \return This request for chaining.
    /// \remarks The account defaults to wallet daemon if not specified.
    [[maybe_unused]]
    SimpleTransferToken& SetSigningAccount(SerializableStringPtr signingAccount);

    SimpleTransferToken& operator=(const SimpleTransferToken& rhs);

    SimpleTransferToken& operator=(SimpleTransferToken&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_SIMPLETRANSFERTOKEN_HPP
