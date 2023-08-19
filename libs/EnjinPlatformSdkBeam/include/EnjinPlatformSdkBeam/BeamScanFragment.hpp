#ifndef ENJINPLATFORMSDKBEAM_BEAMSCANFRAGMENT_HPP
#define ENJINPLATFORMSDKBEAM_BEAMSCANFRAGMENT_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
class BeamScanFragment;

/// \brief Definition for a pointer containing a BeamScanFragment.
using BeamScanFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamScanFragment>;

/// \brief Definition for a ConnectionFragment containing a BeamScanFragment.
using BeamScanConnectionFragment [[maybe_unused]] = ConnectionFragment<BeamScanFragment>;

/// \brief Definition for a pointer containing a BeamScanConnectionFragment.
using BeamScanConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamScanConnectionFragment>;

/// \brief A fragment for requesting properties of a BeamScan returned by the platform.
class ENJINPLATFORMSDKBEAM_EXPORT BeamScanFragment : public virtual IGraphQlFragment<BeamScanFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamScanFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamScanFragment(const BeamScanFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamScanFragment(BeamScanFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BeamScanFragment() override;

    /// \brief Sets whether the BeamScan is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamScanFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the BeamScan is to be returned with its walletPublicKey property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamScanFragment& WithWalletPublicKey(bool isIncluded = true);

    /// \brief Sets whether the BeamScan is to be returned with its message property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamScanFragment& WithMessage(bool isIncluded = true);

    BeamScanFragment& operator=(const BeamScanFragment& rhs);

    BeamScanFragment& operator=(BeamScanFragment&& rhs) noexcept;

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
    BeamScanFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BeamScanFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    BeamScanFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BeamScanFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMSCANFRAGMENT_HPP
