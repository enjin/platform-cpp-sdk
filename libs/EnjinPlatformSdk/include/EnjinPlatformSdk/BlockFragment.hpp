#ifndef ENJINPLATFORMSDK_BLOCKFRAGMENT_HPP
#define ENJINPLATFORMSDK_BLOCKFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class BlockFragment;

/// \brief Definition for a pointer containing a BlockFragment.
using BlockFragmentPtr [[maybe_unused]] = std::shared_ptr<BlockFragment>;

/// \brief Definition for a ConnectionFragment containing a BlockFragment.
using BlockConnectionFragment [[maybe_unused]] = ConnectionFragment<BlockFragment>;

/// \brief Definition for a pointer containing a BlockConnectionFragment.
using BlockConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BlockConnectionFragment>;

/// \brief A fragment for requesting properties of a block returned by the platform.
class ENJINPLATFORMSDK_EXPORT BlockFragment : public IGraphQlFragment<BlockFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BlockFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BlockFragment(const BlockFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BlockFragment(BlockFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BlockFragment() override;

    /// \brief Sets whether the block is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the block is to be returned with its number property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithNumber(bool isIncluded = true);

    /// \brief Sets whether the block is to be returned with its hash property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithHash(bool isIncluded = true);

    /// \brief Sets whether the block is to be returned with its synced property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithSynced(bool isIncluded = true);

    /// \brief Sets whether the block is to be returned with its failed property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithFailed(bool isIncluded = true);

    /// \brief Sets whether the block is to be returned with its exception property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BlockFragment& WithException(bool isIncluded = true);

    BlockFragment& operator=(const BlockFragment& rhs);

    BlockFragment& operator=(BlockFragment&& rhs) noexcept;

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
    BlockFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BlockFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    BlockFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BlockFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_BLOCKFRAGMENT_HPP
