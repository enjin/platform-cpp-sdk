#ifndef ENJINPLATFORMSDK_PLATFORMCLIENT_HPP
#define ENJINPLATFORMSDK_PLATFORMCLIENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/HttpLogLevel.hpp"
#include "EnjinPlatformSdk/IJsonDeserializable.hpp"
#include "EnjinPlatformSdk/ILogger.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/PlatformRequest.hpp"
#include "EnjinPlatformSdk/PlatformResponse.hpp"
#include <future>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <utility>

namespace enjin::platform::sdk
{
class PlatformClient;

/// \brief Definition for a pointer containing a PlatformClient.
using PlatformClientPtr = std::unique_ptr<PlatformClient>;

/// \brief Client class for sending and receiving data with the platform.
class ENJINPLATFORMSDK_EXPORT PlatformClient final
{
    /// \brief Implementation for this class.
    class Impl;

    /// \brief Struct representing the result of an HTTP request.
    struct Result
    {
        std::string body;
        std::map<std::string, std::string> headers;
        int status;
    };

    std::unique_ptr<Impl> _pimpl;

public:
    class PlatformClientBuilder;

    PlatformClient() = delete;

    PlatformClient(const PlatformClient&) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    PlatformClient(PlatformClient&& other) noexcept;

    /// \brief Class destructor.
    ~PlatformClient();

    /// \brief Sets the authentication token to be used by this client.
    /// \param token The authentication token.
    [[maybe_unused]]
    void Auth(std::string token);

    /// \brief Returns the base address of the platform used by this client.
    /// \return The base address.
    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetBaseAddress() const;

    /// \brief Returns the value of the User-Agent header this client uses in requests to the platform.
    /// \return The value of the User-Agent header.
    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetUserAgent() const;

    /// \brief Returns whether this client has an authentication token.
    /// \return Whether this client has an authentication token.
    [[maybe_unused]]
    [[nodiscard]]
    bool IsAuthenticated() const;

    /// \brief Sends the given platform request.
    /// \tparam TResult The type of the result in the response. Must implement IJsonDeserializable.
    /// \param request The platform request.
    /// \return The future containing the response.
    template<class TResult>
    [[maybe_unused]]
    [[nodiscard]]
    std::future<PlatformResponsePtr<TResult>> SendRequest(PlatformRequestPtr request)
    {
        static_assert(std::is_base_of<IJsonDeserializable, TResult>::value,
                      "Type T does not implement IJsonDeserializable");

        return std::async([this, request = std::move(request)]() {
            Result result = SendRequestHelper(request);

            TResult t;
            t.Deserialize(JsonValue::FromJson(result.body));

            return std::shared_ptr<IPlatformResponse<TResult>>(
                new PlatformResponse<TResult>(result.status, result.headers, std::move(t)));
        });
    }

    PlatformClient& operator=(const PlatformClient&) = delete;

    PlatformClient& operator=(PlatformClient&& rhs) noexcept;

    /// \brief Creates a builder instance to be used for creating an instance of this class.
    /// \return The builder instance.
    [[maybe_unused]]
    static PlatformClientBuilder Builder();

    /// \brief The builder class for defining and creating a new instance of the PlatformClient class.
    class ENJINPLATFORMSDK_EXPORT PlatformClientBuilder final
    {
        std::optional<std::string> _baseAddress;
        std::optional<HttpLogLevel> _httpLogLevel;
        std::optional<LoggerPtr> _logger;
        std::optional<std::string> _userAgent;

    public:
        /// \brief Class destructor.
        ~PlatformClientBuilder();

        /// \brief Builds an instance of PlatformClient using the set parameters.
        /// \return The client instance.
        /// \throws std::logic_error Thrown if the base address is not set at the time this method is called.
        [[maybe_unused]]
        [[nodiscard]]
        PlatformClientPtr Build() const;

        /// \brief Sets the URI for the client to use as the base address for the platform.
        /// \param baseAddress The base address.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformClientBuilder& SetBaseAddress(std::string baseAddress);

        /// \brief Sets the HTTP log level for the client to use when processing HTTP traffic.
        /// \param httpLogLevel The HTTP log level.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformClientBuilder& SetHttpLogLevel(HttpLogLevel httpLogLevel);

        /// \brief Sets the logger
        /// \param logger The logger.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformClientBuilder& SetLogger(LoggerPtr logger);

        /// \brief Sets the value of the User-Agent header that the client will use when sending requests to the
        /// platform.
        /// \param userAgent The User-Agent value.
        /// \return This builder for chaining.
        /// \remarks If this value is not set when the client is built, then the User-Agent will be supplied as
        /// `Platform Enjin CPlusPlus SDK v{SDK_VERSION}`.
        [[maybe_unused]]
        PlatformClientBuilder& SetUserAgent(std::string userAgent);

    private:
        /// \brief Constructs an instance of this class.
        [[maybe_unused]]
        PlatformClientBuilder();

        friend PlatformClientBuilder PlatformClient::Builder();
    };

private:
    /// \brief Constructs an instance of this class.
    /// \param baseAddress The base address for the client.
    /// \param userAgent The User-Agent value for the client.
    /// \param logger The logger for the client.
    /// \param httpLogLevel The HTTP log level for HTTP traffic.
    PlatformClient(std::string baseAddress, std::string userAgent, LoggerPtr logger, HttpLogLevel httpLogLevel);

    /// \brief Helper class for sending requests to the platform.
    /// \param request The platform request.
    /// \return The result data of the request.
    [[nodiscard]]
    Result SendRequestHelper(const PlatformRequestPtr& request);
};
}

#endif //ENJINPLATFORMSDK_PLATFORMCLIENT_HPP
