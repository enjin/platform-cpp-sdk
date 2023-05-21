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

#ifndef ENJINPLATFORMSDK_BURNPARAMSINPUT_HPP
#define ENJINPLATFORMSDK_BURNPARAMSINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class BurnParamsInput;

/// \brief Definition for a pointer containing a burn parameter input.
using BurnParamsInputPtr [[maybe_unused]] = std::shared_ptr<BurnParamsInput>;

class ENJINPLATFORMSDK_EXPORT BurnParamsInput : public GraphQlParameter<BurnParamsInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    BurnParamsInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    BurnParamsInput(const BurnParamsInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    BurnParamsInput(BurnParamsInput&& other) noexcept;

    /// \brief Class destructor.
    ~BurnParamsInput() override;

    /// \brief Sets the amount to transfer.
    /// \param amount The amount to transfer.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    BurnParamsInput& SetAmount(SerializableStringPtr amount);

    /// \brief Sets whether the transaction will be kept from failing if the balance drops below the minimum requirement.
    /// \param keepAlive Whether the transaction will be kept from failing.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    BurnParamsInput& SetKeepAlive(SerializableBoolPtr keepAlive);

    /// \brief Sets whether the token storage will be removed if no tokens are left.
    /// \param removeTokenStorage Whether the token storage will be removed.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    BurnParamsInput& SetRemoveTokenStorage(SerializableBoolPtr removeTokenStorage);

    BurnParamsInput& operator=(const BurnParamsInput& rhs);

    BurnParamsInput& operator=(BurnParamsInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_BURNPARAMSINPUT_HPP
