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

#ifndef ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP
#define ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP

#include "EnjinPlatformSdk/EdgeFragment.hpp"
#include "EnjinPlatformSdk/PageInfoFragment.hpp"
#include "EnjinPlatformSdk/internal/ConnectionFragmentBase.hpp"
#include <memory>
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
template<class...>
class ConnectionFragment;

/// \brief A fragment for requesting properties of a scalar connection returned by the platform.
template<class...>
class ConnectionFragment : public ConnectionFragmentBase<ConnectionFragment<>>
{
    static constexpr char EdgeName[] = "edge";

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragment(const ConnectionFragment<>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragment(ConnectionFragment<>&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragment() override = default;

    /// \brief Unsets this fragment from requesting the edge property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& RemoveEdge()
    {
        return GraphQlFragment<ConnectionFragment<>>::RemoveField(EdgeName);
    }

    /// \brief Sets this fragment to request that the edge property be returned with the connection.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& WithEdge(std::shared_ptr<EdgeFragment<>> fragment)
    {
        return GraphQlFragment<ConnectionFragment<>>::WithField(EdgeName, std::move(fragment));
    }

    ConnectionFragment& operator=(const ConnectionFragment<>& rhs) = default;

    ConnectionFragment& operator=(ConnectionFragment<>&& rhs) noexcept = default;
};

/// \brief A fragment for requesting properties of a non-scalar connection returned by the platform.
/// \tparam TFragment The fragment describing the non-scalar data.
template<class TFragment>
class ConnectionFragment<TFragment> : public ConnectionFragmentBase<ConnectionFragment<TFragment>>
{
    static_assert(std::is_base_of<IGraphQlFragment<TFragment>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<>");

    static constexpr char EdgeName[] = "edge";

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragment(const ConnectionFragment<TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragment(ConnectionFragment<TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragment() override = default;

    /// \brief Unsets this fragment from requesting the edge property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& RemoveEdge()
    {
        return GraphQlFragment<ConnectionFragment<TFragment>>::RemoveField(EdgeName);
    }

    /// \brief Sets this fragment to request that the edge property be returned with the connection.
    /// \param fragment The fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& WithEdge(std::shared_ptr<EdgeFragment<TFragment>> fragment)
    {
        return GraphQlFragment<ConnectionFragment<TFragment>>::WithField(EdgeName, std::move(fragment));
    }

    ConnectionFragment& operator=(const ConnectionFragment<TFragment>& rhs) = default;

    ConnectionFragment& operator=(ConnectionFragment<TFragment>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP
