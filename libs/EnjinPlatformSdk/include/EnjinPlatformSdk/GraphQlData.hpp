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

#ifndef ENJINPLATFORMSDK_GRAPHQLDATA_HPP
#define ENJINPLATFORMSDK_GRAPHQLDATA_HPP

#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Models the data field of a GraphQL response containing a single result.
/// \tparam TResult The type of the result.
template<class TResult>
class GraphQlData final : public JsonDeserializableBase
{
    std::optional<TResult> _result;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlData() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GraphQlData(const GraphQlData<TResult>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GraphQlData(GraphQlData<TResult>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlData() override = default;

    /// \brief Returns the result data for the response.
    /// \return The result data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TResult>& GetResult() const
    {
        return _result;
    }

    GraphQlData& operator=(const GraphQlData<TResult>& rhs) = default;

    GraphQlData& operator=(GraphQlData<TResult>&& rhs) noexcept = default;

    bool operator==(const GraphQlData<TResult>& rhs) const = default;

    bool operator!=(const GraphQlData<TResult>& rhs) const = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "result", _result);
    }

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLDATA_HPP
