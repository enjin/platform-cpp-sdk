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

#ifndef ENJINPLATFORMSDK_CONNECTION_HPP
#define ENJINPLATFORMSDK_CONNECTION_HPP

#include "EnjinPlatformSdk/Edge.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/PageInfo.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Models a pagination from the platform.
/// \tparam T The type within the pagination.
template<class T>
class Connection : public JsonDeserializableBase
{
    std::optional<std::vector<Edge<T>>> _edges;
    std::optional<PageInfo> _pageInfo;
    std::optional<int32_t> _totalCount;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    Connection() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    Connection(const Connection& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    Connection(Connection&& other) noexcept = default;

    /// \brief Class destructor.
    ~Connection() override = default;

    /// \brief Returns the edges in this connection.
    /// \return The edges in this connection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<Edge<T>>>& GetEdges() const
    {
        return _edges;
    }

    /// \brief Returns the page information for this connection.
    /// \return The page information for this connection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<PageInfo>& GetPageInfo() const
    {
        return _pageInfo;
    }

    /// \brief Returns the total count of items in this connection.
    /// \return The total count of items in this connection.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<int32_t>& GetTotalCount() const
    {
        return _totalCount;
    }

    Connection& operator=(const Connection& rhs) = default;

    Connection& operator=(Connection&& rhs) noexcept = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "edges", _edges);
        JsonUtil::TryGetField(json, "pageInfo", _pageInfo);
        JsonUtil::TryGetField(json, "totalCount", _totalCount);
    }

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_CONNECTION_HPP
