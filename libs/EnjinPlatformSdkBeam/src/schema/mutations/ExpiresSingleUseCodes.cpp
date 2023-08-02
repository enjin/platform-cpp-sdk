#include "EnjinPlatformSdkBeam/ExpiresSingleUseCodes.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<ExpiresSingleUseCodes>;

[[maybe_unused]]
ExpiresSingleUseCodes::ExpiresSingleUseCodes()
    : RequestType("ExpiresSingleUseCodes", GraphQlRequestType::Mutation)
{
}

[[maybe_unused]]
ExpiresSingleUseCodes::ExpiresSingleUseCodes(const ExpiresSingleUseCodes& other) = default;

[[maybe_unused]]
ExpiresSingleUseCodes::ExpiresSingleUseCodes(ExpiresSingleUseCodes&& other) noexcept = default;

ExpiresSingleUseCodes::~ExpiresSingleUseCodes() = default;

[[maybe_unused]]
ExpiresSingleUseCodes& ExpiresSingleUseCodes::SetCodes(SerializableStringArrayPtr codes)
{
    return RequestType::SetVariable("codes", CoreTypes::StringArray, std::move(codes));
}

ExpiresSingleUseCodes& ExpiresSingleUseCodes::operator=(const ExpiresSingleUseCodes& rhs) = default;

ExpiresSingleUseCodes& ExpiresSingleUseCodes::operator=(ExpiresSingleUseCodes&& rhs) noexcept = default;
