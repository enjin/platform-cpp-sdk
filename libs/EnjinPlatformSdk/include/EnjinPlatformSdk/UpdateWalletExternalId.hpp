#ifndef ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP
#define ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for changing the external ID on a wallet model.
class ENJINPLATFORMSDK_EXPORT UpdateWalletExternalId : public GraphQlRequest<UpdateWalletExternalId>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    UpdateWalletExternalId();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    UpdateWalletExternalId(const UpdateWalletExternalId& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    UpdateWalletExternalId(UpdateWalletExternalId&& other) noexcept;

    /// \brief Class destructor.
    ~UpdateWalletExternalId() override;

    /// \brief Sets the internal ID of the wallet.
    /// \param id The internal ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetId(SerializableIntPtr id);

    /// \brief Sets the external ID for the wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetExternalId(SerializableStringPtr externalId);

    /// \brief Sets the new external ID to set for the wallet.
    /// \param newExternalId The new external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetNewExternalId(SerializableIntPtr newExternalId);

    /// \brief Sets the wallet account on the blockchain.
    /// \param account The wallet account.
    /// \return This request for chaining.
    [[maybe_unused]]
    UpdateWalletExternalId& SetAccount(SerializableIntPtr account);

    UpdateWalletExternalId& operator=(const UpdateWalletExternalId& rhs);

    UpdateWalletExternalId& operator=(UpdateWalletExternalId&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_UPDATEWALLETEXTERNALID_HPP
