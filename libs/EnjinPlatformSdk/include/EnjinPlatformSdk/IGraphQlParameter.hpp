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

#ifndef ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <memory>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlParameter;

/// \brief Definition for a pointer containing a GraphQL parameter type.
using GraphQlParameterPtr [[maybe_unused]] = std::unique_ptr<IGraphQlParameter<>>;

/// \brief Interface for complex GraphQL parameters.
template<class...>
class IGraphQlParameter : virtual public IGraphQlParameterHolder<>,
                          virtual public IGraphQlUploadHolder,
                          virtual public ISerializable
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameter() override = default;
};

/// \brief Interface for setting inner parameters for complex GraphQL parameters.
/// \tparam TParameter The parameter type. Must implement this interface.
template<class TParameter>
class IGraphQlParameter<TParameter> : virtual public IGraphQlParameter<>,
                                      virtual public IGraphQlParameterHolder<TParameter>
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameter() override = default;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLPARAMETER_HPP
