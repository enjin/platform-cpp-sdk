#include "EnjinPlatformSdk/TokenMutationInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<TokenMutationInput>;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput() = default;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput(const TokenMutationInput& other) = default;

[[maybe_unused]]
TokenMutationInput::TokenMutationInput(TokenMutationInput&& other) noexcept = default;

TokenMutationInput::~TokenMutationInput() = default;

[[maybe_unused]]
TokenMutationInput& TokenMutationInput::SetBehavior(TokenMarketBehaviorInputPtr behavior)
{
    return ParameterType::SetParameter("behavior", std::move(behavior));
}

[[maybe_unused]]
TokenMutationInput& TokenMutationInput::SetListingForbidden(SerializableBoolPtr listingForbidden)
{
    return ParameterType::SetParameter("listingForbidden", std::move(listingForbidden));
}

TokenMutationInput& TokenMutationInput::operator=(const TokenMutationInput& rhs) = default;

TokenMutationInput& TokenMutationInput::operator=(TokenMutationInput&& rhs) noexcept = default;
