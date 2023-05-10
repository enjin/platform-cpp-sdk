//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
