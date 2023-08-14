#ifndef ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAFRAGMENT_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdkMarketplace/ListingDataFragment.hpp"
#include <memory>

namespace enjin::platform::sdk::marketplace
{
class AuctionDataFragment;

/// \brief Definition for a pointer containing an AuctionDataFragment.
using AuctionDataFragmentPtr [[maybe_unused]] = std::shared_ptr<AuctionDataFragment>;

/// \brief Definition for a ConnectionFragment containing an AuctionDataFragment.
using AuctionDataConnectionFragment [[maybe_unused]] = ConnectionFragment<AuctionDataFragment>;

/// \brief Definition for a pointer containing an AuctionDataConnectionFragment.
using AuctionDataConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AuctionDataConnectionFragment>;

/// \brief A fragment for requesting properties of an AuctionData returned by the platform.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AuctionDataFragment : public ListingDataFragment<AuctionDataFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AuctionDataFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AuctionDataFragment(const AuctionDataFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AuctionDataFragment(AuctionDataFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AuctionDataFragment() override;

    /// \brief Sets whether the AuctionData is to be returned with its type property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AuctionDataFragment& WithType(bool isIncluded = true);

    /// \brief Sets whether the AuctionData is to be returned with its startBlock property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AuctionDataFragment& WithStartBlock(bool isIncluded = true);

    /// \brief Sets whether the AuctionData is to be returned with its endBlock property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AuctionDataFragment& WithEndBlock(bool isIncluded = true);

    AuctionDataFragment& operator=(const AuctionDataFragment& rhs);

    AuctionDataFragment& operator=(AuctionDataFragment&& rhs) noexcept;

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
    AuctionDataFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AuctionDataFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    AuctionDataFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AuctionDataFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAFRAGMENT_HPP
