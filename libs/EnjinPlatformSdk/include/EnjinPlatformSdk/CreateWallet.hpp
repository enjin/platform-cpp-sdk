#ifndef ENJINPLATFORMSDK_CREATEWALLET_HPP
#define ENJINPLATFORMSDK_CREATEWALLET_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for storing a new unverified wallet record using an external ID.
class ENJINPLATFORMSDK_EXPORT CreateWallet : public GraphQlRequest<CreateWallet>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CreateWallet();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CreateWallet(const CreateWallet& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CreateWallet(CreateWallet&& other) noexcept;

    /// \brief Class destructor.
    ~CreateWallet() override;

    /// \brief Sets the external ID set for the wallet.
    /// \param externalId The external ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    CreateWallet& SetExternalId(SerializableStringPtr externalId);

    CreateWallet& operator=(const CreateWallet& rhs);

    CreateWallet& operator=(CreateWallet&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_CREATEWALLET_HPP
