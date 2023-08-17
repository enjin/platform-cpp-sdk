#ifndef ENJINPLATFORMSDK_GETCOLLECTIONS_HPP
#define ENJINPLATFORMSDK_GETCOLLECTIONS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of collections optionally filtered by collection IDs.
class ENJINPLATFORMSDK_EXPORT GetCollections : public GraphQlRequest<GetCollections, CollectionConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetCollections();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetCollections(const GetCollections& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetCollections(GetCollections&& other) noexcept;

    /// \brief Class destructor.
    ~GetCollections() override;

    /// \brief Sets the on-chain collection IDs to filter to.
    /// \param collectionIds The collection IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetCollections& SetCollectionIds(SerializableStringArrayPtr collectionIds);

    GetCollections& operator=(const GetCollections& rhs);

    GetCollections& operator=(GetCollections&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETCOLLECTIONS_HPP
