#include "FileUtil.hpp"

#include <sstream>
#include <stdexcept>

using namespace enjin::platform::sdk;

[[maybe_unused]]
std::string FileUtil::GetFileContent(std::ifstream& file)
{
    if (!file.is_open())
    {
        throw std::invalid_argument("File stream is not open");
    }

    std::stringstream ss;

    file.seekg(0);

    while (!file.eof())
    {
        std::string line;
        std::getline(file, line);

        ss << line;
    }

    file.seekg(0);

    return ss.str();
}
