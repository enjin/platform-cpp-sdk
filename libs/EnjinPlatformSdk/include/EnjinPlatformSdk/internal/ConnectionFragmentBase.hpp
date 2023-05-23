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

#ifndef ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP
#define ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include "EnjinPlatformSdk/PageInfoFragment.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract base class for GraphQL fragments of the platform's Connection type to extend from.
/// \tparam TConnection The inheriting connection class. Must extend this class.
template<class TConnection>
class ConnectionFragmentBase : public GraphQlFragment<TConnection>
{
    static constexpr char PageInfoKey[] = "pageInfo";
    static constexpr char TotalCountKey[] = "totalCount";

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragmentBase() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragmentBase(const ConnectionFragmentBase<TConnection>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragmentBase(ConnectionFragmentBase<TConnection>&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragmentBase() override = default;

    /// \brief Sets the cursor to fetch.
    /// \param after The cursor.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& SetAfter(SerializableStringPtr after)
    {
        return GraphQlFragment<TConnection>::SetParameter("after", std::move(after));
    }

    /// \brief Sets the number results to return per page.
    /// \param first The number of result per page.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& SetFirst(SerializableIntPtr first)
    {
        return GraphQlFragment<TConnection>::SetParameter("first", std::move(first));
    }

    /// \brief Unsets this fragment from requesting the pageInfo property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& RemovePageInfo()
    {
        return GraphQlFragment<TConnection>::RemoveField(PageInfoKey);
    }

    /// \brief Sets this fragment to request that the pageInfo property be returned with the connection.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& WithPageInfo(PageInfoFragmentPtr fragment)
    {
        return GraphQlFragment<TConnection>::WithField(PageInfoKey, std::move(fragment));
    }

    /// \brief Unsets this fragment from requesting the totalCount property.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& RemoveTotalCount()
    {
        return GraphQlFragment<TConnection>::RemoveField(TotalCountKey);
    }

    /// \brief Sets this fragment to request that the totalCount property be returned with the connection.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& WithTotalCount()
    {
        return GraphQlFragment<TConnection>::WithField(TotalCountKey);
    }

    ConnectionFragmentBase& operator=(const ConnectionFragmentBase<TConnection>& rhs) = default;

    ConnectionFragmentBase& operator=(ConnectionFragmentBase<TConnection>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP
