#ifndef ENJINPLATFORMSDK_GETBLOCKS_HPP
#define ENJINPLATFORMSDK_GETBLOCKS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/BlockFragment.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of blocks optionally filtered by blockchain transaction IDs or blockchain
/// transaction hashes.
class ENJINPLATFORMSDK_EXPORT GetBlocks : public GraphQlRequest<GetBlocks, BlockConnectionFragment>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetBlocks();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetBlocks(const GetBlocks& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetBlocks(GetBlocks&& other) noexcept;

    /// \brief Class destructor.
    ~GetBlocks() override;

    /// \brief Sets the blockchain transaction IDs to filter to.
    /// \param numbers The transaction IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBlocks& SetNumber(SerializableStringArrayPtr numbers);

    /// \brief Sets the blockchain transaction hashes to filter to.
    /// \param hashes The transaction hashes.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetBlocks& SetHashes(SerializableStringArrayPtr hashes);

    GetBlocks& operator=(const GetBlocks& rhs);

    GetBlocks& operator=(GetBlocks&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETBLOCKS_HPP
