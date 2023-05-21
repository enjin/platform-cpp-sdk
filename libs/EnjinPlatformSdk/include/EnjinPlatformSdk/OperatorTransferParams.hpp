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

#ifndef ENJINPLATFORMSDK_OPERATORTRANSFERPARAMS_HPP
#define ENJINPLATFORMSDK_OPERATORTRANSFERPARAMS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class OperatorTransferParams;

/// \brief Definition for a pointer containing an operator transfer parameters.
using OperatorTransferParamsPtr [[maybe_unused]] = std::shared_ptr<OperatorTransferParams>;

/// \brief Models a parameter for parameters to make an operator transfer.
/// \remarks Operator transfers are transfers that you make using tokens from somebody else's wallet as the source. To
/// make this type of transfer the source wallet owner must approve you for transferring their tokens.
class ENJINPLATFORMSDK_EXPORT OperatorTransferParams : public GraphQlParameter<OperatorTransferParams>,
                                                       public HasEncodableTokenId<OperatorTransferParams>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    OperatorTransferParams();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    OperatorTransferParams(const OperatorTransferParams& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    OperatorTransferParams(OperatorTransferParams&& other) noexcept;

    /// \brief Class destructor.
    ~OperatorTransferParams() override;

    /// \brief Sets the source account of the token.
    /// \param source The source account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    OperatorTransferParams& SetSource(SerializableStringPtr source);

    /// \brief Sets the amount to transfer.
    /// \param amount The amount.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    OperatorTransferParams& SetAmount(SerializableStringPtr amount);

    /// \brief Sets whether the transaction will be kept from failing if the balance drops below the minimum
    /// requirement.
    /// \param keepAlive Whether the transaction will be kept from failing.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    OperatorTransferParams& SetKeepAlive(SerializableBoolPtr keepAlive);

    OperatorTransferParams& operator=(const OperatorTransferParams& rhs);

    OperatorTransferParams& operator=(OperatorTransferParams&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_OPERATORTRANSFERPARAMS_HPP
