#ifndef ENJINPLATFORMSDK_SUBSTRATEEVENTS_HPP
#define ENJINPLATFORMSDK_SUBSTRATEEVENTS_HPP

#include "enjinplatformsdk_export.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Static class which contains members representing the name of each Substrate based event on the platform.
class ENJINPLATFORMSDK_EXPORT SubstrateEvents final
{
public:
    /// \brief The name of the event for when an account is created for a Collection.
    static inline const std::string CollectionAccountCreated = "platform:collection-account-created";

    /// \brief The name of the event for when an account is destroyed for a Collection.
    static inline const std::string CollectionAccountDestroyed = "platform:collection-account-destroyed";

    /// \brief The name of the event for when an account is frozen for a Collection.
    static inline const std::string CollectionAccountFrozen = "platform:collection-account-frozen";

    /// \brief The name of the event for when an account is thawed for a Collection.
    static inline const std::string CollectionAccountThawed = "platform:collection-account-thawed";

    /// \brief The name of the event for when a Collection is approved.
    static inline const std::string CollectionApproved = "platform:collection-approved";

    /// \brief The name of the event for when an Attribute is removed from a Collection.
    static inline const std::string CollectionAttributeRemoved = "platform:collection-attribute-removed";

    /// \brief The name of the event for when an Attribute is set for a Collection.
    static inline const std::string CollectionAttributeSet = "platform:collection-attribute-set";

    /// \brief The name of the event for when a Collection is created.
    static inline const std::string CollectionCreated = "platform:collection-created";

    /// \brief The name of the event for when a Collection is destroyed.
    static inline const std::string CollectionDestroyed = "platform:collection-destroyed";

    /// \brief The name of the event for when a Collection is frozen.
    static inline const std::string CollectionFrozen = "platform:collection-frozen";

    /// \brief The name of the event for when a Collection is mutated.
    static inline const std::string CollectionMutated = "platform:collection-mutated";

    /// \brief The name of the event for when a Collection is thawed.
    static inline const std::string CollectionThawed = "platform:collection-thawed";

    /// \brief The name of the event for when a Collection is unapproved.
    static inline const std::string CollectionUnapproved = "platform:collection-unapproved";

    /// \brief The name of the event for when an account is created for a Token.
    static inline const std::string TokenAccountCreated = "platform:token-account-created";

    /// \brief The name of the event for when an account is destroyed for a Token.
    static inline const std::string TokenAccountDestroyed = "platform:token-account-destroyed";

    /// \brief The name of the event for when an account is frozen for a Token.
    static inline const std::string TokenAccountFrozen = "platform:token-account-frozen";

    /// \brief The name of the event for when an account is thawed for a Token.
    static inline const std::string TokenAccountThawed = "platform:token-account-thawed";

    /// \brief The name of the event for when a Token is approved.
    static inline const std::string TokenApproved = "platform:token-approved";

    /// \brief The name of the event for when an Attribute is removed from a Token.
    static inline const std::string TokenAttributeRemoved = "platform:token-attribute-removed";

    /// \brief The name of the event for when an Attribute is set for a Token.
    static inline const std::string TokenAttributeSet = "platform:token-attribute-set";

    /// \brief The name of the event for when a Token is burned.
    static inline const std::string TokenBurned = "platform:token-burned";

    /// \brief The name of the event for when a Token is created.
    static inline const std::string TokenCreated = "platform:token-created";

    /// \brief The name of the event for when a Token is destroyed.
    static inline const std::string TokenDestroyed = "platform:token-destroyed";

    /// \brief The name of the event for when a Token is frozen.
    static inline const std::string TokenFrozen = "platform:token-frozen";

    /// \brief The name of the event for when a Token is minted.
    static inline const std::string TokenMinted = "platform:token-minted";

    /// \brief The name of the event for when a Token is mutated.
    static inline const std::string TokenMutated = "platform:token-mutated";

    /// \brief The name of the event for when a Token is thawed.
    static inline const std::string TokenThawed = "platform:token-thawed";

    /// \brief The name of the event for when a Token is transferred.
    static inline const std::string TokenTransferred = "platform:token-transferred";

    /// \brief The name of the event for when a Token is unapproved.
    static inline const std::string TokenUnapproved = "platform:token-unapproved";

    SubstrateEvents() = delete;

    /// \brief Class destructor.
    ~SubstrateEvents();
};
}

#endif //ENJINPLATFORMSDK_SUBSTRATEEVENTS_HPP
