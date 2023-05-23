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

#include "EnjinPlatformSdk/PageInfoFragment.hpp"

using namespace enjin::platform::sdk;

// region Impl

class PageInfoFragment::Impl : public GraphQlFragment<Impl>
{
public:
    static constexpr char HasNextPageName[] = "hasNextPage";
    static constexpr char HasPreviousPageName[] = "hasPreviousPage";
    static constexpr char StartCursorName[] = "startCursor";
    static constexpr char EndCursorName[] = "endCursor";

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    void RemoveHasNextPage()
    {
        GraphQlFragment<Impl>::RemoveField(HasNextPageName);
    }

    void WithHasNextPage()
    {
        GraphQlFragment<Impl>::WithField(HasNextPageName);
    }

    void RemoveHasPreviousPage()
    {
        GraphQlFragment<Impl>::RemoveField(HasPreviousPageName);
    }

    void WithHasPreviousPage()
    {
        GraphQlFragment<Impl>::WithField(HasPreviousPageName);
    }

    void RemoveHasStartCursor()
    {
        GraphQlFragment<Impl>::RemoveField(StartCursorName);
    }

    void WithHasStartCursor()
    {
        GraphQlFragment<Impl>::WithField(StartCursorName);
    }

    void RemoveHasEndCursor()
    {
        GraphQlFragment<Impl>::RemoveField(EndCursorName);
    }

    void WithHasEndCursor()
    {
        GraphQlFragment<Impl>::WithField(EndCursorName);
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;
};

// endregion Impl

// region PageInfoFragment

[[maybe_unused]]
PageInfoFragment::PageInfoFragment()
    : GraphQlFragment<PageInfoFragment>(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
PageInfoFragment::PageInfoFragment(const PageInfoFragment& other)
    : GraphQlFragment<PageInfoFragment>(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
PageInfoFragment::PageInfoFragment(PageInfoFragment&& other) noexcept = default;

PageInfoFragment::~PageInfoFragment() = default;

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::RemoveHasNextPage()
{
    _pimpl->RemoveHasNextPage();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasNextPage()
{
    _pimpl->WithHasNextPage();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::RemoveHasPreviousPage()
{
    _pimpl->RemoveHasPreviousPage();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasPreviousPage()
{
    _pimpl->WithHasPreviousPage();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::RemoveHasStartCursor()
{
    _pimpl->RemoveHasStartCursor();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasStartCursor()
{
    _pimpl->WithHasStartCursor();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::RemoveHasEndCursor()
{
    _pimpl->RemoveHasEndCursor();
    return *this;
}

[[maybe_unused]]
PageInfoFragment& PageInfoFragment::WithHasEndCursor()
{
    _pimpl->WithHasEndCursor();
    return *this;
}

PageInfoFragment& PageInfoFragment::operator=(const PageInfoFragment& rhs)
{
    GraphQlFragment<PageInfoFragment>::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

PageInfoFragment& PageInfoFragment::operator=(PageInfoFragment&& rhs) noexcept = default;

// endregion PageInfoFragment
