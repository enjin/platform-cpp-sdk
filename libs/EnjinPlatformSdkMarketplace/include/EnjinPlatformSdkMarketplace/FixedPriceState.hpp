#ifndef ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdkMarketplace/ListingState.hpp"
#include "EnjinPlatformSdkMarketplace/ListingType.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::marketplace
{
/// \brief Models the state of a fixed price listing.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT FixedPriceState : public ListingState
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FixedPriceState();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FixedPriceState(const FixedPriceState& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FixedPriceState(FixedPriceState&& other) noexcept;

    /// \brief Class destructor.
    ~FixedPriceState() override;

    /// \brief Returns the type of the listing.
    /// \return The type.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<ListingType>& GetType() const;

    /// \brief Returns the amount of the listing that has been filled.
    /// \return The amount filled.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetAmountFilled() const;

    FixedPriceState& operator=(const FixedPriceState& rhs);

    FixedPriceState& operator=(FixedPriceState&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_FIXEDPRICESTATE_HPP
