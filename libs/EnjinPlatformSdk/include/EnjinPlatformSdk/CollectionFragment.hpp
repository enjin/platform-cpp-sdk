#ifndef ENJINPLATFORMSDK_COLLECTIONFRAGMENT_HPP
#define ENJINPLATFORMSDK_COLLECTIONFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AttributeFragment.hpp"
#include "EnjinPlatformSdk/CollectionAccountFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/RoyaltyFragment.hpp"
#include "EnjinPlatformSdk/TokenFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class AttributeFragment;

using AttributeFragmentPtr = std::shared_ptr<AttributeFragment>;

class CollectionAccountFragment;

using CollectionAccountConnectionFragment = ConnectionFragment<CollectionAccountFragment>;
using CollectionAccountConnectionFragmentPtr = std::shared_ptr<CollectionAccountConnectionFragment>;

class RoyaltyFragment;

using RoyaltyFragmentPtr = std::shared_ptr<RoyaltyFragment>;

class TokenFragment;

using TokenConnectionFragment = ConnectionFragment<TokenFragment>;
using TokenConnectionFragmentPtr = std::shared_ptr<TokenConnectionFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class CollectionFragment;

/// \brief Definition for a pointer containing a CollectionFragment.
using CollectionFragmentPtr [[maybe_unused]] = std::shared_ptr<CollectionFragment>;

/// \brief Definition for a ConnectionFragment containing a CollectionFragment.
using CollectionConnectionFragment [[maybe_unused]] = ConnectionFragment<CollectionFragment>;

/// \brief Definition for a pointer containing a CollectionConnectionFragment.
using CollectionConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<CollectionConnectionFragment>;

/// \brief A fragment for requesting properties of a Collection returned by the platform.
class ENJINPLATFORMSDK_EXPORT CollectionFragment : public IGraphQlFragment<CollectionFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionFragment(const CollectionFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionFragment(CollectionFragment&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionFragment() override;

    /// \brief Sets whether the collection is to be returned with its collectionId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithCollectionId(bool isIncluded = true);

    /// \brief Sets whether the collection is to be returned with its maxTokenCount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithMaxTokenCount(bool isIncluded = true);

    /// \brief Sets whether the collection is to be returned with its maxTokenSupply property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithMaxTokenSupply(bool isIncluded = true);

    /// \brief Sets whether the collection is to be returned with its forceSingleMint property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithForceSingleMint(bool isIncluded = true);

    /// \brief Sets whether the collection is to be returned with its frozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithFrozen(bool isIncluded = true);

    /// \brief Sets the royalty fragment to be used for getting the royalty property of the collection.
    /// \param fragment The royalty fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithRoyalty(RoyaltyFragmentPtr fragment);

    /// \brief Sets whether the collection is to be returned with its network property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithNetwork(bool isIncluded = true);

    /// \brief Sets the wallet fragment to be used for getting the owner property of the collection.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithOwner(WalletFragmentPtr fragment);

    /// \brief Sets the attribute fragment to be used for getting the attributes property of the collection.
    /// \param fragment The attribute fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithAttributes(AttributeFragmentPtr fragment);

    /// \brief Sets the connection fragment, which uses collection account, to be used for getting the accounts property
    /// of the collection.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithAccounts(CollectionAccountConnectionFragmentPtr fragment);

    /// \brief Sets the connection fragment, which uses token, to be used for getting the tokens property of the
    /// collection.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionFragment& WithTokens(TokenConnectionFragmentPtr fragment);

    CollectionFragment& operator=(const CollectionFragment& rhs);

    CollectionFragment& operator=(CollectionFragment&& rhs) noexcept;

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
    CollectionFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    CollectionFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    bool HasParameters() const override;

    [[maybe_unused]]
    CollectionFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    CollectionFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONFRAGMENT_HPP
