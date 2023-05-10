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

#ifndef ENJINPLATFORMSDK_FILEUTIL_HPP
#define ENJINPLATFORMSDK_FILEUTIL_HPP

#include "enjinplatformsdk_export.h"
#include <fstream>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for file processing.
class ENJINPLATFORMSDK_EXPORT FileUtil final
{
public:
    FileUtil() = delete;

    /// \brief Gets the content of the given file.
    /// \param file The in stream of the file.
    /// \return The file content.
    /// \throws std::invalid_argument If the given stream is not open.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string GetFileContent(std::ifstream& file);
};
}

#endif //ENJINPLATFORMSDK_FILEUTIL_HPP
