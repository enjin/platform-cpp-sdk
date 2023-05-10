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

#include "MockHttpServer.hpp"

#include "httplib.h"
#include "FakePlatformRequest.hpp"
#include <map>
#include <mutex>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <utility>

// Do not use httplib namespace to avoid ambiguous references
using namespace enjin::platform::sdk;

using ResponseProviderPtr = std::unique_ptr<ResponseProvider>;

// region Impl

class MockHttpServer::Impl
{
    std::queue<MessageHandler> _messageHandlers;
    std::map<std::string, ResponseProviderPtr> _responseProviderMap;

    // Server info
    httplib::Server _server;
    std::optional<std::string> _uri;

    // Threads
    std::thread _serverThread;

    // Mutexes
    mutable std::mutex _messagesMutex;
    mutable std::mutex _serverMutex;

    static constexpr char ContentTypeKey[] = "Content-Type";
    static constexpr char DefaultContentType[] = "text/plain charset=utf-8";
    static constexpr char Host[] = "localhost";

public:
    Impl()
    {
        if (!_server.set_mount_point("/", "./"))
        {
            throw std::runtime_error("The base directory does not exist for mock HTTP server");
        }
        else if (!_server.is_valid())
        {
            throw std::runtime_error("Mock server is not valid");
        }
    }

    ~Impl()
    {
        Stop();
    }

    const std::optional<std::string>& GetUri() const
    {
        return _uri;
    }

    ResponseProvider& Given(const Request& request)
    {
        if (!request._path.has_value())
        {
            throw std::invalid_argument("HTTP request does not have a set path");
        }

        if (!request._method.has_value())
        {
            throw std::invalid_argument("HTTP request does not have a set method");
        }

        const std::string& path = request._path.value();
        const std::string& method = request._method.value();

        std::lock_guard<std::mutex> guard(_serverMutex);

        _responseProviderMap[path] = std::unique_ptr<ResponseProvider>(new ResponseProvider());
        ResponseProviderPtr& provider = _responseProviderMap[path];

        AssignProvider(provider, path, method);

        return *provider;
    }

    void NextMessage(MessageHandler handler)
    {
        std::lock_guard<std::mutex> guard(_messagesMutex);
        _messageHandlers.emplace(std::move(handler));
    }

    void Start()
    {
        Stop();

        std::lock_guard<std::mutex> guard(_serverMutex);

        const int port = _server.bind_to_any_port(Host);
        _uri = CreateUri(port);

        _serverThread = std::thread([this]()
                                    {
                                        _server.listen_after_bind();
                                    });
    }

    void Stop()
    {
        std::lock_guard<std::mutex> guard(_serverMutex);

        if (_server.is_running())
        {
            _uri.reset();
            _server.stop();
            _serverThread.join();
        }
    }

private:
    /// \brief Assigns the given response provider to the server.
    /// \param provider The response provider.
    /// \param path The stubbed path for the response.
    /// \param method The stubbed HTTP method for the response.
    /// \throws std::invalid_argument Thrown if given an unsupported HTTP method type.
    /// \remarks Call only when holding the lock for the server mutex.
    void AssignProvider(const ResponseProviderPtr& provider, const std::string& path, const std::string& method)
    {
        httplib::Server::Handler handler = CreateHandler(provider);

        if (method == "Get")
        {
            _server.Get(path, std::move(handler));
        }
        else if (method == "Post")
        {
            _server.Post(path, std::move(handler));
        }
        else if (method == "Put")
        {
            _server.Put(path, std::move(handler));
        }
        else if (method == "Delete")
        {
            _server.Delete(path, std::move(handler));
        }
        else
        {
            throw std::invalid_argument("Unsupported HTTP method '" + method + "' in mock server");
        }
    }

    /// \brief Creates a request handler using the given response provider.
    /// \param provider The response provider.
    /// \return The request handler.
    httplib::Server::Handler CreateHandler(const ResponseProviderPtr& provider)
    {
        return {
            [this, &provider](const httplib::Request& req, httplib::Response& res)
            {
                if (provider->_response.has_value())
                {
                    Response& providerRes = provider->_response.value();

                    SetResponseStatusCode(res, providerRes);
                    SetResponseContent(res, providerRes);
                }

                ProcessNextMessage(req);
            }
        };
    }

    /// \brief Processes the next stubbed message in the queue.
    /// \param req The request.
    void ProcessNextMessage(const httplib::Request& req)
    {
        std::unique_lock<std::mutex> lock(_messagesMutex);

        if (_messageHandlers.empty())
        {
            return;
        }

        MessageHandler handler = _messageHandlers.front();
        _messageHandlers.pop();

        lock.unlock();

        FakePlatformRequest fakeReq;
        fakeReq.body = req.body;
        fakeReq.path = req.path;

        for (const auto& [k, v] : req.headers)
        {
            fakeReq.headers.emplace(k, v);
        }

        handler(fakeReq);
    }

    /// \brief Creates the URI for the server.
    /// \param port The port number.
    /// \return The URI.
    static std::string CreateUri(const int port)
    {
        std::stringstream ss;

        ss << "http://" << Host << ":" << port;

        return ss.str();
    }

    /// \brief Sets the content of the response.
    /// \param res The response.
    /// \param providerRes The response provider.
    static void SetResponseContent(httplib::Response& res, const Response& providerRes)
    {
        if (providerRes._body.has_value())
        {
            const std::string& body = providerRes._body.value();
            const std::map<std::string, std::string>& headers = providerRes._headers;
            auto iter = headers.find(ContentTypeKey);

            if (iter == headers.end())
            {
                res.set_content(body, DefaultContentType);
            }
            else
            {
                res.set_content(body, iter->second);
            }
        }
    }

    /// \brief Sets the status code of the response.
    /// \param res The response.
    /// \param providerRes The response provider.
    static void SetResponseStatusCode(httplib::Response& res, const Response& providerRes)
    {
        if (providerRes._statusCode.has_value())
        {
            res.status = providerRes._statusCode.value();
        }
    }
};

// endregion Impl

// region MockHttpServer

MockHttpServer::MockHttpServer()
    : _pimpl(std::make_unique<Impl>())
{
}

MockHttpServer::MockHttpServer(MockHttpServer&& other) noexcept = default;

MockHttpServer::~MockHttpServer() = default;

[[maybe_unused]]
const std::optional<std::string>& MockHttpServer::GetUri() const
{
    return _pimpl->GetUri();
}

[[maybe_unused]]
ResponseProvider& MockHttpServer::Given(const Request& request)
{
    return _pimpl->Given(request);
}

[[maybe_unused]]
void MockHttpServer::NextMessage(MessageHandler handler)
{
    _pimpl->NextMessage(std::move(handler));
}

[[maybe_unused]]
void MockHttpServer::Start()
{
    _pimpl->Start();
}

[[maybe_unused]]
void MockHttpServer::Stop()
{
    _pimpl->Stop();
}

MockHttpServer& MockHttpServer::operator=(MockHttpServer&& rhs) noexcept = default;

// endregion MockHttpServer
