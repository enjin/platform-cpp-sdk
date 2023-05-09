#include "FakePlatformRequest.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
FakePlatformRequest::FakePlatformRequest() = default;

FakePlatformRequest::~FakePlatformRequest() = default;

[[maybe_unused]]
const std::optional<std::string>& FakePlatformRequest::GetBody() const
{
    return body;
}

[[maybe_unused]]
const std::string& FakePlatformRequest::GetContentType() const
{
    return contentType;
}

[[maybe_unused]]
const std::map<std::string, std::string>& FakePlatformRequest::GetHeaders() const
{
    return headers;
}

[[maybe_unused]]
const std::optional<std::vector<MultipartFormData>>& FakePlatformRequest::GetMultipartFormData() const
{
    return multipartFormData;
}

[[maybe_unused]]
const std::string& FakePlatformRequest::GetPath() const
{
    return path;
}
