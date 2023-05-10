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

#ifndef ENJINPLATFORMSDK_RESPONSE_HPP
#define ENJINPLATFORMSDK_RESPONSE_HPP

#include <map>
#include <optional>
#include <string>

/// \brief HTTP response builder to be used when setting a stub response in MockHttpServer.
class Response
{
    std::optional<std::string> _body;
    std::map<std::string, std::string> _headers;
    std::optional<int> _statusCode;

public:
    /// \brief Class destructor.
    ~Response();

    /// \brief Adds a body to this response.
    /// \param body The serialized body.
    /// \return This response for chaining.
    [[maybe_unused]]
    Response& WithBody(std::string body);

    /// \brief Adds a header to this response.
    /// \param name The header name (key).
    /// \param value The header value.
    /// \return This response for chaining.
    [[maybe_unused]]
    Response& WithHeader(std::string key, std::string value);

    /// \brief Adds the status code to this response.
    /// \param code The status code.
    /// \return This response for chaining.
    [[maybe_unused]]
    Response& WithStatusCode(int code);

    /// \brief Marks this response as being successful with a status code of 200.
    /// \return This response for chaining.
    [[maybe_unused]]
    Response& WithSuccess();

    /// \brief Creates a new instance of this class.
    /// \return A new instance of this class.
    [[maybe_unused]]
    [[nodiscard]]
    static Response Create();

private:
    /// \brief Constructs an instance of this class.
    Response();

    friend class MockHttpServer;
};

#endif //ENJINPLATFORMSDK_RESPONSE_HPP
