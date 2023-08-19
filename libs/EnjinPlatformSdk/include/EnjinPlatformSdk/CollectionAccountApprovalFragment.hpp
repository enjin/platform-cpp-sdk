#ifndef ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVALFRAGMENT_HPP
#define ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVALFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionAccountFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class CollectionAccountFragment;

using CollectionAccountFragmentPtr = std::shared_ptr<CollectionAccountFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class CollectionAccountApprovalFragment;

/// \brief Definition for a pointer containing a CollectionAccountApprovalFragment.
using CollectionAccountApprovalFragmentPtr [[maybe_unused]] = std::shared_ptr<CollectionAccountApprovalFragment>;

/// \brief Definition for a ConnectionFragment containing a CollectionAccountApprovalFragment.
using CollectionAccountApprovalConnectionFragment [[maybe_unused]] =
    ConnectionFragment<CollectionAccountApprovalFragment>;

/// \brief Definition for a pointer containing a CollectionAccountApprovalConnectionFragment.
using CollectionAccountApprovalConnectionFragmentPtr [[maybe_unused]] =
    std::shared_ptr<CollectionAccountApprovalConnectionFragment>;

/// \brief A fragment for requesting properties of a collection account approval returned by the platform.
class ENJINPLATFORMSDK_EXPORT CollectionAccountApprovalFragment
    : public IGraphQlFragment<CollectionAccountApprovalFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionAccountApprovalFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionAccountApprovalFragment(const CollectionAccountApprovalFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionAccountApprovalFragment(CollectionAccountApprovalFragment&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionAccountApprovalFragment() override;

    /// \brief Sets whether the collection account approval is to be returned with its expiration property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountApprovalFragment& WithExpiration(bool isIncluded = true);

    /// \brief Sets the collection account fragment to be used for getting the account property of the collection
    /// account approval.
    /// \param fragment The collection account fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountApprovalFragment& WithAccount(CollectionAccountFragmentPtr fragment);

    /// \brief Sets the wallet fragment to be used for getting the wallet property of the collection account approval.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    CollectionAccountApprovalFragment& WithWallet(WalletFragmentPtr fragment);

    CollectionAccountApprovalFragment& operator=(const CollectionAccountApprovalFragment& rhs);

    CollectionAccountApprovalFragment& operator=(CollectionAccountApprovalFragment&& rhs) noexcept;

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
    CollectionAccountApprovalFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    CollectionAccountApprovalFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    CollectionAccountApprovalFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    CollectionAccountApprovalFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONACCOUNTAPPROVALFRAGMENT_HPP
