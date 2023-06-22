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
#include "gmock/gmock.h"
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
    Document document = RapidJsonUtil::StringToDocument(expected);

    // Act
    const std::string actual = RapidJsonUtil::DocumentToString(document);

    // Assert
    ASSERT_THAT(actual, Eq(expected));
}

TEST_F(RapidJsonUtilTest, SetDocumentMemberSetsValue)
{
    // Arrange
    const std::string expected(R"({"key":{"innerKey":"innerValue"}})");
    const std::string key("key");
    const Document value = RapidJsonUtil::StringToDocument(R"({"innerKey":"innerValue"})");
    Document document(kObjectType);

    // Assumptions
    ASSERT_THAT(value.IsObject(), IsTrue()) << "Assume that value is an object";

    // Act
    RapidJsonUtil::SetDocumentMember(document, key, value);

    // Assert
    ASSERT_THAT(RapidJsonUtil::DocumentToString(document), Eq(expected));
}

TEST_F(RapidJsonUtilTest, SetStringMemberSetsValue)
{
    // Arrange
    const std::string expected("value");
    const std::string key("key");
    const char* kStr = key.c_str();
    Document document(kObjectType);

    // Act
    RapidJsonUtil::SetStringMember(document, key, expected);

    // Assert
    ASSERT_THAT(document.HasMember(kStr), IsTrue()) << "Assert that document has member";
    ASSERT_THAT(document[kStr].IsString(), IsTrue()) << "Assert that member is a string";
    ASSERT_THAT(document[kStr].GetString(), Eq(expected)) << "Assert that member equals expected";
}

TEST_F(RapidJsonUtilTest, StringToDocumentGivenValidStringReturnsExpected)
{
    // Arrange
    const std::string expectedKey("key");
    const std::string expectedValue("value");
    const std::string s(R"({"key":"value"})");

    // Act
    const Document actual = RapidJsonUtil::StringToDocument(s);

    // Assert
    ASSERT_THAT(actual.HasMember(expectedKey.c_str()), IsTrue()) << "Assert that actual has member for expected key";
    ASSERT_THAT(actual[expectedKey.c_str()].IsString(), IsTrue()) << "Assert that member is a string";
    ASSERT_THAT(actual[expectedKey.c_str()].GetString(), Eq(expectedValue)) << "Assert that member has expected value";
}
