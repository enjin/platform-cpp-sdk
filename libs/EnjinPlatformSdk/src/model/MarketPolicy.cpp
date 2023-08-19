#include "EnjinPlatformSdk/MarketPolicy.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<MarketPolicy>;

[[maybe_unused]]
MarketPolicy::MarketPolicy() = default;

[[maybe_unused]]
MarketPolicy::MarketPolicy(const MarketPolicy& other) = default;

[[maybe_unused]]
MarketPolicy::MarketPolicy(MarketPolicy&& other) noexcept = default;

MarketPolicy::~MarketPolicy() = default;

[[maybe_unused]]
MarketPolicy& MarketPolicy::SetRoyalty(RoyaltyInputPtr royalty)
{
    return ParameterType::SetParameter("royalty", std::move(royalty));
}

MarketPolicy& MarketPolicy::operator=(const MarketPolicy& rhs) = default;

MarketPolicy& MarketPolicy::operator=(MarketPolicy&& rhs) noexcept = default;
