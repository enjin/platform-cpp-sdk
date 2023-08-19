#include "EnjinPlatformSdk/RoyaltyInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<RoyaltyInput>;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput() = default;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput(const RoyaltyInput& other) = default;

[[maybe_unused]]
RoyaltyInput::RoyaltyInput(RoyaltyInput&& other) noexcept = default;

RoyaltyInput::~RoyaltyInput() = default;

[[maybe_unused]]
RoyaltyInput& RoyaltyInput::SetBeneficiary(SerializableStringPtr beneficiary)
{
    return ParameterType::SetParameter("beneficiary", std::move(beneficiary));
}

[[maybe_unused]]
RoyaltyInput& RoyaltyInput::SetPercentage(SerializableDoublePtr percentage)
{
    return ParameterType::SetParameter("percentage", std::move(percentage));
}

RoyaltyInput& RoyaltyInput::operator=(const RoyaltyInput& rhs) = default;

RoyaltyInput& RoyaltyInput::operator=(RoyaltyInput&& rhs) noexcept = default;
