#ifndef ENJINPLATFORMSDK_FAKEPLATFORMREQUEST_HPP
#define ENJINPLATFORMSDK_FAKEPLATFORMREQUEST_HPP

#include "EnjinPlatformSdk/IPlatformRequest.hpp"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Class representing a fake platform request.
class FakePlatformRequest : public IPlatformRequest
{
public:
    /// \brief The body of this request.
    std::optional<std::string> body;

    /// \brief The content-type of this request.
    std::string contentType;

    /// \brief The headers of this request.
    std::map<std::string, std::string> headers;

    /// \brief The multipart form-data of this request.
    std::optional<std::vector<MultipartFormData>> multipartFormData;

    /// \brief The path of this request.
    std::string path;

    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    FakePlatformRequest();

    /// \brief Class destructor.
    ~FakePlatformRequest() override;

    // region IPlatformRequest

    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetBody() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetContentType() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, std::string>& GetHeaders() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<MultipartFormData>>& GetMultipartFormData() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetPath() const override;

    // endregion IPlatformRequest
};
}

#endif //ENJINPLATFORMSDK_FAKEPLATFORMREQUEST_HPP
