//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
