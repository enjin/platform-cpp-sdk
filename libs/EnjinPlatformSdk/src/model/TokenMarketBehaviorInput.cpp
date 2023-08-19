#include "EnjinPlatformSdk/TokenMarketBehaviorInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<TokenMarketBehaviorInput>;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput() = default;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput(const TokenMarketBehaviorInput& other) = default;

[[maybe_unused]]
TokenMarketBehaviorInput::TokenMarketBehaviorInput(TokenMarketBehaviorInput&& other) noexcept = default;

TokenMarketBehaviorInput::~TokenMarketBehaviorInput() = default;

[[maybe_unused]]
TokenMarketBehaviorInput& TokenMarketBehaviorInput::SetHasRoyalty(RoyaltyInputPtr input)
{
    return ParameterType::SetParameter("input", std::move(input));
}

[[maybe_unused]]
TokenMarketBehaviorInput& TokenMarketBehaviorInput::SetIsCurrency(SerializableBoolPtr isCurrency)
{
    return ParameterType::SetParameter("isCurrency", std::move(isCurrency));
}

TokenMarketBehaviorInput& TokenMarketBehaviorInput::operator=(const TokenMarketBehaviorInput& rhs) = default;

TokenMarketBehaviorInput& TokenMarketBehaviorInput::operator=(TokenMarketBehaviorInput&& rhs) noexcept = default;
