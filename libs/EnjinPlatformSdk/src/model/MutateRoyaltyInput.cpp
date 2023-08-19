#include "EnjinPlatformSdk/MutateRoyaltyInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<MutateRoyaltyInput>;

[[maybe_unused]]
MutateRoyaltyInput::MutateRoyaltyInput() = default;

[[maybe_unused]]
MutateRoyaltyInput::MutateRoyaltyInput(const MutateRoyaltyInput& other) = default;

[[maybe_unused]]
MutateRoyaltyInput::MutateRoyaltyInput(MutateRoyaltyInput&& other) noexcept = default;

MutateRoyaltyInput::~MutateRoyaltyInput() = default;

[[maybe_unused]]
MutateRoyaltyInput& MutateRoyaltyInput::SetBeneficiary(SerializableStringPtr beneficiary)
{
    return ParameterType::SetParameter("beneficiary", std::move(beneficiary));
}

[[maybe_unused]]
MutateRoyaltyInput& MutateRoyaltyInput::SetPercentage(SerializableDoublePtr percentage)
{
    return ParameterType::SetParameter("percentage", std::move(percentage));
}

MutateRoyaltyInput& MutateRoyaltyInput::operator=(const MutateRoyaltyInput& rhs) = default;

MutateRoyaltyInput& MutateRoyaltyInput::operator=(MutateRoyaltyInput&& rhs) noexcept = default;
