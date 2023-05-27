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

#include "EnjinPlatformSdk/CollectionAccountFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class CollectionAccountFragment::Impl : public GraphQlFragment<Impl>
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

// region CollectionAccountFragment

[[maybe_unused]]
CollectionAccountFragment::CollectionAccountFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
CollectionAccountFragment::CollectionAccountFragment(const CollectionAccountFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
CollectionAccountFragment::CollectionAccountFragment(CollectionAccountFragment&& other) noexcept = default;

CollectionAccountFragment::~CollectionAccountFragment() = default;

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithAccountCount(const bool isIncluded)
{
    return WithField("accountCount", isIncluded);
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithIsFrozen(const bool isIncluded)
{
    return WithField("isFrozen", isIncluded);
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithCollection(CollectionFragmentPtr fragment)
{
    return WithField("collection", std::move(fragment));
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithWallet(WalletFragmentPtr fragment)
{
    return WithField("wallet", std::move(fragment));
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithApprovals(CollectionAccountApprovalFragmentPtr fragment)
{
    return WithField("approvals", std::move(fragment));
}

CollectionAccountFragment& CollectionAccountFragment::operator=(const CollectionAccountFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

CollectionAccountFragment& CollectionAccountFragment::operator=(CollectionAccountFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string CollectionAccountFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool CollectionAccountFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool CollectionAccountFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string CollectionAccountFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& CollectionAccountFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool CollectionAccountFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
CollectionAccountFragment& CollectionAccountFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion CollectionAccountFragment
