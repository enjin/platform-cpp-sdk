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
