#ifndef ENJINPLATFORMSDK_MARKETPOLICY_HPP
#define ENJINPLATFORMSDK_MARKETPOLICY_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/RoyaltyInput.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MarketPolicy;

/// \brief Definition for a pointer containing a MarketPolicy.
using MarketPolicyPtr [[maybe_unused]] = std::shared_ptr<MarketPolicy>;

/// \brief Models a parameter for the marketplace policy of a collection.
class ENJINPLATFORMSDK_EXPORT MarketPolicy : public GraphQlParameter<MarketPolicy>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MarketPolicy();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MarketPolicy(const MarketPolicy& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MarketPolicy(MarketPolicy&& other) noexcept;

    /// \brief Class destructor.
    ~MarketPolicy() override;

    /// \brief Sets the royalty for this marketplace policy.
    /// \param royalty The royalty.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MarketPolicy& SetRoyalty(RoyaltyInputPtr royalty);

    MarketPolicy& operator=(const MarketPolicy& rhs);

    MarketPolicy& operator=(MarketPolicy&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MARKETPOLICY_HPP
