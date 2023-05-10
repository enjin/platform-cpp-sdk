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

#ifndef ENJINPLATFORMSDK_GRAPHQLRESPONSE_HPP
#define ENJINPLATFORMSDK_GRAPHQLRESPONSE_HPP

#include "EnjinPlatformSdk/GraphQlData.hpp"
#include "EnjinPlatformSdk/GraphQlError.hpp"
#include "EnjinPlatformSdk/JsonUtil.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <optional>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Represents a GraphQL response message from the platform for a single operation.
/// \tparam TResult The type to be returned in the result.
template<class TResult>
class GraphQlResponse final : public JsonDeserializableBase
{
    std::optional<GraphQlData<TResult>> _data;
    std::optional<std::vector<GraphQlError>> _errors;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlResponse() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GraphQlResponse(const GraphQlResponse<TResult>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GraphQlResponse(GraphQlResponse<TResult>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlResponse() override = default;

    /// \brief Returns the data of this response.
    /// \return The data.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<GraphQlData<TResult>>& GetData() const
    {
        return _data;
    }

    /// \brief Returns the errors of this response.
    /// \return The errors.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<GraphQlError>>& GetErrors() const
    {
        return _errors;
    }

    /// \brief Determines whether this response contains errors.
    /// \return Whether this response contains errors.
    [[maybe_unused]]
    [[nodiscard]]
    bool HasErrors() const
    {
        return _errors.has_value() && !_errors.value().empty();
    }

    /// \brief Determines whether this response is empty.
    /// \return Whether this response is empty.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsEmpty() const
    {
        return !_data.has_value() || !_data.value().GetResult().has_value();
    }

    /// \brief Determines whether this response is successful. Must contain data and have no errors.
    /// \return Whether this response is successful.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsSuccess() const
    {
        return !IsEmpty() && !HasErrors();
    }

    GraphQlResponse& operator=(const GraphQlResponse<TResult>& rhs) = default;

    GraphQlResponse& operator=(GraphQlResponse<TResult>&& rhs) noexcept = default;

    bool operator==(const GraphQlResponse<TResult>& rhs) const = default;

    bool operator!=(const GraphQlResponse<TResult>& rhs) const = default;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "data", _data);
        JsonUtil::TryGetField(json, "errors", _errors);
    }

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLRESPONSE_HPP
