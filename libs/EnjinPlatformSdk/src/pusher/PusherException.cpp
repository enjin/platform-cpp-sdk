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

#include "PusherException.hpp"
#include <sstream>

using namespace pusher;

[[maybe_unused]]
PusherException::PusherException(const int code, const std::string& message)
    : _code(code)
{
    std::stringstream ss;

    ss << code << ": " << message;

    _what = ss.str();
}

[[maybe_unused]]
PusherException::PusherException(const PusherException& other) = default;

[[maybe_unused]]
PusherException::PusherException(PusherException&& other) noexcept = default;

PusherException::~PusherException() = default;

[[maybe_unused]]
int PusherException::GetCode() const
{
    return _code;
}

PusherException& PusherException::operator=(const PusherException& rhs) = default;

PusherException& PusherException::operator=(PusherException&& rhs) noexcept = default;

// region exception

[[maybe_unused]]
const char* PusherException::what() const noexcept
{
    return _what.c_str();
}

// endregion exception
