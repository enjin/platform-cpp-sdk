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

#ifndef ENJINPLATFORMSDK_GRAPHQLUPLOADHOLDER_HPP
#define ENJINPLATFORMSDK_GRAPHQLUPLOADHOLDER_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IGraphQlUploadHolder.hpp"
#include <set>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL types which hold parameters for file uploads.
class ENJINPLATFORMSDK_EXPORT GraphQlUploadHolder : public IGraphQlUploadHolder
{
    std::set<std::string> _uploadPaths;

public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlUploadHolder(const GraphQlUploadHolder& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlUploadHolder(GraphQlUploadHolder&& other) noexcept;

    /// \brief Class destructor.
    ~GraphQlUploadHolder() override;

    GraphQlUploadHolder& operator=(const GraphQlUploadHolder& rhs);

    GraphQlUploadHolder& operator=(GraphQlUploadHolder&& rhs) noexcept;

    // region IGraphQlUploadHolder

    [[maybe_unused]]
    [[nodiscard]]
    const std::set<std::string>& GetUploadParameterPaths() const override;

    // endregion IGraphQlUploadHolder

protected:
    /// \brief Constructs an instance of this class.
    GraphQlUploadHolder();

    /// \brief Adds the given upload parameter key to this holder.
    /// \param key The parameter key.
    [[maybe_unused]]
    virtual void UploadAdded(const std::string& key);

    /// \brief Adds a parameter keys for an array of uploads.
    /// \param key The base name for the parameter.
    /// \param count The number of uploads in the array.
    [[maybe_unused]]
    virtual void UploadAdded(const std::string& key, int count);

    /// \brief Removes the given upload parameter key from this holder if present.
    /// \param key The parameter key.
    [[maybe_unused]]
    virtual void UploadRemoved(const std::string& key);
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLUPLOADHOLDER_HPP
