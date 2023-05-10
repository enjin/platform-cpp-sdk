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

#include "EnjinPlatformSdk/PlatformClient.hpp"

#include "httplib.h"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>

// Do not use httplib namespace to avoid ambiguous references
using namespace enjin::platform::sdk;

// region Impl

class PlatformClient::Impl
{
    std::optional<std::string> _authToken;
    const std::string _baseAddress;
    const std::string _userAgent;

    std::unique_ptr<httplib::Client> _client;

    // Mutexes
    mutable std::mutex _authTokenMutex;

    static constexpr char MediaType[] = "application/json";

public:
    Impl(std::string baseAddress, std::string userAgent)
        : _baseAddress(std::move(baseAddress)),
          _userAgent(std::move(userAgent))
    {
        _client = std::make_unique<httplib::Client>(_baseAddress);
        _client->set_follow_location(true);
        _client->set_keep_alive(true);
    }

    ~Impl()
    {
        _client->stop();
    }

    void Auth(std::string token)
    {
        std::lock_guard<std::mutex> guard(_authTokenMutex);
        _authToken = std::move(token);
    }

    [[nodiscard]]
    const std::string& GetBaseAddress() const
    {
        return _baseAddress;
    }

    [[nodiscard]]
    const std::string& GetUserAgent() const
    {
        return _userAgent;
    }

    [[nodiscard]]
    bool IsAuthenticated() const
    {
        std::lock_guard<std::mutex> guard(_authTokenMutex);
        return _authToken.has_value();
    }

    [[nodiscard]]
    Result SendRequest(const PlatformRequestPtr& request)
    {
        const std::string path = request->GetPath();
        const httplib::Headers headers = CreateHeaders(request);
        Result result;

        if (request->GetMultipartFormData().has_value())
        {
            httplib::Result r = _client->Post(path, headers, CreateFormItems(request));
            SetResultFields(r, result);
        }
        else
        {
            httplib::Result r = _client->Post(path, headers, request->GetBody().value(), MediaType);
            SetResultFields(r, result);
        }

        return result;
    }

private:
    httplib::Headers CreateHeaders(const PlatformRequestPtr& request)
    {
        httplib::Headers headers;

        // Set Authorization header
        {
            std::lock_guard<std::mutex> guard(_authTokenMutex);

            if (_authToken.has_value())
            {
                headers.emplace("Authorization", _authToken.value());
            }
        }

        // Set User-Agent header
        headers.emplace("User-Agent", _userAgent);

        // Set headers from the request
        for (const auto& [k, v] : request->GetHeaders())
        {
            headers.emplace(k, v);
        }

        return headers;
    }

    static httplib::MultipartFormDataItems CreateFormItems(const PlatformRequestPtr& request)
    {
        httplib::MultipartFormDataItems items;

        for (const MultipartFormData& form : request->GetMultipartFormData().value())
        {
            httplib::MultipartFormData f;
            f.name = form.contentName;
            f.content = form.content;
            f.filename = form.fileName;
            f.content_type = form.contentType;

            items.push_back(std::move(f));
        }

        return items;
    }

    static void SetResultFields(const httplib::Result& httpResult, Result& outResult)
    {
        outResult.status = httpResult->status;
        outResult.body = httpResult->body;

        for (const auto& [k, v] : httpResult->headers)
        {
            outResult.headers.emplace(k, v);
        }
    }
};

// endregion Impl

// region PlatformClient

[[maybe_unused]]
PlatformClient::PlatformClient(std::string baseAddress, std::string userAgent)
    : _pimpl(std::make_unique<Impl>(std::move(baseAddress), std::move(userAgent)))
{
}

[[maybe_unused]]
PlatformClient::PlatformClient(PlatformClient&& other) noexcept = default;

PlatformClient::~PlatformClient() = default;

[[maybe_unused]]
void PlatformClient::Auth(std::string token)
{
    _pimpl->Auth(std::move(token));
}

[[maybe_unused]]
const std::string& PlatformClient::GetBaseAddress() const
{
    return _pimpl->GetBaseAddress();
}

[[maybe_unused]]
const std::string& PlatformClient::GetUserAgent() const
{
    return _pimpl->GetUserAgent();
}

[[maybe_unused]]
bool PlatformClient::IsAuthenticated() const
{
    return _pimpl->IsAuthenticated();
}

PlatformClient::Result PlatformClient::SendRequestHelper(const PlatformRequestPtr& request)
{
    return _pimpl->SendRequest(request);
}

PlatformClient& PlatformClient::operator=(PlatformClient&& rhs) noexcept = default;

// Static

[[maybe_unused]]
PlatformClient::PlatformClientBuilder PlatformClient::Builder()
{
    return {};
}

// endregion PlatformClient

// region PlatformClientBuilder

PlatformClient::PlatformClientBuilder::PlatformClientBuilder() = default;

PlatformClient::PlatformClientBuilder::~PlatformClientBuilder() = default;

[[maybe_unused]]
std::unique_ptr<PlatformClient> PlatformClient::PlatformClientBuilder::Build() const
{
    if (!_baseAddress.has_value())
    {
        throw std::logic_error("Cannot build PlatformClient without a base address");
    }

    std::stringstream userAgentStream;

    if (_userAgent.has_value())
    {
        userAgentStream << _userAgent.value();
    }
    else
    {
        userAgentStream << "Platform Enjin CPlusPlus SDK";

#ifdef ENJINPLATFORMSDK_VERSION
        userAgentStream << " v" << ENJINPLATFORMSDK_VERSION;
#endif
    }

    return std::unique_ptr<PlatformClient>(new PlatformClient(_baseAddress.value(), userAgentStream.str()));
}

[[maybe_unused]]
PlatformClient::PlatformClientBuilder& PlatformClient::PlatformClientBuilder::SetBaseAddress(std::string baseAddress)
{
    _baseAddress = std::move(baseAddress);
    return *this;
}

[[maybe_unused]]
PlatformClient::PlatformClientBuilder& PlatformClient::PlatformClientBuilder::SetUserAgent(std::string userAgent)
{
    _userAgent = std::move(userAgent);
    return *this;
}

// endregion PlatformClientBuilder
