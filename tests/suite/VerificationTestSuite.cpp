#include "VerificationTestSuite.hpp"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <chrono>

using namespace testing;
using Clock = std::chrono::high_resolution_clock;
using Milliseconds = std::chrono::milliseconds;

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
void VerificationTestSuite::Verify()
{
    std::lock_guard<std::mutex> guard(_countMutex);

    VerifyImpl();
}

[[maybe_unused]]
void VerificationTestSuite::Verify(Milliseconds timeout)
{
    std::unique_lock<std::mutex> lock(_countMutex);

    while (_callCounter != _expectedCount && timeout > Milliseconds::zero())
    {
        const auto start = Clock::now();

        _cv.wait_for(lock, timeout, [this]() {
            return _callCounter == _expectedCount;
        });

        const auto end = Clock::now();
        timeout -= std::chrono::duration_cast<Milliseconds>(end - start);
    }

    VerifyImpl();
}

[[maybe_unused]]
void VerificationTestSuite::Verify(const unsigned int milliseconds)
{
    Verify(Milliseconds(milliseconds));
}

void VerificationTestSuite::VerifyImpl()
{
    EXPECT_THAT(_callCounter, Eq(_expectedCount)) << "Verify the expected number of calls were made";
}
