#ifndef ENJINPLATFORMSDK_TOKENMUTATIONINPUT_HPP
#define ENJINPLATFORMSDK_TOKENMUTATIONINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/TokenMarketBehaviorInput.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TokenMutationInput;

/// \brief Definition for a pointer containing a TokenMutationInput.
using TokenMutationInputPtr [[maybe_unused]] = std::shared_ptr<TokenMutationInput>;

/// \brief Models a parameter for parameters that can be mutated for a token.
class ENJINPLATFORMSDK_EXPORT TokenMutationInput : public GraphQlParameter<TokenMutationInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenMutationInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenMutationInput(const TokenMutationInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenMutationInput(TokenMutationInput&& other) noexcept;

    /// \brief Class destructor.
    ~TokenMutationInput() override;

    /// \brief Sets the market behavior of the token.
    /// \param behavior The behavior.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMutationInput& SetBehavior(TokenMarketBehaviorInputPtr behavior);

    /// \brief Sets whether the token can be listed in the marketplace.
    /// \param listingForbidden Whether the token can be listed in the marketplace.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMutationInput& SetListingForbidden(SerializableBoolPtr listingForbidden);

    TokenMutationInput& operator=(const TokenMutationInput& rhs);

    TokenMutationInput& operator=(TokenMutationInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TOKENMUTATIONINPUT_HPP
