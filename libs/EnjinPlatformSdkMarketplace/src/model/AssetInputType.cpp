#include "EnjinPlatformSdkMarketplace/AssetInputType.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::marketplace;
using ParameterType = GraphQlParameter<AssetInputType>;

[[maybe_unused]]
AssetInputType::AssetInputType() = default;

[[maybe_unused]]
AssetInputType::AssetInputType(const AssetInputType& other) = default;

[[maybe_unused]]
AssetInputType::AssetInputType(AssetInputType&& other) noexcept = default;

AssetInputType::~AssetInputType() = default;

[[maybe_unused]]
AssetInputType& AssetInputType::SetCollectionId(SerializableStringPtr collectionId)
{
    return ParameterType::SetParameter("collectionId", std::move(collectionId));
}

[[maybe_unused]]
AssetInputType& AssetInputType::SetTokenId(SerializableStringPtr tokenId)
{
    return ParameterType::SetParameter("tokenId", std::move(tokenId));
}

AssetInputType& AssetInputType::operator=(const AssetInputType& rhs) = default;

AssetInputType& AssetInputType::operator=(AssetInputType&& rhs) noexcept = default;
