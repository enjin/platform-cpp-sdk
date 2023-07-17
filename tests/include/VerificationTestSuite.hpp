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

#ifndef ENJINPLATFORMSDK_VERIFICATIONTESTSUITE_HPP
#define ENJINPLATFORMSDK_VERIFICATIONTESTSUITE_HPP

#include <chrono>
#include <condition_variable>
#include <mutex>

/// \brief Test suite to assist in setting expectations and verifying asynchronous operations.
class VerificationTestSuite
{
    int _callCounter = 0;
    int _expectedCount = 0;

    // Mutexes
    mutable std::mutex _countMutex;

    // Condition variables
    std::condition_variable _cv;

public:
    /// \brief Class destructor.
    ~VerificationTestSuite();

    /// \brief Increments the call counter.
    [[maybe_unused]]
    void IncrementCallCount();

    /// \brief Sets the expected number of times an operation is expected to be called.
    /// \param count The expected call count.
    [[maybe_unused]]
    void SetExpectedCallCount(int count);

    /// \brief Verifies that the actual call count is equal to the expected call count.
    [[maybe_unused]]
    virtual void Verify();

    /// \brief Verifies that the actual call count is equal to the expected call count.
    /// \param timeout The timeout in milliseconds for this verification check.
    [[maybe_unused]]
    virtual void Verify(std::chrono::milliseconds timeout);

    /// \brief Verifies that the actual call count is equal to the expected call count.
    /// \param milliseconds The number of milliseconds before this verification check times out.
    [[maybe_unused]]
    void Verify(unsigned int milliseconds);

protected:
    /// \brief Constructs an instance of this class.
    VerificationTestSuite();

private:
    /// \brief Implementation for verifying that the actual call count is equal to the expected call count.
    /// \remarks Only call this when holding the lock for the count mutex.
    void VerifyImpl();
};

#endif //ENJINPLATFORMSDK_VERIFICATIONTESTSUITE_HPP
