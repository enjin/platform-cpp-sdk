#ifndef ENJINPLATFORMSDKBEAM_BEAMFRAGMENT_HPP
#define ENJINPLATFORMSDKBEAM_BEAMFRAGMENT_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/CollectionFragment.hpp"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdkBeam/BeamQrFragment.hpp"
#include "EnjinPlatformSdkBeam/BeamScanFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
// region Forward declarations

class BeamQrFragment;

using BeamQrFragmentPtr = std::shared_ptr<BeamQrFragment>;

class BeamScanFragment;

using BeamScanFragmentPtr = std::shared_ptr<BeamScanFragment>;

// endregion Forward declarations

class BeamFragment;

/// \brief Definition for a pointer containing a beam fragment.
using BeamFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamFragment>;

/// \brief Definition for a beam connection fragment.
using BeamConnectionFragment [[maybe_unused]] = ConnectionFragment<BeamFragment>;

/// \brief Definition for a pointer containing a beam connection fragment.
using BeamConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<BeamConnectionFragment>;

/// \brief A fragment for requesting properties of a Beam returned by the platform.
class ENJINPLATFORMSDKBEAM_EXPORT BeamFragment : public IGraphQlFragment<BeamFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BeamFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BeamFragment(const BeamFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BeamFragment(BeamFragment&& other) noexcept;

    /// \brief Class destructor.
    ~BeamFragment() override;

    /// \brief Sets whether the Beam is to be returned with its id property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithId(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its code property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithCode(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its name property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithName(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its description property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithDescription(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its imagine property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithImage(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its start property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithStart(bool isIncluded = true);

    /// \brief Sets whether the Beam is to be returned with its end property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithEnd(bool isIncluded = true);

    /// \brief Sets the Collection fragment to be used for getting the collection property of the Beam.
    /// \param fragment The Collection fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithCollection(CollectionFragmentPtr fragment);

    /// \brief Sets the BeamScan fragment to be used for getting the message property of the Beam.
    /// \param fragment The BeamScan fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithMessage(BeamScanFragmentPtr fragment);

    /// \brief Sets whether the Beam is to be returned with its flags property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithFlags(bool isIncluded = true);

    /// \brief Sets the BeamQr fragment to be used for getting the qr property of the Beam.
    /// \param fragment The BeamQr fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    BeamFragment& WithQr(BeamQrFragmentPtr fragment);

    BeamFragment& operator=(const BeamFragment& rhs);

    BeamFragment& operator=(BeamFragment&& rhs) noexcept;

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
    BeamFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    BeamFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    BeamFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    BeamFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKBEAM_BEAMFRAGMENT_HPP
