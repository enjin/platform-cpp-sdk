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

#include "FakePlatformRequest.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
FakePlatformRequest::FakePlatformRequest() = default;

FakePlatformRequest::~FakePlatformRequest() = default;

[[maybe_unused]]
const std::optional<std::string>& FakePlatformRequest::GetBody() const
{
    return body;
}

[[maybe_unused]]
const std::string& FakePlatformRequest::GetContentType() const
{
    return contentType;
}

[[maybe_unused]]
const std::map<std::string, std::string>& FakePlatformRequest::GetHeaders() const
{
    return headers;
}

[[maybe_unused]]
const std::optional<std::vector<MultipartFormData>>& FakePlatformRequest::GetMultipartFormData() const
{
    return multipartFormData;
}

[[maybe_unused]]
const std::string& FakePlatformRequest::GetPath() const
{
    return path;
}
