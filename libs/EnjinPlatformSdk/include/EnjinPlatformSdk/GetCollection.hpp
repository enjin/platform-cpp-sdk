#ifndef ENJINPLATFORMSDK_GETCOLLECTION_HPP
#define ENJINPLATFORMSDK_GETCOLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying a collection by its collection ID.
class ENJINPLATFORMSDK_EXPORT GetCollection : public GraphQlRequest<GetCollection, CollectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetCollection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetCollection(const GetCollection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetCollection(GetCollection&& other) noexcept;

    /// \brief Class destructor.
    ~GetCollection() override;

    /// \brief Sets the on-chain collection ID to get.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetCollection& SetCollectionId(SerializableStringPtr collectionId);

    GetCollection& operator=(const GetCollection& rhs);

    GetCollection& operator=(GetCollection&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETCOLLECTION_HPP
