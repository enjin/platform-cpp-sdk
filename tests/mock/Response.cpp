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

#include "Response.hpp"

#include <utility>

Response::Response() = default;

Response::~Response() = default;

[[maybe_unused]]
Response& Response::WithBody(std::string body)
{
    _body = std::move(body);
    return *this;
}

[[maybe_unused]]
Response& Response::WithHeader(std::string key, std::string value)
{
    _headers.emplace(std::move(key), std::move(value));
    return *this;
}

[[maybe_unused]]
Response& Response::WithStatusCode(const int code)
{
    _statusCode = code;
    return *this;
}

[[maybe_unused]]
Response& Response::WithSuccess()
{
    _statusCode = 200;
    return *this;
}

// Static

[[maybe_unused]]
Response Response::Create()
{
    return {};
}
