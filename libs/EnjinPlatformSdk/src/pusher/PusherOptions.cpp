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

#include "PusherOptions.hpp"

#include <sstream>

using namespace pusher;

[[maybe_unused]]
PusherOptions::PusherOptions() = default;

[[maybe_unused]]
PusherOptions::PusherOptions(const PusherOptions& other) = default;

[[maybe_unused]]
PusherOptions::PusherOptions(PusherOptions&& other) noexcept = default;

PusherOptions::~PusherOptions() = default;

[[maybe_unused]]
std::string PusherOptions::GetHost() const
{
    if (_host.has_value())
    {
        return _host.value();
    }

    std::stringstream ss;

    ss << "ws-" << _cluster.value_or(DefaultCluster) << ".pusher.com";

    return ss.str();
}

[[maybe_unused]]
bool PusherOptions::IsEncrypted() const
{
    return _encrypted.value_or(DefaultEncryption);
}

[[maybe_unused]]
PusherOptions& PusherOptions::SetCluster(std::string cluster)
{
    _cluster = std::move(cluster);
    _host.reset();

    return *this;
}

[[maybe_unused]]
PusherOptions& PusherOptions::SetEncrypted(const bool isEncrypted)
{
    _encrypted = isEncrypted;

    return *this;
}

[[maybe_unused]]
PusherOptions& PusherOptions::SetHost(std::string host)
{
    _host = std::move(host);
    _cluster.reset();

    return *this;
}

PusherOptions& PusherOptions::operator=(const PusherOptions& rhs) = default;

PusherOptions& PusherOptions::operator=(PusherOptions&& rhs) noexcept = default;
