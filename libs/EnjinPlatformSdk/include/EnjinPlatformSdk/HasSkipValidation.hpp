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

#ifndef ENJINPLATFORMSDK_HASSKIPVALIDATION_HPP
#define ENJINPLATFORMSDK_HASSKIPVALIDATION_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set the skipValidation flag.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasSkipValidation
{
public:
    /// \brief Class destructor.
    ~HasSkipValidation() = default;

    /// \brief Sets whether to skip all validation rules, use with caution.
    /// \param skipValidation Whether to skip all validation rules.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetSkipValidation(SerializableBoolPtr skipValidation)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("skipValidation", std::move(skipValidation));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasSkipValidation() = default;
};
}

#endif //ENJINPLATFORMSDK_HASSKIPVALIDATION_HPP
