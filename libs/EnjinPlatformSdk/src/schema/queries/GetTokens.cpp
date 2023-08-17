#include "EnjinPlatformSdk/GetTokens.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetTokens, TokenConnectionFragment>;

[[maybe_unused]]
GetTokens::GetTokens()
    : RequestType("GetTokens", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetTokens::GetTokens(const GetTokens& other) = default;

[[maybe_unused]]
GetTokens::GetTokens(GetTokens&& other) noexcept = default;

GetTokens::~GetTokens() = default;

[[maybe_unused]]
GetTokens& GetTokens::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

GetTokens& GetTokens::operator=(const GetTokens& rhs) = default;

GetTokens& GetTokens::operator=(GetTokens&& rhs) noexcept = default;
