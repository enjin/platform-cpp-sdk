#include "EnjinPlatformSdkMarketplace/ListingData.hpp"

using namespace enjin::platform::sdk::marketplace;

[[maybe_unused]]
ListingData::ListingData() = default;

[[maybe_unused]]
ListingData::ListingData(const ListingData& other) = default;

[[maybe_unused]]
ListingData::ListingData(ListingData&& other) noexcept = default;

ListingData::~ListingData() = default;

ListingData& ListingData::operator=(const ListingData& rhs) = default;

ListingData& ListingData::operator=(ListingData&& rhs) noexcept = default;
