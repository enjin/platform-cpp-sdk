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

#ifndef ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP
#define ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/OperatorTransferParams.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/SimpleTransferParams.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TransferRecipient;

/// \brief Definition for a pointer containing an attribute input.
using TransferRecipientPtr [[maybe_unused]] = std::shared_ptr<TransferRecipient>;

class ENJINPLATFORMSDK_EXPORT TransferRecipient : public GraphQlParameter<TransferRecipient>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TransferRecipient();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TransferRecipient(const TransferRecipient& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TransferRecipient(TransferRecipient&& other) noexcept;

    /// \brief Class destructor.
    ~TransferRecipient() override;

    /// \brief Sets the recipient account of the token.
    /// \param account The recipient account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetAccount(SerializableStringPtr account);

    /// \brief Sets parameters for making a simple transfer.
    /// \param simpleParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetSimpleParams(SimpleTransferParamsPtr simpleParams);

    /// \brief Sets parameters for making an operator transfer.
    /// \param operatorParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetOperatorParams(OperatorTransferParamsPtr operatorParams);

    TransferRecipient& operator=(const TransferRecipient& rhs);

    TransferRecipient& operator=(TransferRecipient&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP
