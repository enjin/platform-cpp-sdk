#ifndef ENJINPLATFORMSDK_VERIFYMESSAGE_HPP
#define ENJINPLATFORMSDK_VERIFYMESSAGE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CryptoSignatureType.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying whether a message was verified with the provided public key.
class ENJINPLATFORMSDK_EXPORT VerifyMessage : public GraphQlRequest<VerifyMessage>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    VerifyMessage();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    VerifyMessage(const VerifyMessage& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    VerifyMessage(VerifyMessage&& other) noexcept;

    /// \brief Class destructor.
    ~VerifyMessage() override;

    /// \brief Sets the message that the user signed.
    /// \param message The message.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyMessage& SetMessage(SerializableStringPtr message);

    /// \brief Sets the signature.
    /// \param signature The signature.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyMessage& SetSignature(SerializableStringPtr signature);

    /// \brief Sets the public key of the user.
    /// \param publicKey The public key.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyMessage& SetPublicKey(SerializableStringPtr publicKey);

    /// \brief Sets the crypto type of the signature.
    /// \param cryptoSignatureType The signature's crypto type.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyMessage& SetCryptoSignatureType(CryptoSignatureType cryptoSignatureType);

    VerifyMessage& operator=(const VerifyMessage& rhs);

    VerifyMessage& operator=(VerifyMessage&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_VERIFYMESSAGE_HPP
