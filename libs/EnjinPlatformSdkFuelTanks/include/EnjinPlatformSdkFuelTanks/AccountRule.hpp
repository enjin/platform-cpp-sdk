#ifndef ENJINPLATFORMSDKFUELTANKS_ACCOUNTRULE_HPP
#define ENJINPLATFORMSDKFUELTANKS_ACCOUNTRULE_HPP

#include "enjinplatformsdkfueltanks_export.h"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Models account rules for a fuel tank.
class ENJINPLATFORMSDKFUELTANKS_EXPORT AccountRule : virtual public IJsonDeserializable
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountRule();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountRule(const AccountRule& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountRule(AccountRule&& other) noexcept;

    /// \brief Class destructor.
    ~AccountRule() override;

    /// \brief Returns the fuel tank rule.
    /// \return The rule.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetRule() const;

    /// \brief Returns the rule value.
    /// \return The value.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<JsonValue>& GetValue() const;

    AccountRule& operator=(const AccountRule& rhs);

    AccountRule& operator=(AccountRule&& rhs) noexcept;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_ACCOUNTRULE_HPP
