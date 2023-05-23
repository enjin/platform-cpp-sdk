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

#ifndef ENJINPLATFORMSDK_EDGEFRAGMENT_HPP
#define ENJINPLATFORMSDK_EDGEFRAGMENT_HPP

#include "EnjinPlatformSdk/internal/EdgeFragmentBase.hpp"
#include <memory>
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
template<class...>
class EdgeFragment;

/// \brief A fragment for requesting properties of a scalar edge returned by the platform.
template<class...>
class EdgeFragment : public EdgeFragmentBase<EdgeFragment<>>
{
    static constexpr char NodeName[] = "node";

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    EdgeFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EdgeFragment(const EdgeFragment<>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EdgeFragment(EdgeFragment<>&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragment() override = default;

    /// \brief Unsets this fragment from requesting the node property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& RemoveNode()
    {
        return GraphQlFragment<EdgeFragment>::RemoveField(NodeName);
    }

    /// \brief Sets this fragment to request that the node property be returned with the page info.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& WithNode()
    {
        return GraphQlFragment<EdgeFragment>::WithField(NodeName);
    }

    EdgeFragment& operator=(const EdgeFragment<>& rhs) = default;

    EdgeFragment& operator=(EdgeFragment<>&& rhs) noexcept = default;
};

/// \brief A fragment for requesting properties of a non-scalar edge returned by the platform.
/// \tparam TFragment The fragment describing the non-scalar data.
template<class TFragment>
class EdgeFragment<TFragment> : public EdgeFragmentBase<EdgeFragment<TFragment>>
{
    static_assert(std::is_base_of<IGraphQlFragment<TFragment>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<>");

    static constexpr char NodeKey[] = "node";

public:
    /// \brief Constructs an instance of this class.
    EdgeFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    EdgeFragment(const EdgeFragment<TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    EdgeFragment(EdgeFragment<TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragment() override = default;

    /// \brief Unsets this fragment from requesting the node property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& RemoveNode()
    {
        return GraphQlFragment<EdgeFragment>::RemoveField(NodeKey);
    }

    /// \brief Sets this fragment to request that the node property be returned with the page info.
    /// \param fragment The fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& WithNode(std::shared_ptr<TFragment> fragment)
    {
        return GraphQlFragment<EdgeFragment>::WithField(NodeKey, std::move(fragment));
    }

    EdgeFragment& operator=(const EdgeFragment<TFragment>& rhs) = default;

    EdgeFragment& operator=(EdgeFragment<TFragment>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_EDGEFRAGMENT_HPP
