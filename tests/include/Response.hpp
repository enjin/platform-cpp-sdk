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
