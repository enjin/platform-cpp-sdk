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

#ifndef ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
#define ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "rapidjson/document.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for RapidJSON functions.
class ENJINPLATFORMSDK_EXPORT RapidJsonUtil final
{
public:
    RapidJsonUtil() = delete;

    /// \brief Converts the content of the given document into a string.
    /// \param document The document.
    /// \return The stringified contents of the document.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string DocumentToString(const rapidjson::Document& document);
};
}

#endif //ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
