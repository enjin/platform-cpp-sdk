#ifndef ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP
#define ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP

#include <map>
#include <memory>
#include <optional>
#include <string>

namespace enjin::platform::sdk
{
template<class TResult>
class IPlatformResponse;

/// \brief Definition for a pointer containing an IPlatformResponse.
template<class TResult>
using PlatformResponsePtr = std::shared_ptr<IPlatformResponse<TResult>>;

/// \brief Interface for a response containing HTTP data that the platform sent in response to a request.
/// \tparam TResult The type of the result in the response.
template<class TResult>
class IPlatformResponse
{
public:
    /// \brief Class destructor.
    virtual ~IPlatformResponse() = default;

    /// \brief Returns the HTTP headers for this response.
    /// \return The HTTP headers.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, std::string>& GetHeaders() const = 0;

    /// \brief Returns the result that represents the body of this response.
    /// \return The result.
    virtual const std::optional<TResult>& GetResult() const = 0;

    /// \brief Returns the status code of this response.
    /// \return The status code.
    [[maybe_unused]]
    [[nodiscard]]
    virtual int GetStatusCode() const = 0;

    /// \brief Determines whether the status code of this response is in the success range [200-300).
    /// \return Whether the status code is in the success range.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool IsSuccessStatusCode() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IPLATFORMRESPONSE_HPP
