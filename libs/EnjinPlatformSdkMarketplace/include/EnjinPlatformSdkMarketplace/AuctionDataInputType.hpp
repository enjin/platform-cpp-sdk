#ifndef ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAINPUTTYPE_HPP
#define ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAINPUTTYPE_HPP

#include "enjinplatformsdkmarketplace_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlParameterORDViolation.hpp"

#endif

namespace enjin::platform::sdk::marketplace
{
class AuctionDataInputType;

/// \brief Definition for a pointer containing an AuctionDataInputType.
using AuctionDataInputTypePtr [[maybe_unused]] = std::shared_ptr<AuctionDataInputType>;

/// \brief Models a parameter for data for an auction.
class ENJINPLATFORMSDKMARKETPLACE_EXPORT AuctionDataInputType : public GraphQlParameter<AuctionDataInputType>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AuctionDataInputType();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AuctionDataInputType(const AuctionDataInputType& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AuctionDataInputType(AuctionDataInputType&& other) noexcept;

    /// \brief Class destructor.
    ~AuctionDataInputType() override;

    /// \brief Sets the block number the auction starts at.
    /// \param startBlock The block.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AuctionDataInputType& SetStartBlock(SerializableIntPtr startBlock);

    /// \brief Sets the block number the auction ends at.
    /// \param endBlock The block.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    AuctionDataInputType& SetEndBlock(SerializableIntPtr endBlock);

    AuctionDataInputType& operator=(const AuctionDataInputType& rhs);

    AuctionDataInputType& operator=(AuctionDataInputType&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_AUCTIONDATAINPUTTYPE_HPP
