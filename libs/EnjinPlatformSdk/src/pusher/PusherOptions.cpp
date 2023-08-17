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
