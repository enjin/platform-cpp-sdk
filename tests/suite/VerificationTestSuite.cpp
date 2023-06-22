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

#include "VerificationTestSuite.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <chrono>

using namespace testing;

[[maybe_unused]]
VerificationTestSuite::VerificationTestSuite() = default;

VerificationTestSuite::~VerificationTestSuite() = default;

[[maybe_unused]]
void VerificationTestSuite::IncrementCallCount()
{
    std::lock_guard<std::mutex> guard(_countMutex);

    _callCounter++;
    _cv.notify_all();
}

[[maybe_unused]]
void VerificationTestSuite::SetExpectedCallCount(const int count)
{
    std::lock_guard<std::mutex> guard(_countMutex);

    _expectedCount = count;
}

[[maybe_unused]]
void VerificationTestSuite::Verify(const int milliseconds)
{
    std::unique_lock<std::mutex> lock(_countMutex);

    if (_callCounter != _expectedCount)
    {
        _cv.wait_for(lock, std::chrono::milliseconds(milliseconds), [this]()
        {
            return _callCounter == _expectedCount;
        });
    }

    EXPECT_THAT(_callCounter, Eq(_expectedCount)) << "Verify the expected number of calls were made";
}
