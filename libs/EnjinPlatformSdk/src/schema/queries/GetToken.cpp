#include "EnjinPlatformSdk/GetToken.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetToken, TokenFragment>;

[[maybe_unused]]
GetToken::GetToken()
    : RequestType("GetToken", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetToken::GetToken(const GetToken& other) = default;

[[maybe_unused]]
GetToken::GetToken(GetToken&& other) noexcept = default;

GetToken::~GetToken() = default;

[[maybe_unused]]
GetToken& GetToken::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

GetToken& GetToken::operator=(const GetToken& rhs) = default;

GetToken& GetToken::operator=(GetToken&& rhs) noexcept = default;
