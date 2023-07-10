#include "HttpLoggingHandler.hpp"

#include <algorithm>
#include <cctype>
#include <functional>
#include <sstream>
#include <stdexcept>
#include <utility>

// Do not use httplib namespace to avoid ambiguous references
using namespace enjin::platform::sdk;

[[maybe_unused]]
HttpLoggingHandler::HttpLoggingHandler(LoggerPtr logger, const HttpLogLevel level)
    : _level(level)
{
    if (logger == nullptr)
    {
        throw std::invalid_argument("Logger cannot be null");
    }

    _logger = std::move(logger);
}

[[maybe_unused]]
HttpLoggingHandler::HttpLoggingHandler(const HttpLoggingHandler& other) = default;

[[maybe_unused]]
HttpLoggingHandler::HttpLoggingHandler(HttpLoggingHandler&& other) noexcept = default;

HttpLoggingHandler::~HttpLoggingHandler() = default;

[[maybe_unused]]
void HttpLoggingHandler::LogRequest(const httplib::Request& request)
{
    std::stringstream ss;

    // Essential info
    const std::string method = ToUpper(request.method);
    const std::string& uri = request.path;
    const size_t contentLength = request.content_length_;

    // Basic
    if (_level == HttpLogLevel::Basic)
    {
        ss << "--> " << method << " " << uri << " (" << contentLength << "-byte body)";
        _logger->Log(TraceLevel, ss.str());

        return;
    }

    ss << "--> " << method << " " << uri << EndLine;

    // Headers
    for (const auto& [k, v] : request.headers)
    {
        ss << k << ": " << v << EndLine;
    }

    if (_level == HttpLogLevel::Headers)
    {
        ss << "<-- END " << method << " (" << contentLength << "-byte body)";

        _logger->Log(TraceLevel, ss.str());

        return;
    }

    // Body
    ss << EndLine // Line break between header(s) and body
       << request.body << EndLine
       << "<-- END " << method << " (" << contentLength << "-byte body)";

    _logger->Log(TraceLevel, ss.str());
}

[[maybe_unused]]
void HttpLoggingHandler::LogResponse(const httplib::Response& response)
{
    std::stringstream ss;

    // Essential info
    const int statusCode = response.status;
    const std::string& uri = response.location;

    // Basic
    ss << "<-- " << statusCode << " " << uri;

    if (_level == HttpLogLevel::Basic)
    {
        _logger->Log(TraceLevel, ss.str());

        return;
    }

    ss << EndLine;

    // Headers
    for (const auto& [k, v] : response.headers)
    {
        ss << k << ": " << v << EndLine;
    }

    if (_level == HttpLogLevel::Headers)
    {
        ss << "<-- END HTTP";

        _logger->Log(TraceLevel, ss.str());

        return;
    }

    // Body
    ss << EndLine // Line break between header(s) and body
       << response.body << EndLine
       << "<-- END HTTP";

    _logger->Log(TraceLevel, ss.str());
}

HttpLoggingHandler& HttpLoggingHandler::operator=(const HttpLoggingHandler& rhs) = default;

HttpLoggingHandler& HttpLoggingHandler::operator=(HttpLoggingHandler&& rhs) noexcept = default;

// Static

std::string HttpLoggingHandler::ToUpper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), std::ptr_fun<int, int>(std::toupper));

    return s;
}
