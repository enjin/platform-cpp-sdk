#ifndef ENJINPLATFORMSDK_MUTATEROYALTYINPUT_HPP
#define ENJINPLATFORMSDK_MUTATEROYALTYINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableDouble.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MutateRoyaltyInput;

/// \brief Definition for a pointer containing a MutateRoyaltyInput.
using MutateRoyaltyInputPtr [[maybe_unused]] = std::shared_ptr<MutateRoyaltyInput>;

/// \brief Models a parameter for mutating the royalty for a new collection or token.
class ENJINPLATFORMSDK_EXPORT MutateRoyaltyInput : public GraphQlParameter<MutateRoyaltyInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MutateRoyaltyInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MutateRoyaltyInput(const MutateRoyaltyInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MutateRoyaltyInput(MutateRoyaltyInput&& other) noexcept;

    /// \brief Class destructor.
    ~MutateRoyaltyInput() override;

    /// \brief Sets the account that will receive the royalty.
    /// \param beneficiary The beneficiary account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MutateRoyaltyInput& SetBeneficiary(SerializableStringPtr beneficiary);

    /// \brief Sets the amount of royalty the beneficiary receives in percentage.
    /// \param percentage The amount as a percentage.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MutateRoyaltyInput& SetPercentage(SerializableDoublePtr percentage);

    MutateRoyaltyInput& operator=(const MutateRoyaltyInput& rhs);

    MutateRoyaltyInput& operator=(MutateRoyaltyInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MUTATEROYALTYINPUT_HPP
