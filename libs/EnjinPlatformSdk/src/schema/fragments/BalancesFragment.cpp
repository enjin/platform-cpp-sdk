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

#include "EnjinPlatformSdk/BalancesFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class BalancesFragment::Impl : public GraphQlFragment<Impl>
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

// region BalancesFragment

[[maybe_unused]]
BalancesFragment::BalancesFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
BalancesFragment::BalancesFragment(const BalancesFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
BalancesFragment::BalancesFragment(BalancesFragment&& other) noexcept = default;

BalancesFragment::~BalancesFragment() = default;

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithFree(const bool isIncluded)
{
    return WithField("free", isIncluded);
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithReserved(const bool isIncluded)
{
    return WithField("reserved", isIncluded);
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithMiscFrozen(const bool isIncluded)
{
    return WithField("miscFrozen", isIncluded);
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithFeeFrozen(const bool isIncluded)
{
    return WithField("feeFrozen", isIncluded);
}

BalancesFragment& BalancesFragment::operator=(const BalancesFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

BalancesFragment& BalancesFragment::operator=(BalancesFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string BalancesFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool BalancesFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool BalancesFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string BalancesFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& BalancesFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool BalancesFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
BalancesFragment& BalancesFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion BalancesFragment
