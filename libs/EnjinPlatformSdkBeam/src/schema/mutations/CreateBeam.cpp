#include "EnjinPlatformSdkBeam/CreateBeam.hpp"

#include "EnjinPlatformSdk/CoreTypes.hpp"
#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdkBeam/BeamTypes.hpp"
#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using RequestType = GraphQlRequest<CreateBeam>;

[[maybe_unused]]
CreateBeam::CreateBeam()
    : RequestType("CreateBeam", GraphQlRequestType::Mutation),
      HasBeamCommonFields<CreateBeam>()
{
}

[[maybe_unused]]
CreateBeam::CreateBeam(const CreateBeam& other) = default;

[[maybe_unused]]
CreateBeam::CreateBeam(CreateBeam&& other) noexcept = default;

CreateBeam::~CreateBeam() = default;

[[maybe_unused]]
CreateBeam& CreateBeam::SetFlags(std::shared_ptr<SerializableArray<BeamFlagInputType>> flags)
{
    return RequestType::SetVariable("flags", BeamTypes::BeamFlagInputTypeArray, std::move(flags));
}

[[maybe_unused]]
CreateBeam& CreateBeam::SetCollectionId(SerializableStringPtr collectionId)
{
    return RequestType::SetVariable("collectionId", CoreTypes::BigInt, std::move(collectionId));
}

[[maybe_unused]]
CreateBeam& CreateBeam::SetTokens(std::shared_ptr<SerializableArray<ClaimToken>> tokens)
{
    return RequestType::SetVariable("tokens", BeamTypes::ClaimTokenArray, std::move(tokens));
}

CreateBeam& CreateBeam::operator=(const CreateBeam& rhs) = default;

CreateBeam& CreateBeam::operator=(CreateBeam&& rhs) noexcept = default;
