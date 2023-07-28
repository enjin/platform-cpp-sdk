#ifndef ENJINPLATFORMSDKBEAM_BEAMQRFRAGMENT_HPP
#define ENJINPLATFORMSDKBEAM_BEAMQRFRAGMENT_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
class BeamQrFragment;

/// \brief Definition for a pointer containing a beam QR fragment.
using BeamQrFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamQrFragment>;

/// \brief Definition for a beam QR connection fragment.
using BeamQrConnectionFragment [[maybe_unused]] = ConnectionFragment<BeamQrFragment>;

/// \brief Definition for a pointer containing a beam QR connection fragment.
using BeamQrConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamQrConnectionFragment>;

/// \brief A fragment for requesting properties of a BeamQr returned by the platform.
class BeamQrFragment : public IGraphQlFragment<BeamQrFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamQrFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamQrFragment(const BeamQrFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamQrFragment(BeamQrFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BeamQrFragment() override;

    /// \brief Sets whether the BeamQr is to be returned with its url property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamQrFragment& WithUrl(bool isIncluded = true);

    /// \brief Sets whether the BeamQr is to be returned with its payload property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamQrFragment& WithPayload(bool isIncluded = true);

    BeamQrFragment& operator=(const BeamQrFragment& rhs);

    BeamQrFragment& operator=(BeamQrFragment&& rhs) noexcept;

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
    BeamQrFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BeamQrFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    BeamQrFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BeamQrFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMQRFRAGMENT_HPP
