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

#ifndef ENJINPLATFORMSDK_MULTIPARTFORMDATA_HPP
#define ENJINPLATFORMSDK_MULTIPARTFORMDATA_HPP

#include "enjinplatformsdk_export.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Struct representing multipart form-data of an HTTP request.
struct ENJINPLATFORMSDK_EXPORT MultipartFormData final
{
    /// \brief The content of this form.
    std::string content;

    /// \brief The name of the content for this form.
    std::string contentName;

    /// \brief The content-type of this form.
    std::string contentType;

    /// \brief The filename of this form.
    std::string fileName;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    MultipartFormData();

    /// \brief Constructs an instance of this struct with the given form data.
    /// \param content The content of the form.
    /// \param contentName The name of the content for the form.
    /// \param contentType The content-type of the form.
    /// \param fileName The filename of the form.
    [[maybe_unused]]
    MultipartFormData(std::string content, std::string contentName, std::string contentType, std::string fileName);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MultipartFormData(const MultipartFormData& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MultipartFormData(MultipartFormData&& other) noexcept;

    /// \brief Struct destructor.
    ~MultipartFormData();

    MultipartFormData& operator=(const MultipartFormData& rhs);

    MultipartFormData& operator=(MultipartFormData&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MULTIPARTFORMDATA_HPP
