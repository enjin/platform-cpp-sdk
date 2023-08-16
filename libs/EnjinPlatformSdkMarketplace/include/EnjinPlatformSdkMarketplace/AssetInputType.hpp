#ifndef ENJINPLATFORMSDKMARKETPLACE_ASSETINPUTTYPE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_ASSETINPUTTYPE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
class AssetInputType;

/// \brief Definition for a pointer containing an AssetInputType.
using AssetInputTypePtr [[maybe_unused]] = std::shared_ptr<AssetInputType>;

/// \brief Models a parameter for an asset.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AssetInputType : public GraphQlParameter<AssetInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AssetInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AssetInputType(const AssetInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AssetInputType(AssetInputType&& other) noexcept;

    /// \brief Class destructor.
    ~AssetInputType() override;

    /// \brief Sets the collection ID of the asset.
    /// \param collectionId The collection ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AssetInputType& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the token ID of the asset.
    /// \param tokenId The token ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AssetInputType& SetTokenId(SerializableStringPtr tokenId);

    AssetInputType& operator=(const AssetInputType& rhs);

    AssetInputType& operator=(AssetInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_ASSETINPUTTYPE_HPP
