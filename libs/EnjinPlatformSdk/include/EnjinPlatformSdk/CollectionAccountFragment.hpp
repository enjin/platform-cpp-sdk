#ifndef ENJINPLATFORMSDK_COLLECTIONACCOUNTFRAGMENT_HPP
#define ENJINPLATFORMSDK_COLLECTIONACCOUNTFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionAccountApprovalFragment.hpp"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class CollectionAccountApprovalFragment;

using CollectionAccountApprovalFragmentPtr = std::shared_ptr<CollectionAccountApprovalFragment>;

class CollectionFragment;

using CollectionFragmentPtr = std::shared_ptr<CollectionFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class CollectionAccountFragment;

/// \brief Definition for a pointer containing a CollectionAccountFragment.
using CollectionAccountFragmentPtr [[maybe_unused]] = std::shared_ptr<CollectionAccountFragment>;

/// \brief Definition for a ConnectionFragment containing a CollectionAccountFragment.
using CollectionAccountConnectionFragment [[maybe_unused]] = ConnectionFragment<CollectionAccountFragment>;

/// \brief Definition for a pointer containing a CollectionAccountConnectionFragment.
using CollectionAccountConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<CollectionAccountConnectionFragment>;

/// \brief A fragment for requesting properties of a collection account returned by the platform.
class ENJINPLATFORMSDK_EXPORT CollectionAccountFragment : public IGraphQlFragment<CollectionAccountFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionAccountFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionAccountFragment(const CollectionAccountFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionAccountFragment(CollectionAccountFragment&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionAccountFragment() override;

    /// \brief Sets whether the collection account is to be returned with its accountCount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountFragment& WithAccountCount(bool isIncluded = true);

    /// \brief Sets whether the collection account is to be returned with its isFrozen property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountFragment& WithIsFrozen(bool isIncluded = true);

    /// \brief Sets the collection fragment to be used for getting the collection property of the collection account.
    /// \param fragment The collection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountFragment& WithCollection(CollectionFragmentPtr fragment);

    /// \brief Sets the wallet fragment to be used for getting the wallet collection account.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountFragment& WithWallet(WalletFragmentPtr fragment);

    /// \brief Sets the collection account approval fragment to be used for getting the approvals property of the
    /// collection account.
    /// \param fragment The collection account approval fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountFragment& WithApprovals(CollectionAccountApprovalFragmentPtr fragment);

    CollectionAccountFragment& operator=(const CollectionAccountFragment& rhs);

    CollectionAccountFragment& operator=(CollectionAccountFragment&& rhs) noexcept;

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
    CollectionAccountFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    CollectionAccountFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    CollectionAccountFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    CollectionAccountFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONACCOUNTFRAGMENT_HPP
