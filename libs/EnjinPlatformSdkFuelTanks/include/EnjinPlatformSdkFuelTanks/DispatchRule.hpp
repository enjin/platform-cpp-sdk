#ifndef ENJINPLATFORMSDKFUELTANKS_DISPATCHRULE_HPP
#define ENJINPLATFORMSDKFUELTANKS_DISPATCHRULE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief The dispatch rules for a fuel tank.
class DispatchRule : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    DispatchRule();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    DispatchRule(const DispatchRule& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    DispatchRule(DispatchRule&& other) noexcept;

    /// \brief Class destructor.
    ~DispatchRule() override;

    /// \brief Returns the fuel tank rule.
    /// \return The rule.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetRule() const;

    /// \brief Returns the rule set ID.
    /// \return The ID.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int>& GetRuleSetId() const;

    /// \brief Returns the rule value.
    /// \return The value.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetValue() const;

    /// \brief Returns whether the dispatch is frozen.
    /// \return Whether the dispatch is frozen.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<bool>& GetIsFrozen() const;

    DispatchRule& operator=(const DispatchRule& rhs);

    DispatchRule& operator=(DispatchRule&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_DISPATCHRULE_HPP
