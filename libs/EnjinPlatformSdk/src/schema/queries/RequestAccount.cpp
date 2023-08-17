#include "EnjinPlatformSdk/RequestAccount.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<RequestAccount, AccountRequestFragment>;

[[maybe_unused]]
RequestAccount::RequestAccount()
    : RequestType("RequestAccount", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
RequestAccount::RequestAccount(const RequestAccount& other) = default;

[[maybe_unused]]
RequestAccount::RequestAccount(RequestAccount&& other) noexcept = default;

RequestAccount::~RequestAccount() = default;

[[maybe_unused]]
RequestAccount& RequestAccount::SetCallback(SerializableStringPtr callback)
{
    return RequestType::SetVariable("callback", CoreTypes::String, std::move(callback));
}

RequestAccount& RequestAccount::operator=(const RequestAccount& rhs) = default;

RequestAccount& RequestAccount::operator=(RequestAccount&& rhs) noexcept = default;
