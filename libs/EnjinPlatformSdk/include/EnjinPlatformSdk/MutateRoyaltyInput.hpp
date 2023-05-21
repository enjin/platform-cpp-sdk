//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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

/// \brief Definition for a pointer containing a mutate royalty input.
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