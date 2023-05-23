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

#ifndef ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP
#define ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class PageInfoFragment;

/// \brief Definition for a pointer containing a page info fragment.
using PageInfoFragmentPtr [[maybe_unused]] = std::shared_ptr<PageInfoFragment>;

/// \brief A fragment for requesting properties of a PageInfo returned by the platform.
class ENJINPLATFORMSDK_EXPORT PageInfoFragment : public GraphQlFragment<PageInfoFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PageInfoFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PageInfoFragment(const PageInfoFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PageInfoFragment(PageInfoFragment&& other) noexcept;

    /// \brief Class destructor.
    ~PageInfoFragment() override;

    /// \brief Unsets this fragment from requesting the hasNextPage property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& RemoveHasNextPage();

    /// \brief Sets this fragment to request that the hasNextPage property be returned with the page info.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasNextPage();

    /// \brief Unsets this fragment from requesting the hasPreviousPage property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& RemoveHasPreviousPage();

    /// \brief Sets this fragment to request that the hasPreviousPage property be returned with the page info.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasPreviousPage();

    /// \brief Unsets this fragment from requesting the hasStartCursor property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& RemoveHasStartCursor();

    /// \brief Sets this fragment to request that the hasStartCursor property be returned with the page info.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasStartCursor();

    /// \brief Unsets this fragment from requesting the hasEndCursor property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& RemoveHasEndCursor();

    /// \brief Sets this fragment to request that the hasEndCursor property be returned with the page info.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasEndCursor();

    PageInfoFragment& operator=(const PageInfoFragment& rhs);

    PageInfoFragment& operator=(PageInfoFragment&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP
