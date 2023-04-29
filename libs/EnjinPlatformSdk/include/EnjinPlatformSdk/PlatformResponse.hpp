#ifndef ENJINPLATFORMSDK_PLATFORMRESPONSE_HPP
#define ENJINPLATFORMSDK_PLATFORMRESPONSE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IPlatformResponse.hpp"
#include <map>
#include <string>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Contains HTTP data that the platform sent in response to a request.
/// \tparam TResult The type of the result in the response.
template<class TResult>
class PlatformResponse final : public IPlatformResponse<TResult>
{
    std::map<std::string, std::string> _headers;
    std::optional<TResult> _result;
    int _statusCode = 0;

public:
    /// \brief Constructs an instance of this class.
    PlatformResponse() = default;

    /// \brief Initializes a new instance of this class.
    /// \param statusCode The HTTP status code for the response.
    /// \param headers The HTTP headers for the response.
    /// \param result The result for the response.
    [[maybe_unused]]
    PlatformResponse(int statusCode, std::map<std::string, std::string> headers, std::optional<TResult> result)
        : _statusCode(statusCode),
          _headers(std::move(headers)),
          _result(std::move(result))
    {
    }

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PlatformResponse(const PlatformResponse& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PlatformResponse(PlatformResponse&& other) noexcept = default;

    /// \brief Class destructor.
    ~PlatformResponse() override = default;

    PlatformResponse& operator=(const PlatformResponse& rhs) = default;

    PlatformResponse& operator=(PlatformResponse&& rhs) noexcept = default;

    // region IPlatformResponse

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, std::string>& GetHeaders() const override
    {
        return _headers;
    }

    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<TResult>& GetResult() const override
    {
        return _result;
    }

    [[maybe_unused]]
    [[nodiscard]]
    int GetStatusCode() const override
    {
        return _statusCode;
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool IsSuccessStatusCode() const override
    {
        return _statusCode >= 200 && _statusCode < 300;
    }

    // endregion IPlatformResponse
};
}

#endif //ENJINPLATFORMSDK_PLATFORMRESPONSE_HPP
