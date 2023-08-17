#ifndef ENJINPLATFORMSDK_REQUESTACCOUNT_HPP
#define ENJINPLATFORMSDK_REQUESTACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AccountRequestFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for generating a QR code that a user can scan to request an account for their wallet.
class ENJINPLATFORMSDK_EXPORT RequestAccount : public GraphQlRequest<RequestAccount, AccountRequestFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RequestAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RequestAccount(const RequestAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RequestAccount(RequestAccount&& other) noexcept;

    /// \brief Class destructor.
    ~RequestAccount() override;

    /// \brief Sets the callback URL that the wallet should send the verification to.
    /// \param callback The callback URL.
    /// \return This request for chaining.
    [[maybe_unused]]
    RequestAccount& SetCallback(SerializableStringPtr callback);

    RequestAccount& operator=(const RequestAccount& rhs);

    RequestAccount& operator=(RequestAccount&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_REQUESTACCOUNT_HPP
