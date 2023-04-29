#ifndef ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
#define ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "rapidjson/document.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for RapidJSON functions.
class ENJINPLATFORMSDK_EXPORT RapidJsonUtil final
{
public:
    RapidJsonUtil() = delete;

    /// \brief Converts the content of the given document into a string.
    /// \param document The document.
    /// \return The stringified contents of the document.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string DocumentToString(const rapidjson::Document& document);
};
}

#endif //ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
