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

#include "EnjinPlatformSdk/CollectionAccountApprovalFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class CollectionAccountApprovalFragment::Impl : public GraphQlFragment<Impl>
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

// region CollectionAccountApprovalFragment

[[maybe_unused]]
CollectionAccountApprovalFragment::CollectionAccountApprovalFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
CollectionAccountApprovalFragment::CollectionAccountApprovalFragment(const CollectionAccountApprovalFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
CollectionAccountApprovalFragment::CollectionAccountApprovalFragment(
    CollectionAccountApprovalFragment&& other) noexcept = default;

CollectionAccountApprovalFragment::~CollectionAccountApprovalFragment() = default;

[[maybe_unused]]
CollectionAccountApprovalFragment& CollectionAccountApprovalFragment::WithExpiration(const bool isIncluded)
{
    return WithField("expiration", isIncluded);
}

[[maybe_unused]]
CollectionAccountApprovalFragment& CollectionAccountApprovalFragment::WithAccount(CollectionAccountFragmentPtr fragment)
{
    return WithField("account", std::move(fragment));
}

[[maybe_unused]]
CollectionAccountApprovalFragment& CollectionAccountApprovalFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

CollectionAccountApprovalFragment&
CollectionAccountApprovalFragment::operator=(const CollectionAccountApprovalFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

CollectionAccountApprovalFragment&
CollectionAccountApprovalFragment::operator=(CollectionAccountApprovalFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string CollectionAccountApprovalFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool CollectionAccountApprovalFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool CollectionAccountApprovalFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
CollectionAccountApprovalFragment& CollectionAccountApprovalFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
CollectionAccountApprovalFragment&
CollectionAccountApprovalFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string CollectionAccountApprovalFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& CollectionAccountApprovalFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool CollectionAccountApprovalFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
CollectionAccountApprovalFragment& CollectionAccountApprovalFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
CollectionAccountApprovalFragment&
CollectionAccountApprovalFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion CollectionAccountApprovalFragment
