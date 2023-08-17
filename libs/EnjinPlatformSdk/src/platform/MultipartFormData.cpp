#include "EnjinPlatformSdk/MultipartFormData.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
MultipartFormData::MultipartFormData() = default;

[[maybe_unused]]
MultipartFormData::MultipartFormData(std::string content,
                                     std::string contentName,
                                     std::string contentType,
                                     std::string fileName)
    : content(std::move(content)),
      contentName(std::move(contentName)),
      contentType(std::move(contentType)),
      fileName(std::move(fileName))
{
}

[[maybe_unused]]
MultipartFormData::MultipartFormData(const MultipartFormData& other) = default;

[[maybe_unused]]
MultipartFormData::MultipartFormData(MultipartFormData&& other) noexcept = default;

MultipartFormData::~MultipartFormData() = default;

MultipartFormData& MultipartFormData::operator=(const MultipartFormData& rhs) = default;

MultipartFormData& MultipartFormData::operator=(MultipartFormData&& rhs) noexcept = default;
