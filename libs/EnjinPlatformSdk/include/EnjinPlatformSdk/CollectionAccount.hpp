#ifndef ENJINPLATFORMSDK_COLLECTIONACCOUNT_HPP
#define ENJINPLATFORMSDK_COLLECTIONACCOUNT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/Collection.hpp"
#include "EnjinPlatformSdk/CollectionAccountApproval.hpp"
#include "EnjinPlatformSdk/Connection.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/Wallet.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <optional>
#include <vector>

namespace enjin::platform::sdk
{
// region Forward declarations

class Collection;

class CollectionAccountApproval;

class Wallet;

// endregion Forward declarations

/// \brief Models an account for a Collection.
class ENJINPLATFORMSDK_EXPORT CollectionAccount : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    CollectionAccount();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    CollectionAccount(const CollectionAccount& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    CollectionAccount(CollectionAccount&& other) noexcept;

    /// \brief Class destructor.
    ~CollectionAccount() override;

    /// \brief Returns the number of token accounts attached to this collection account.
    /// \return The number of token accounts.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetAccountCount() const;

    /// \brief Returns whether this collection account is frozen.
    /// \return Whether this collection account is frozen.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const;

    /// \brief Returns the collection this collection account belongs to.
    /// \return The collection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Collection>& GetCollection() const;

    /// \brief Returns the wallet which owns this collection account.
    /// \return The wallet.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<Wallet>& GetWallet() const;

    /// \brief Returns the list of approvals for this account.
    /// \return The list of approvals for this account.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<CollectionAccountApproval>>& GetApprovals() const;

    CollectionAccount& operator=(const CollectionAccount& rhs);

    CollectionAccount& operator=(CollectionAccount&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_COLLECTIONACCOUNT_HPP
