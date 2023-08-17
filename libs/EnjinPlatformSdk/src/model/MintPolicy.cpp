#include "EnjinPlatformSdk/MintPolicy.hpp"

#include <utility>

using namespace enjin::platform::sdk;

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
    return GraphQlParameter<MintPolicy>::SetParameter("maxTokenCount", std::move(maxTokenCount));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetMaxTokenSupply(SerializableStringPtr maxTokenSupply)
{
    return GraphQlParameter<MintPolicy>::SetParameter("maxTokenSupply", std::move(maxTokenSupply));
}

[[maybe_unused]]
MintPolicy& MintPolicy::SetForceSingleMint(SerializableBoolPtr forceSingleMint)
{
    return GraphQlParameter<MintPolicy>::SetParameter("forceSingleMint", std::move(forceSingleMint));
}

MintPolicy& MintPolicy::operator=(const MintPolicy& rhs) = default;

MintPolicy& MintPolicy::operator=(MintPolicy&& rhs) noexcept = default;
