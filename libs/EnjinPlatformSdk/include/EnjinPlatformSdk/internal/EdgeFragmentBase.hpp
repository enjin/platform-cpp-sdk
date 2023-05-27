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

#ifndef ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP
#define ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP

#include "EnjinPlatformSdk/GraphQlFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief Abstract base class for GraphQL fragments of the platform's edge type to extend from.
/// \tparam TEdge The inheriting edge class. Must extend this class.
template<class TEdge>
class EdgeFragmentBase : public GraphQlFragment<TEdge>
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EdgeFragmentBase(const EdgeFragmentBase<TEdge>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EdgeFragmentBase(EdgeFragmentBase<TEdge>&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragmentBase() override = default;

    /// \brief Sets whether the edge is to be returned with its cursor property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TEdge& WithCursor(bool isIncluded = true)
    {
        return GraphQlFragment<TEdge>::WithField("cursor", isIncluded);
    }

    EdgeFragmentBase& operator=(const EdgeFragmentBase<TEdge>& rhs) = default;

    EdgeFragmentBase& operator=(EdgeFragmentBase<TEdge>&& rhs) noexcept = default;

protected:
    /// \brief Constructs an instance of this class.
    EdgeFragmentBase() = default;
};
}

#endif //ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP
