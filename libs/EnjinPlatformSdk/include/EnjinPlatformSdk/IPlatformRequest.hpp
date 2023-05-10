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

#ifndef ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP
#define ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP

#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
class IPlatformRequest;

/// \brief Definition for a pointer containing a platform request type.
using PlatformRequestPtr [[maybe_unused]] = std::shared_ptr<IPlatformRequest>;

/// \brief Interface for platform requests to implement.
class IPlatformRequest
{
public:
    /// \brief Class destructor.
    virtual ~IPlatformRequest() = default;

    /// \brief Returns the body of this request.
    /// \return The body.
    /// \remarks May be empty if this request has multipart form-data.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::optional<std::string>& GetBody() const = 0;

    /// \brief Returns the content-type of this request.
    /// \return The content-type.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::string& GetContentType() const = 0;

    /// \brief Returns the headers for this request.
    /// \return The headers.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, std::string>& GetHeaders() const = 0;

    /// \brief Returns the multipart forms-data for this request.
    /// \return The multipart form-data.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::optional<std::vector<MultipartFormData>>& GetMultipartFormData() const = 0;

    /// \brief Returns the relative path of this request.
    /// \return The relative path.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::string& GetPath() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP
