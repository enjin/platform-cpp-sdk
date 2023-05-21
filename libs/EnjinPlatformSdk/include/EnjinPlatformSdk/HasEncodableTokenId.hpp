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

#ifndef ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP
#define ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP

#include "EnjinPlatformSdk/EncodableTokenIdInput.hpp"
#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter to set an encodable token ID.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasEncodableTokenId
{
public:
    /// \brief Class destructor.
    ~HasEncodableTokenId() = default;

    /// \brief Sets the token ID.
    /// \param tokenId The token ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    THolder& SetTokenId(EncodableTokenIdInputPtr tokenId)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("tokenId", std::move(tokenId));
    }

protected:
    /// \brief Constructs an instance of this class.
    HasEncodableTokenId() = default;
};
}

#endif //ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP
