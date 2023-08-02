#include "EnjinPlatformSdkBeam/RemoveTokens.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<RemoveTokens>;

[[maybe_unused]]
RemoveTokens::RemoveTokens()
    : RequestType("RemoveTokens", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
RemoveTokens::RemoveTokens(const RemoveTokens& other) = default;

[[maybe_unused]]
RemoveTokens::RemoveTokens(RemoveTokens&& other) noexcept = default;

RemoveTokens::~RemoveTokens() = default;

[[maybe_unused]]
RemoveTokens& RemoveTokens::SetCode(SerializableStringPtr code)
{
    return RequestType::SetVariable("code", CoreTypes::String, std::move(code));
}

[[maybe_unused]]
RemoveTokens& RemoveTokens::SetTokenIds(std::shared_ptr<SerializableArray<IntegerRange>> tokenIds)
{
    return RequestType::SetVariable("tokenIds", CoreTypes::IntegerRangeString, std::move(tokenIds));
}

RemoveTokens& RemoveTokens::operator=(const RemoveTokens& rhs) = default;

RemoveTokens& RemoveTokens::operator=(RemoveTokens&& rhs) noexcept = default;
