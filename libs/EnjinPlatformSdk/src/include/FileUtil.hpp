#ifndef ENJINPLATFORMSDK_FILEUTIL_HPP
#define ENJINPLATFORMSDK_FILEUTIL_HPP

#include "enjinplatformsdk_export.h"
#include <fstream>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for file processing.
class ENJINPLATFORMSDK_EXPORT FileUtil final
{
public:
    FileUtil() = delete;

    /// \brief Gets the content of the given file.
    /// \param file The in stream of the file.
    /// \return The file content.
    /// \throws std::invalid_argument If the given stream is not open.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string GetFileContent(std::ifstream& file);
};
}

#endif //ENJINPLATFORMSDK_FILEUTIL_HPP
