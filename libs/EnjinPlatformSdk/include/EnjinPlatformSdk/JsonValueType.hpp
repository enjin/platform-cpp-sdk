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

#ifndef ENJINPLATFORMSDK_JSONVALUETYPE_HPP
#define ENJINPLATFORMSDK_JSONVALUETYPE_HPP

namespace enjin::platform::sdk
{
/// \brief Values representing the types of a JSON value.
enum class JsonValueType
{
    Null, ///< Represents a null value.
    Array, ///< Represents an array value.
    Object, ///< Represents an object value.
    String, ///< Represents a string value.
    Bool, ///< Represents a boolean value.
    Number, ///< Represents a number value.
};
}

#endif //ENJINPLATFORMSDK_JSONVALUETYPE_HPP
