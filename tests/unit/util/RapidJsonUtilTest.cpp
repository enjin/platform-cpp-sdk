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

#include "gtest/gtest.h"
#include "RapidJsonUtil.hpp"
#include "rapidjson/document.h"
#include <string>

using namespace enjin::platform::sdk;
using namespace rapidjson;
using namespace testing;

class RapidJsonUtilTest : public Test
{
};

TEST_F(RapidJsonUtilTest, DocumentToString)
{
    // Arrange
    const std::string expected(R"({"key":"value"})");
    Document document;
    document.Parse(expected.c_str());

    // Act
    const std::string actual = RapidJsonUtil::DocumentToString(document);

    // Assert
    ASSERT_EQ(actual, expected);
}
