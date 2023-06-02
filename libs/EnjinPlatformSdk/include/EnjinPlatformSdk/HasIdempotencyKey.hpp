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

#ifndef ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP
#define ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set an idempotency key.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasIdempotencyKey
{
public:
    /// \brief Class destructor.
    ~HasIdempotencyKey() = default;

    /// \brief Sets the idempotency key to set. It is recommended to use a UUID for this.
    /// \param idempotencyKey The idempotency key.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetIdempotencyKey(SerializableStringPtr idempotencyKey)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("idempotencyKey", std::move(idempotencyKey));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasIdempotencyKey() = default;
};
}

#endif //ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP
