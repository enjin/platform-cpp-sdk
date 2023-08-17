#ifndef ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVEFRAGMENT_HPP
#define ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVEFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TokenAccountNamedReserveFragment;

/// \brief Definition for a pointer containing a token account named reserve fragment.
using TokenAccountNamedReserveFragmentPtr [[maybe_unused]] = std::shared_ptr<TokenAccountNamedReserveFragment>;

/// \brief Definition for a token account named reserve connection fragment.
using TokenAccountNamedReserveConnectionFragment [[maybe_unused]] =
    ConnectionFragment<TokenAccountNamedReserveFragment>;

/// \brief Definition for a pointer containing a token account named reserve connection fragment.
using TokenAccountNamedReserveConnectionFragmentPtr [[maybe_unused]] =
    std::shared_ptr<TokenAccountNamedReserveConnectionFragment>;

/// \brief A fragment for requesting properties of a token account named reserve returned by the platform.
class ENJINPLATFORMSDK_EXPORT TokenAccountNamedReserveFragment
    : public IGraphQlFragment<TokenAccountNamedReserveFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TokenAccountNamedReserveFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TokenAccountNamedReserveFragment(const TokenAccountNamedReserveFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TokenAccountNamedReserveFragment(TokenAccountNamedReserveFragment&& other) noexcept;

    /// \brief Class destructor.
    ~TokenAccountNamedReserveFragment() override;

    /// \brief Sets whether the token account named reserve is to be returned with its pallet property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountNamedReserveFragment& WalletPallet(bool isIncluded = true);

    /// \brief Sets whether the token account named reserve is to be returned with its amount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TokenAccountNamedReserveFragment& WalletAmount(bool isIncluded = true);

    TokenAccountNamedReserveFragment& operator=(const TokenAccountNamedReserveFragment& rhs);

    TokenAccountNamedReserveFragment& operator=(TokenAccountNamedReserveFragment&& rhs) noexcept;

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
    TokenAccountNamedReserveFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    TokenAccountNamedReserveFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    TokenAccountNamedReserveFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    TokenAccountNamedReserveFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_TOKENACCOUNTNAMEDRESERVEFRAGMENT_HPP
