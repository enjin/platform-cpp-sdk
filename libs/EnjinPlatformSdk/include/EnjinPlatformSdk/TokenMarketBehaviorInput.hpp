#ifndef ENJINPLATFORMSDK_TOKENMARKETBEHAVIORINPUT_HPP
#define ENJINPLATFORMSDK_TOKENMARKETBEHAVIORINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/RoyaltyInput.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TokenMarketBehaviorInput;

/// \brief Definition for a pointer containing a token market behavior input.
using TokenMarketBehaviorInputPtr [[maybe_unused]] = std::shared_ptr<TokenMarketBehaviorInput>;

/// \brief Models a parameter for the market behavior for a token.
class ENJINPLATFORMSDK_EXPORT TokenMarketBehaviorInput : public GraphQlParameter<TokenMarketBehaviorInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenMarketBehaviorInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenMarketBehaviorInput(const TokenMarketBehaviorInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenMarketBehaviorInput(TokenMarketBehaviorInput&& other) noexcept;

    /// \brief Class destructor.
    ~TokenMarketBehaviorInput() override;

    /// \brief Sets the royalty settings for the market behavior.
    /// \param input The input.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMarketBehaviorInput& SetHasRoyalty(RoyaltyInputPtr input);

    /// \brief Sets whether the token is a currency.
    /// \param isCurrency Whether the token is a currency.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TokenMarketBehaviorInput& SetIsCurrency(SerializableBoolPtr isCurrency);

    TokenMarketBehaviorInput& operator=(const TokenMarketBehaviorInput& rhs);

    TokenMarketBehaviorInput& operator=(TokenMarketBehaviorInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TOKENMARKETBEHAVIORINPUT_HPP
