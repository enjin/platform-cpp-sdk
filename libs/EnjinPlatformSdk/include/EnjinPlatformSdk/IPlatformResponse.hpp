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

#ifndef ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP
#define ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP

#include <map>
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
template<class TResult>
class IPlatformResponse;

/// \brief Definition for a pointer containing a platform response type.
template<class TResult>
using PlatformResponsePtr = std::shared_ptr<IPlatformResponse<TResult>>;

/// \brief Interface for a response containing HTTP data that the platform sent in response to a request.
/// \tparam TResult The type of the result in the response.
template<class TResult>
class IPlatformResponse
{
public:
    /// \brief Class destructor.
    virtual ~IPlatformResponse() = default;

    /// \brief Returns the HTTP headers for this response.
    /// \return The HTTP headers.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, std::string>& GetHeaders() const = 0;

    /// \brief Returns the result that represents the body of this response.
    /// \return The result.
    virtual const std::optional<TResult>& GetResult() const = 0;

    /// \brief Returns the status code of this response.
    /// \return The status code.
    [[maybe_unused]]
    [[nodiscard]]
    virtual int GetStatusCode() const = 0;

    /// \brief Determines whether the status code of this response is in the success range [200-300).
    /// \return Whether the status code is in the success range.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsSuccessStatusCode() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP
