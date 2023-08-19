#include "EnjinPlatformSdk/PlatformClient.hpp"

#include "httplib.h"
#include "HttpLoggingHandler.hpp"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>

// Do not use httplib namespace to avoid ambiguous references
using namespace enjin::platform::sdk;
using PlatformClientBuilder = PlatformClient::PlatformClientBuilder;

// region Impl

class PlatformClient::Impl
{
    std::optional<std::string> _authToken;
    const std::string _baseAddress;
    const std::string _userAgent;

    std::unique_ptr<httplib::Client> _client;
    std::unique_ptr<HttpLoggingHandler> _httpLoggingHandler;

    // Mutexes
    mutable std::mutex _authTokenMutex;

    static constexpr char MediaType[] = "application/json";

public:
    Impl(std::string baseAddress, std::string userAgent, LoggerPtr logger, const HttpLogLevel httpLogLevel)
        : _baseAddress(std::move(baseAddress)),
          _userAgent(std::move(userAgent))
    {
        _client = std::make_unique<httplib::Client>(_baseAddress);
        _client->set_follow_location(true);
        _client->set_keep_alive(true);

        if (logger != nullptr && httpLogLevel != HttpLogLevel::None)
        {
            _httpLoggingHandler = std::make_unique<HttpLoggingHandler>(std::move(logger), httpLogLevel);

            _client->set_logger([this](const httplib::Request& req, const httplib::Response& res) {
                _httpLoggingHandler->LogRequest(req);
                _httpLoggingHandler->LogResponse(res);
            });
        }
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

        httplib::Result httpResult = request->GetMultipartFormData().has_value()
                                     ? _client->Post(path, headers, CreateFormItems(request))
                                     : _client->Post(path, headers, request->GetBody().value(), MediaType);

        return ConvertResult(httpResult);
    }

private:
    /// \brief Creates cpp-httplib request headers from the given platform request and the authorization token if set.
    /// \param request The platform request.
    /// \return The request headers.
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

    /// \brief Converts a cpp-httplib result into a platform result.
    /// \param httpResult The cpp-httplib result.
    /// \return The platform result.
    static Result ConvertResult(const httplib::Result& httpResult)
    {
        Result platformResult;
        platformResult.status = httpResult->status;
        platformResult.body = httpResult->body;

        for (const auto& [k, v] : httpResult->headers)
        {
            platformResult.headers.emplace(k, v);
        }

        return platformResult;
    }

    /// \brief Creates the cpp-httplib multipart form-data items from the given platform request.
    /// \param request The platform request.
    /// \return The multipart form-data items.
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
};

// endregion Impl

// region PlatformClient

[[maybe_unused]]
PlatformClient::PlatformClient(std::string baseAddress,
                               std::string userAgent,
                               LoggerPtr logger,
                               const HttpLogLevel httpLogLevel)
    : _pimpl(std::make_unique<Impl>(std::move(baseAddress),
                                    std::move(userAgent),
                                    std::move(logger),
                                    httpLogLevel))
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
PlatformClientBuilder PlatformClient::Builder()
{
    return {};
}

// endregion PlatformClient

// region PlatformClientBuilder

PlatformClientBuilder::PlatformClientBuilder() = default;

PlatformClientBuilder::~PlatformClientBuilder() = default;

[[maybe_unused]]
PlatformClientPtr PlatformClientBuilder::Build() const
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

    return std::unique_ptr<PlatformClient>(new PlatformClient(_baseAddress.value(),
                                                              userAgentStream.str(),
                                                              _logger.value_or(nullptr),
                                                              _httpLogLevel.value_or(HttpLogLevel::None)));
}

[[maybe_unused]]
PlatformClientBuilder& PlatformClientBuilder::SetBaseAddress(std::string baseAddress)
{
    _baseAddress = std::move(baseAddress);
    return *this;
}

[[maybe_unused]]
PlatformClientBuilder& PlatformClientBuilder::SetHttpLogLevel(const HttpLogLevel httpLogLevel)
{
    _httpLogLevel = httpLogLevel;
    return *this;
}

[[maybe_unused]]
PlatformClientBuilder& PlatformClientBuilder::SetLogger(LoggerPtr logger)
{
    _logger = std::move(logger);
    return *this;
}

[[maybe_unused]]
PlatformClientBuilder& PlatformClientBuilder::SetUserAgent(std::string userAgent)
{
    _userAgent = std::move(userAgent);
    return *this;
}

// endregion PlatformClientBuilder
