#ifndef ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP
#define ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP

#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
class IPlatformRequest;

/// \brief Definition for a pointer containing an IPlatformRequest.
using PlatformRequestPtr [[maybe_unused]] = std::shared_ptr<IPlatformRequest>;

/// \brief Interface for platform requests to implement.
class IPlatformRequest
{
public:
    /// \brief Class destructor.
    virtual ~IPlatformRequest() = default;

    /// \brief Returns the body of this request.
    /// \return The body.
    /// \remarks May be empty if this request has multipart form-data.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::optional<std::string>& GetBody() const = 0;

    /// \brief Returns the content-type of this request.
    /// \return The content-type.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::string& GetContentType() const = 0;

    /// \brief Returns the headers for this request.
    /// \return The headers.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, std::string>& GetHeaders() const = 0;

    /// \brief Returns the multipart forms-data for this request.
    /// \return The multipart form-data.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::optional<std::vector<MultipartFormData>>& GetMultipartFormData() const = 0;

    /// \brief Returns the relative path of this request.
    /// \return The relative path.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::string& GetPath() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IPLATFORMREQUEST_HPP
