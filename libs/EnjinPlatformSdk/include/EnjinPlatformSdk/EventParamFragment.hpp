#ifndef ENJINPLATFORMSDK_EVENTPARAMFRAGMENT_HPP
#define ENJINPLATFORMSDK_EVENTPARAMFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class EventParamFragment;

/// \brief Definition for a pointer containing an EventParamFragment.
using EventParamFragmentPtr [[maybe_unused]] = std::shared_ptr<EventParamFragment>;

/// \brief Definition for a ConnectionFragment containing a EventParamFragment.
using EventParamConnectionFragment [[maybe_unused]] = ConnectionFragment<EventParamFragment>;

/// \brief Definition for a pointer containing an EventParamConnectionFragment.
using EventParamConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<EventParamConnectionFragment>;

/// \brief A fragment for requesting properties of an event parameter returned by the platform.
class ENJINPLATFORMSDK_EXPORT EventParamFragment : public IGraphQlFragment<EventParamFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    EventParamFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EventParamFragment(const EventParamFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EventParamFragment(EventParamFragment&& other) noexcept;

    /// \brief Class destructor.
    ~EventParamFragment() override;

    /// \brief Sets whether the event parameter is to be returned with its type property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventParamFragment& WithType(bool isIncluded = true);

    /// \brief Sets whether the event parameter is to be returned with its value property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EventParamFragment& WithValue(bool isIncluded = true);

    EventParamFragment& operator=(const EventParamFragment& rhs);

    EventParamFragment& operator=(EventParamFragment&& rhs) noexcept;

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
    EventParamFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    EventParamFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    EventParamFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    EventParamFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_EVENTPARAMFRAGMENT_HPP
