#ifndef ENJINPLATFORMSDK_VERIFYACCOUNT_HPP
#define ENJINPLATFORMSDK_VERIFYACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CryptoSignatureType.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation that the wallet calls to prove the ownership of the user account.
class ENJINPLATFORMSDK_EXPORT VerifyAccount : public GraphQlRequest<VerifyAccount>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    VerifyAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    VerifyAccount(const VerifyAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    VerifyAccount(VerifyAccount&& other) noexcept;

    /// \brief Class destructor.
    ~VerifyAccount() override;

    /// \brief Sets the verification ID.
    /// \param verificationId The verification ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyAccount& SetVerificationId(SerializableStringPtr verificationId);

    /// \brief Sets the signature.
    /// \param signature The signature.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyAccount& SetSignature(SerializableStringPtr signature);

    /// \brief Sets the account.
    /// \param account The account.
    /// \return This request for chaining.
    [[maybe_unused]]
    VerifyAccount& SetAccount(SerializableStringPtr account);

    /// \brief Sets the signature crypto type.
    /// \param cryptoSignatureType
    /// \return This request for chaining.
    /// \remarks Defaults to ed25519 on the platform if not set.
    [[maybe_unused]]
    VerifyAccount& SetCryptoSignatureType(CryptoSignatureType cryptoSignatureType);

    VerifyAccount& operator=(const VerifyAccount& rhs);

    VerifyAccount& operator=(VerifyAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_VERIFYACCOUNT_HPP
