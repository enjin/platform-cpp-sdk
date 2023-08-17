#ifndef ENJINPLATFORMSDK_BATCHTRANSFER_HPP
#define ENJINPLATFORMSDK_BATCHTRANSFER_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasContinueOnFailure.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"
#include "EnjinPlatformSdk/TransferRecipient.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for transferring multiple tokens in one transaction.
/// \remarks Up to 250 different transfers per batch may be included. The continueOnFailure flag may be used to allow
/// all valid transfers to complete while skipping transfers which would fail so that they may be fixed and attempted
/// again in another transaction.
class ENJINPLATFORMSDK_EXPORT BatchTransfer : public GraphQlRequest<BatchTransfer, TransactionFragment>,
                                              public HasContinueOnFailure<BatchTransfer>,
                                              public HasIdempotencyKey<BatchTransfer>,
                                              public HasSkipValidation<BatchTransfer>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BatchTransfer();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BatchTransfer(const BatchTransfer& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BatchTransfer(BatchTransfer&& other) noexcept;

    /// \brief Class destructor.
    ~BatchTransfer() override;

    /// \brief Sets the collection ID.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchTransfer& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the recipients for the transfer.
    /// \param recipients The recipients.
    /// \return This request for chaining.
    [[maybe_unused]]
    BatchTransfer& SetRecipients(std::shared_ptr<SerializableArray<TransferRecipient>> recipients);

    /// \brief Sets the signing wallet for the transaction.
    /// \param signingAccount The signing wallet account.
    /// \return This request for chaining.
    /// \remarks The account defaults to wallet daemon if not specified.
    [[maybe_unused]]
    BatchTransfer& SetSigningAccount(SerializableStringPtr signingAccount);

    BatchTransfer& operator=(const BatchTransfer& rhs);

    BatchTransfer& operator=(BatchTransfer&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_BATCHTRANSFER_HPP
