#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKFRAGMENT_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKFRAGMENT_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlFragmentORDViolation.hpp"

#endif

namespace enjin::platform::sdk::fuelTanks
{
class FuelTankFragment;

/// \brief Definition for a pointer containing a FuelTankFragment.
using FuelTankFragmentPtr [[maybe_unused]] = std::shared_ptr<FuelTankFragment>;

/// \brief Definition for a ConnectionFragment containing a FuelTankFragment.
using FuelTankConnectionFragment [[maybe_unused]] = ConnectionFragment<FuelTankFragment>;

/// \brief Definition for a pointer containing a FuelTankConnectionFragment.
using FuelTankConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<FuelTankConnectionFragment>;

/// \brief A fragment for requesting properties of a FuelTank returned by the platform.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTankFragment : public virtual IGraphQlFragment<FuelTankFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FuelTankFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    FuelTankFragment(const FuelTankFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    FuelTankFragment(FuelTankFragment&& other) noexcept;

    /// \brief Class destructor.
    ~FuelTankFragment() override;

    /// \brief Sets whether the FuelTank is to be returned with its name property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    FuelTankFragment& WithName(bool isIncluded = true);

    /// \brief Sets whether the FuelTank is to be returned with its tankId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    FuelTankFragment& WithTankId(bool isIncluded = true);

    FuelTankFragment& operator=(const FuelTankFragment& rhs);

    FuelTankFragment& operator=(FuelTankFragment&& rhs) noexcept;

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
    FuelTankFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    FuelTankFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    FuelTankFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    FuelTankFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKFRAGMENT_HPP
