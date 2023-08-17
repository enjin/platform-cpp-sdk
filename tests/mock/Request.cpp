#include "Request.hpp"

#include <utility>

Request::Request() = default;

Request::~Request() = default;

[[maybe_unused]]
Request& Request::UsingDelete()
{
    _method = "Delete";
    return *this;
}

[[maybe_unused]]
Request& Request::UsingGet()
{
    _method = "Get";
    return *this;
}

[[maybe_unused]]
Request& Request::UsingPost()
{
    _method = "Post";
    return *this;
}

[[maybe_unused]]
Request& Request::UsingPut()
{
    _method = "Put";
    return *this;
}

[[maybe_unused]]
Request& Request::WithBody(std::string body)
{
    _body = std::move(body);
    return *this;
}

[[maybe_unused]]
Request& Request::WithPath(std::string path)
{
    _path = std::move(path);
    return *this;
}

bool Request::operator==(const Request& rhs) const
{
    return _path == rhs._path
           && _method == rhs._method;
}

bool Request::operator!=(const Request& rhs) const
{
    return !(*this == rhs);
}

bool Request::operator<(const Request& rhs) const
{
    if (_path < rhs._path)
    {
        return true;
    }
    else if (_path > rhs._path)
    {
        return false;
    }

    return _method < rhs._method;
}

bool Request::operator>(const Request& rhs) const
{
    return rhs < *this;
}

bool Request::operator<=(const Request& rhs) const
{
    return !(*this > rhs);
}

bool Request::operator>=(const Request& rhs) const
{
    return rhs <= *this;
}

// Static

[[maybe_unused]]
Request Request::Create()
{
    return {};
}
