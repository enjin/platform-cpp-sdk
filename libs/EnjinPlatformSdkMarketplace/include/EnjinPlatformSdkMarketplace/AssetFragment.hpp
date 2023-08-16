#ifndef ENJINPLATFORMSDKMARKETPLACE_ASSETFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_ASSETFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
class AssetFragment;

/// \brief Definition for a pointer containing an AssetFragment.
using AssetFragmentPtr [[maybe_unused]] = std::shared_ptr<AssetFragment>;

/// \brief Definition for a ConnectionFragment containing an AssetFragment.
using AssetConnectionFragment [[maybe_unused]] = ConnectionFragment<AssetFragment>;

/// \brief Definition for a pointer containing an AssetConnectionFragment.
using AssetConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AssetConnectionFragment>;

/// \brief A fragment for requesting properties of an Asset returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AssetFragment : public virtual IGraphQlFragment<AssetFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AssetFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AssetFragment(const AssetFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AssetFragment(AssetFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AssetFragment() override;

    /// \brief Sets whether the Asset is to be returned with its collectionId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AssetFragment& WithCollectionId(bool isIncluded = true);

    /// \brief Sets whether the Asset is to be returned with its tokenId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AssetFragment& WithTokenId(bool isIncluded = true);

    AssetFragment& operator=(const AssetFragment& rhs);

    AssetFragment& operator=(AssetFragment&& rhs) noexcept;

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override;

    [[maybe_unused]]
    AssetFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AssetFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameter(const std::string& key) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override;

    [[maybe_unused]]
    AssetFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AssetFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_ASSETFRAGMENT_HPP
