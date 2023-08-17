#ifndef ENJINPLATFORMSDK_TOKENFRAGMENT_HPP
#define ENJINPLATFORMSDK_TOKENFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/AttributeFragment.hpp"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/RoyaltyFragment.hpp"
#include "EnjinPlatformSdk/TokenAccountFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class AttributeFragment;

using AttributeFragmentPtr = std::shared_ptr<AttributeFragment>;

class CollectionFragment;

using CollectionFragmentPtr = std::shared_ptr<CollectionFragment>;

class RoyaltyFragment;

using RoyaltyFragmentPtr = std::shared_ptr<RoyaltyFragment>;

class TokenAccountFragment;

using TokenAccountConnectionFragment = ConnectionFragment<TokenAccountFragment>;
using TokenAccountConnectionFragmentPtr = std::shared_ptr<TokenAccountConnectionFragment>;

// endregion Forward declarations

class TokenFragment;

/// \brief Definition for a pointer containing a token fragment.
using TokenFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenFragment>;

/// \brief Definition for a token connection fragment.
using TokenConnectionFragment [[maybe_unused]] = ConnectionFragment<TokenFragment>;

/// \brief Definition for a pointer containing a token connection fragment.
using TokenConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenConnectionFragment>;

/// \brief A fragment for requesting properties of a token returned by the platform.
class ENJINPLATFORMSDK_EXPORT TokenFragment : public IGraphQlFragment<TokenFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenFragment(const TokenFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenFragment(TokenFragment&& other) noexcept;

    /// \brief Class destructor.
    ~TokenFragment() override;

    /// \brief Sets whether the token is to be returned with its tokenId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithTokenId(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its supply property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithSupply(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its cap property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithCap(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its capSupply property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithCapSupply(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its isFrozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithIsFrozen(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its isCurrency property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithIsCurrency(bool isIncluded = true);

    /// \brief Sets the royalty fragment to be used for getting the royalty property of the token.
    /// \param fragment The royalty fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithRoyalty(RoyaltyFragmentPtr fragment);

    /// \brief Sets whether the token is to be returned with its minimumBalance property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithMinimumBalance(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its unitPrice property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithUnitPrice(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its mintDeposit property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithMintDeposit(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its attributeCount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithAttributeCount(bool isIncluded = true);

    /// \brief Sets the collection fragment to be used for getting the collection property of token.
    /// \param fragment The collection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithCollection(CollectionFragmentPtr fragment);

    /// \brief Sets the attribute fragment to be used for getting the attributes property of the token.
    /// \param fragment The attribute fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithAttributes(AttributeFragmentPtr fragment);

    /// \brief Sets the connection fragment to be used for getting the accounts property of the token.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithAccounts(TokenAccountConnectionFragmentPtr fragment);

    /// \brief Sets whether the token is to be returned with its metadata property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithMetadata(bool isIncluded = true);

    /// \brief Sets whether the token is to be returned with its nonFungible property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenFragment& WithNonFungible(bool isIncluded = true);

    TokenFragment& operator=(const TokenFragment& rhs);

    TokenFragment& operator=(TokenFragment&& rhs) noexcept;

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
    TokenFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    TokenFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    TokenFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    TokenFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_TOKENFRAGMENT_HPP
