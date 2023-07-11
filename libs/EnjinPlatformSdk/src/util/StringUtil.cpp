#include "StringUtil.hpp"

#include <algorithm>
#include <cctype>

using namespace enjin::platform::sdk;

StringUtil::~StringUtil() = default;

[[maybe_unused]]
std::string StringUtil::ToLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](char ch) { return std::tolower(ch); });

    return s;
}

[[maybe_unused]]
std::string StringUtil::ToUpper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](char ch) { return std::toupper(ch); });

    return s;
}
