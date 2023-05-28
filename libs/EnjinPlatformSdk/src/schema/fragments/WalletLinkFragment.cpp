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

#include "EnjinPlatformSdk/WalletLinkFragment.hpp"

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <utility>

using namespace enjin::platform::sdk;

// region Impl

class WalletLinkFragment::Impl : public GraphQlFragment<Impl>
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

// region WalletLinkFragment

[[maybe_unused]]
WalletLinkFragment::WalletLinkFragment()
    : _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
WalletLinkFragment::WalletLinkFragment(const WalletLinkFragment& other)
    : _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
WalletLinkFragment::WalletLinkFragment(WalletLinkFragment&& other) noexcept = default;

WalletLinkFragment::~WalletLinkFragment() = default;

[[maybe_unused]]
WalletLinkFragment& WalletLinkFragment::WithCode(const bool isIncluded)
{
    return WithField("code", isIncluded);
}

WalletLinkFragment& WalletLinkFragment::operator=(const WalletLinkFragment& rhs)
{
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

WalletLinkFragment& WalletLinkFragment::operator=(WalletLinkFragment&& rhs) noexcept = default;

// region IGraphQlFragment

[[maybe_unused]]
std::string WalletLinkFragment::CompileFields() const
{
    return _pimpl->CompileFields();
}

[[maybe_unused]]
bool WalletLinkFragment::HasField(const std::string& name) const
{
    return _pimpl->HasField(name);
}

[[maybe_unused]]
bool WalletLinkFragment::HasFields() const
{
    return _pimpl->HasFields();
}

[[maybe_unused]]
WalletLinkFragment& WalletLinkFragment::WithField(std::string name, const bool isIncluded)
{
    _pimpl->WithField(std::move(name), isIncluded);

    return *this;
}

[[maybe_unused]]
WalletLinkFragment& WalletLinkFragment::WithField(std::string name, GraphQlFragmentPtr fragment)
{
    _pimpl->WithField(std::move(name), std::move(fragment));

    return *this;
}

// endregion IGraphQlFragment

// region IGraphQlParameterHolder

[[maybe_unused]]
std::string WalletLinkFragment::CompileParameters() const
{
    return _pimpl->CompileParameters();
}

[[maybe_unused]]
const std::map<std::string, SerializablePtr>& WalletLinkFragment::GetParameters() const
{
    return _pimpl->GetParameters();
}

[[maybe_unused]]
bool WalletLinkFragment::HasParameters() const
{
    return _pimpl->HasParameters();
}

[[maybe_unused]]
WalletLinkFragment& WalletLinkFragment::RemoveParameter(const std::string& key)
{
    _pimpl->RemoveParameter(key);

    return *this;
}

[[maybe_unused]]
WalletLinkFragment& WalletLinkFragment::SetParameter(std::string key, SerializablePtr value)
{
    _pimpl->SetParameter(std::move(key), std::move(value));

    return *this;
}

// endregion IGraphQlParameterHolder

// endregion WalletLinkFragment
