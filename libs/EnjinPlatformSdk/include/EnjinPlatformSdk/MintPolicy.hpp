#ifndef ENJINPLATFORMSDK_MINTPOLICY_HPP
#define ENJINPLATFORMSDK_MINTPOLICY_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MintPolicy;

/// \brief Definition for a pointer containing a mint policy.
using MintPolicyPtr [[maybe_unused]] = std::shared_ptr<MintPolicy>;

/// \brief Models the parameter for the mint policy for a new collection.
class ENJINPLATFORMSDK_EXPORT MintPolicy : public GraphQlParameter<MintPolicy>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MintPolicy();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MintPolicy(const MintPolicy& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MintPolicy(MintPolicy&& other) noexcept;

    /// \brief Class destructor.
    ~MintPolicy() override;

    /// \brief Sets the maximum number of tokens that can be issued for the collection.
    /// \param maxTokenCount The maximum number of tokens.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintPolicy& SetMaxTokenCount(SerializableStringPtr maxTokenCount);

    /// \brief Sets the maximum amount of each token in the collection that can be minted.
    /// \param maxTokenSupply The maximum amount per token.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintPolicy& SetMaxTokenSupply(SerializableStringPtr maxTokenSupply);

    /// \brief Set whether the tokens in the collection will be minted as single mint types. This would indicate the
    /// tokens in the collection are non-fungible tokens (NFTs).
    /// \param forceSingleMint Whether the tokens are non-fungible.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MintPolicy& SetForceSingleMint(SerializableBoolPtr forceSingleMint);

    MintPolicy& operator=(const MintPolicy& rhs);

    MintPolicy& operator=(MintPolicy&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MINTPOLICY_HPP
