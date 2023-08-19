#ifndef ENJINPLATFORMSDK_STRINGUTIL_HPP
#define ENJINPLATFORMSDK_STRINGUTIL_HPP

#include "enjinplatformsdk_export.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for RapidJSON functions.
class ENJINPLATFORMSDK_EXPORT StringUtil final
{
public:
    StringUtil() = delete;

    /// \brief Converts the given string to all lowercase.
    /// \param s The string.
    /// \return The converted string.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string ToLower(std::string s);

    /// \brief Converts the given string to all uppercase.
    /// \param s The string.
    /// \return The converted string.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string ToUpper(std::string s);
};
}

#endif //ENJINPLATFORMSDK_STRINGUTIL_HPP
