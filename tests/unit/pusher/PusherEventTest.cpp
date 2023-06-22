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
#include "PusherEvent.hpp"
#include <string>

using namespace pusher;
using namespace testing;

class PusherEventTest : public Test
{
};

TEST_F(PusherEventTest, ConstructionWhenJsonIsEmptyHasNoFields)
{
    // Arrange
    const std::string json;

    // Act
    const PusherEvent actual(json);

    // Assert
    EXPECT_THAT(actual.GetChannelName().has_value(), IsFalse()) << "Expect channel name optional is empty";
    EXPECT_THAT(actual.GetData().has_value(), IsFalse()) << "Expect data optional is empty";
    EXPECT_THAT(actual.GetEventName().has_value(), IsFalse()) << "Expect event name optional is empty";
    EXPECT_THAT(actual.GetUserId().has_value(), IsFalse()) << "Expect user ID optional is empty";
}

TEST_F(PusherEventTest, ConstructionWhenJsonIsPopulatedHasFields)
{
    // Arrange
    const std::string expected("xyz");
    const std::string json(R"({"channel":"xyz","data":"xyz","event":"xyz","user_id":"xyz"})");

    // Act
    const PusherEvent actual(json);

    // Assert
    EXPECT_THAT(actual.GetChannelName().value(), Eq(expected)) << "Expect channel name equals expected";
    EXPECT_THAT(actual.GetData().value(), Eq(expected)) << "Expect data equals expected";
    EXPECT_THAT(actual.GetEventName().value(), Eq(expected)) << "Expect event name equals expected";
    EXPECT_THAT(actual.GetUserId().value(), Eq(expected)) << "Expect user ID equals expected";
}
