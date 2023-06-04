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

#ifndef ENJINPLATFORMSDK_ACCOUNTREQUESTFRAGMENT_HPP
#define ENJINPLATFORMSDK_ACCOUNTREQUESTFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class AccountRequestFragment;

/// \brief Definition for a pointer containing an account request fragment.
using AccountRequestFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountRequestFragment>;

/// \brief Definition for an account request connection fragment.
using AccountRequestConnectionFragment [[maybe_unused]] = ConnectionFragment<AccountRequestFragment>;

/// \brief Definition for a pointer containing an account request connection fragment.
using AccountRequestConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AccountRequestConnectionFragment>;

/// \brief A fragment for requesting properties of an account request returned by the platform.
class ENJINPLATFORMSDK_EXPORT AccountRequestFragment : public IGraphQlFragment<AccountRequestFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AccountRequestFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AccountRequestFragment(const AccountRequestFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AccountRequestFragment(AccountRequestFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AccountRequestFragment() override;

    /// \brief Sets whether the account request is to be returned with its qrCode property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountRequestFragment& WithQrCode(bool isIncluded = true);

    /// \brief Sets whether the account request is to be returned with its verificationId property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AccountRequestFragment& WithVerificationId(bool isIncluded = true);

    AccountRequestFragment& operator=(const AccountRequestFragment& rhs);

    AccountRequestFragment& operator=(AccountRequestFragment&& rhs) noexcept;

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
    AccountRequestFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AccountRequestFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    AccountRequestFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AccountRequestFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_ACCOUNTREQUESTFRAGMENT_HPP
