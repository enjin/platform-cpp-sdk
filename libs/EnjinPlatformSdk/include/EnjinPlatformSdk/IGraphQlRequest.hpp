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

#ifndef ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP
#define ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP

#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlRequest;

/// \brief Interface for GraphQL requests.
template<class...>
class IGraphQlRequest : public IGraphQlUploadHolder
{
public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Returns the name of this request.
    /// \return The name.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string GetName() const = 0;

    /// \brief Returns a JSON value-object representing the variables for this request.
    /// \return The JSON value-object.
    [[maybe_unused]]
    [[nodiscard]]
    virtual JsonValue GetVariablesJson() const = 0;

    /// \brief Determines whether this request has variables.
    /// \return Whether this request has variables.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasVariables() const = 0;
};

/// \brief Interface for GraphQL requests with a settable variables for the operation.
/// \tparam TRequest The type of the request. Must implement this interface.
template<class TRequest>
class IGraphQlRequest<TRequest> : public IGraphQlRequest<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Sets a variable for this request.
    /// \param name The variable name.
    /// \param type The variable type.
    /// \param value The variable value.
    /// \return This request for chaining.
    [[maybe_unused]]
    virtual TRequest& SetVariable(std::string name, std::string type, SerializablePtr value) = 0;
};

/// \brief Interface for GraphQL requests with a settable fragment for response data.
/// \tparam TRequest The type of the request. Must implement this interface.
/// \tparam TFragment The type of the fragment. Must implement IGraphQlFragment.
template<class TRequest, class TFragment>
class IGraphQlRequest<TRequest, TFragment> : public IGraphQlRequest<TRequest>
{
    static_assert(std::is_base_of<IGraphQlFragment<>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<>");

public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Determines whether a fragment is attached to this request.
    /// \return Whether a fragment is attached to this request.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasFragment() const = 0;

    /// \brief Sets the fragment defining the response data for this request.
    /// \param fragment The fragment.
    /// \return This request for chaining.
    [[maybe_unused]]
    virtual TRequest& SetFragment(std::shared_ptr<TFragment> fragment) = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP
