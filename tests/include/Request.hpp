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

#ifndef ENJINPLATFORMSDK_REQUEST_HPP
#define ENJINPLATFORMSDK_REQUEST_HPP

#include <optional>
#include <string>

/// \brief HTTP request builder to be used when setting expectations of a request in MockHttpServer.
class Request
{
    std::optional<std::string> _body;
    std::optional<std::string> _method;
    std::optional<std::string> _path;

public:
    /// \brief Class destructor.
    ~Request();

    /// \brief Marks this request as using the Delete HTTP method.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& UsingDelete();

    /// \brief Marks this request as using the Get HTTP method.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& UsingGet();

    /// \brief Marks this request as using the Post HTTP method.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& UsingPost();

    /// \brief Marks this request as using the Put HTTP method.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& UsingPut();

    /// \brief Adds a body to this request.
    /// \param body The serialized body.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& WithBody(std::string body);

    /// \brief Adds the relative path to this request.
    /// \param path The relative path.
    /// \return This request for chaining.
    [[maybe_unused]]
    Request& WithPath(std::string path);

    bool operator==(const Request& rhs) const;

    bool operator!=(const Request& rhs) const;

    bool operator<(const Request& rhs) const;

    bool operator>(const Request& rhs) const;

    bool operator<=(const Request& rhs) const;

    bool operator>=(const Request& rhs) const;

    /// \brief Creates a new instance of this class.
    /// \return The new instance of this class.
    [[maybe_unused]]
    [[nodiscard]]
    static Request Create();

private:
    /// \brief Constructs an instance of this class.
    Request();

    friend class MockHttpServer;
};

#endif //ENJINPLATFORMSDK_REQUEST_HPP
