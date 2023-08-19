#ifndef ENJINPLATFORMSDK_MINTRECIPIENT_HPP
#define ENJINPLATFORMSDK_MINTRECIPIENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CreateTokenParams.hpp"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/MintTokenParams.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MintRecipient;

/// \brief Definition for a pointer containing a MintRecipient.
using MintRecipientPtr [[maybe_unused]] = std::shared_ptr<MintRecipient>;

/// \brief Models a parameter for a recipient account for a mint.
class ENJINPLATFORMSDK_EXPORT MintRecipient : public GraphQlParameter<MintRecipient>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MintRecipient();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MintRecipient(const MintRecipient& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MintRecipient(MintRecipient&& other) noexcept;

    /// \brief Class destructor.
    ~MintRecipient() override;

    /// \brief Sets the recipient account of the token.
    /// \param account The account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintRecipient& SetAccount(SerializableStringPtr account);

    /// \brief Sets the parameters to create a token.
    /// \param createParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintRecipient& SetCreateParams(CreateTokenParamsPtr createParams);

    /// \brief Sets the parameters to mint a token.
    /// \param mintParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintRecipient& SetMintParams(MintTokenParamsPtr mintParams);

    MintRecipient& operator=(const MintRecipient& rhs);

    MintRecipient& operator=(MintRecipient&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MINTRECIPIENT_HPP
