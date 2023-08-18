#ifndef ENJINPLATFORMSDK_ACCOUNT_HPP
#define ENJINPLATFORMSDK_ACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Models a substrate account.
class ENJINPLATFORMSDK_EXPORT Account : public virtual IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Account();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Account(const Account& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Account(Account&& other) noexcept;

    /// \brief Class destructor.
    ~Account() override;

    /// \brief Returns the account public key.
    /// \return The account public key.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetPublicKey() const;

    /// \brief Returns the account address.
    /// \return The account address.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAddress() const;

    Account& operator=(const Account& rhs);

    Account& operator=(Account&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_ACCOUNT_HPP
