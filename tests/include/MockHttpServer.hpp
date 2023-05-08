#ifndef ENJINPLATFORMSDK_MOCKHTTPSERVER_HPP
#define ENJINPLATFORMSDK_MOCKHTTPSERVER_HPP

#include "Request.hpp"
#include "RequestMessage.hpp"
#include "Response.hpp"
#include "ResponseMessage.hpp"
#include "ResponseProvider.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include <functional>
#include <memory>
#include <string>
#include <vector>

/// \brief Definition for message handlers.
using MessageHandler = std::function<void(const enjin::platform::sdk::IPlatformRequest&)>;

/// \brief Mock HTTP server for testing HTTP requests.
class MockHttpServer final
{
    /// \brief Implementation for this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    /// \throws std::runtime_error Thrown if the server cannot set its base directory or is invalid in some other way.
    [[maybe_unused]]
    MockHttpServer();

    MockHttpServer(const MockHttpServer& other) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MockHttpServer(MockHttpServer&& other) noexcept;

    /// \brief Class destructor.
    ~MockHttpServer();

    /// \brief Returns the URI for this server.
    /// \return The URI.
    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetUri() const;

    /// \brief Sets this server to respond for a given request.
    /// \param request The request.
    /// \return The response provider to be setup with the stubbed response.
    /// \throws std::invalid_argument Thrown if request does not have a path or HTTP method.
    [[maybe_unused]]
    ResponseProvider& Given(const Request& request);

    /// \brief Setup a handler for the next message received by this server. Intended for use establishing expectations.
    /// \param handler The message handler.
    /// \remarks This server will only use the handler on a new message received by it and will not retroactively apply
    /// the handler to any messages it received in the past.
    [[maybe_unused]]
    void NextMessage(MessageHandler handler);

    /// \brief Starts this server.
    [[maybe_unused]]
    void Start();

    /// \brief Stops this server.
    [[maybe_unused]]
    void Stop();

    MockHttpServer& operator=(const MockHttpServer& rhs) = delete;

    MockHttpServer& operator=(MockHttpServer&& rhs) noexcept;
};

#endif //ENJINPLATFORMSDK_MOCKHTTPSERVER_HPP
