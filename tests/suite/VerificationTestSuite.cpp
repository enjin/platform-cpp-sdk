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
//    _cv.notify_all();
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
