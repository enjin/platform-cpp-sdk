#include "EnjinPlatformSdk/MintPolicy.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<MintPolicy>;

[[maybe_unused]]
MintPolicy::MintPolicy() = default;

[[maybe_unused]]
MintPolicy::MintPolicy(const MintPolicy& other) = default;

[[maybe_unused]]
MintPolicy::MintPolicy(MintPolicy&& other) noexcept = default;

MintPolicy::~MintPolicy() = default;

[[maybe_unused]]
MintPolicy& MintPolicy::SetMaxTokenCount(SerializableStringPtr maxTokenCount)
{
    return ParameterType::SetParameter("maxTokenCount", std::move(maxTokenCount));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetMaxTokenSupply(SerializableStringPtr maxTokenSupply)
{
    return ParameterType::SetParameter("maxTokenSupply", std::move(maxTokenSupply));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetForceSingleMint(SerializableBoolPtr forceSingleMint)
{
    return ParameterType::SetParameter("forceSingleMint", std::move(forceSingleMint));
}

MintPolicy& MintPolicy::operator=(const MintPolicy& rhs) = default;

MintPolicy& MintPolicy::operator=(MintPolicy&& rhs) noexcept = default;
