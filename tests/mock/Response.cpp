#include "Response.hpp"

#include <utility>

Response::Response() = default;

Response::~Response() = default;

[[maybe_unused]]
Response& Response::WithBody(std::string body)
{
    _body = std::move(body);
    return *this;
}

[[maybe_unused]]
Response& Response::WithHeader(std::string key, std::string value)
{
    _headers.emplace(std::move(key), std::move(value));
    return *this;
}

[[maybe_unused]]
Response& Response::WithStatusCode(const int code)
{
    _statusCode = code;
    return *this;
}

[[maybe_unused]]
Response& Response::WithSuccess()
{
    _statusCode = 200;
    return *this;
}

// Static

[[maybe_unused]]
Response Response::Create()
{
    return {};
}
