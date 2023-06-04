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

#include "EnjinPlatformSdk/TokenAccountFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class TokenAccountFragment::Impl : public GraphQlFragment<Impl>
{
public:
    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;
};

// endregion Impl

// region TokenAccountFragment

[[maybe_unused]]
TokenAccountFragment::TokenAccountFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
TokenAccountFragment::TokenAccountFragment(const TokenAccountFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
TokenAccountFragment::TokenAccountFragment(TokenAccountFragment&& other) noexcept = default;

TokenAccountFragment::~TokenAccountFragment() = default;

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithBalance(const bool isIncluded)
{
    return WithField("balance", isIncluded);
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithReservedBalance(const bool isIncluded)
{
    return WithField("reservedBalance", isIncluded);
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithIsFrozen(const bool isIncluded)
{
    return WithField("isFrozen", isIncluded);
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithCollection(CollectionFragmentPtr fragment)
{
    return WithField("collection", std::move(fragment));
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithToken(TokenFragmentPtr fragment)
{
    return WithField("token", std::move(fragment));
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithApprovals(TokenAccountApprovalFragmentPtr fragment)
{
    return WithField("approvals", std::move(fragment));
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithNamedReserves(TokenAccountNamedReserveFragmentPtr fragment)
{
    return WithField("namedReserves", std::move(fragment));
}

TokenAccountFragment& TokenAccountFragment::operator=(const TokenAccountFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

TokenAccountFragment& TokenAccountFragment::operator=(TokenAccountFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string TokenAccountFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool TokenAccountFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool TokenAccountFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string TokenAccountFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& TokenAccountFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool TokenAccountFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
TokenAccountFragment& TokenAccountFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion TokenAccountFragment
