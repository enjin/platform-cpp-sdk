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

#ifndef ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP
#define ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP

namespace enjin::platform::sdk
{
/// \brief Represents the types a GraphQL request may be.
enum class GraphQlRequestType
{
    Mutation, ///< Value for a mutation type of request.
    Query, ///< Value for a query type of request.
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP
