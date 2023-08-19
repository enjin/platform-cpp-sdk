#ifndef ENJINPLATFORMSDK_TRANSACTIONFRAGMENT_HPP
#define ENJINPLATFORMSDK_TRANSACTIONFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/EventFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/WalletFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
// region Forward declarations

class EventFragment;

using EventConnectionFragment = ConnectionFragment<EventFragment>;
using EventConnectionFragmentPtr = std::shared_ptr<EventConnectionFragment>;

class WalletFragment;

using WalletFragmentPtr = std::shared_ptr<WalletFragment>;

// endregion Forward declarations

class TransactionFragment;

/// \brief Definition for a pointer containing a TransactionFragment.
using TransactionFragmentPtr [[maybe_unused]] = std::shared_ptr<TransactionFragment>;

/// \brief Definition for a ConnectionFragment containing a TransactionFragment.
using TransactionConnectionFragment [[maybe_unused]] = ConnectionFragment<TransactionFragment>;

/// \brief Definition for a pointer containing a TransactionConnectionFragment.
using TransactionConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<TransactionConnectionFragment>;

/// \brief A fragment for requesting properties of a transaction returned by the platform.
class ENJINPLATFORMSDK_EXPORT TransactionFragment : public IGraphQlFragment<TransactionFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TransactionFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TransactionFragment(const TransactionFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TransactionFragment(TransactionFragment&& other) noexcept;

    /// \brief Class destructor.
    ~TransactionFragment() override;

    /// \brief Sets whether the transaction is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the transaction is to be returned with its transactionId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithTransactionId(bool isIncluded = true);

    /// \brief Sets whether the transaction is to be returned with its method property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithMethod(bool isIncluded = true);

    /// \brief Sets whether the transaction is to be returned with its state property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithState(bool isIncluded = true);

    /// \brief Sets whether the transaction is to be returned with its result property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithResult(bool isIncluded = true);

    /// \brief Sets whether the transaction is to be returned with its encodedData property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithEncodedData(bool isIncluded = true);

    /// \brief Sets the wallet fragment to be used for getting the wallet property of the transaction.
    /// \param fragment The wallet fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithWallet(WalletFragmentPtr fragment);

    /// \brief Sets whether the transaction is to be returned with its idempotencyKey property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithIdempotencyKey(bool isIncluded = true);

    /// \brief Sets the connection fragment, to be used for getting the events property of the transaction.
    /// \param fragment The connection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TransactionFragment& WithEvents(EventConnectionFragmentPtr fragment);

    TransactionFragment& operator=(const TransactionFragment& rhs);

    TransactionFragment& operator=(TransactionFragment&& rhs) noexcept;

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
    TransactionFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    TransactionFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    TransactionFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    TransactionFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_TRANSACTIONFRAGMENT_HPP
