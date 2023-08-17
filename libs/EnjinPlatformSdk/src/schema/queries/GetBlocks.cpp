#include "EnjinPlatformSdk/GetBlocks.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using RequestType = GraphQlRequest<GetBlocks, BlockConnectionFragment>;

[[maybe_unused]]
GetBlocks::GetBlocks()
    : RequestType("GetBlocks", GraphQlRequestType::Query)
{
}

[[maybe_unused]]
GetBlocks::GetBlocks(const GetBlocks& other) = default;

[[maybe_unused]]
GetBlocks::GetBlocks(GetBlocks&& other) noexcept = default;

GetBlocks::~GetBlocks() = default;

[[maybe_unused]]
GetBlocks& GetBlocks::SetNumber(SerializableStringArrayPtr numbers)
{
    return RequestType::SetVariable("numbers", CoreTypes::StringArray, std::move(numbers));
}

[[maybe_unused]]
GetBlocks& GetBlocks::SetHashes(SerializableStringArrayPtr hashes)
{
    return RequestType::SetVariable("hashes", CoreTypes::StringArray, std::move(hashes));
}

GetBlocks& GetBlocks::operator=(const GetBlocks& rhs) = default;

GetBlocks& GetBlocks::operator=(GetBlocks&& rhs) noexcept = default;
