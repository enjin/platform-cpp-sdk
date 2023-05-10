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

#ifndef ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP

#include <set>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Interface for GraphQL types which hold parameters for file uploads.
class IGraphQlUploadHolder
{
public:
    /// \brief Class destructor.
    virtual ~IGraphQlUploadHolder() = default;

    /// \brief Returns the path of the upload parameters.
    /// \return The parameter paths.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::set<std::string>& GetUploadParameterPaths() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP
