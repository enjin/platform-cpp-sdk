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
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;

class GraphQlParameterImpl : public GraphQlParameter<GraphQlParameterImpl>
{
public:
    GraphQlParameterImpl() = default;

    ~GraphQlParameterImpl() override = default;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override
    {
        return {};
    }

    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override
    {
        return {};
    }

    // endregion ISerializable
};

class GraphQlParameterTest : public Test
{
};

TEST_F(GraphQlParameterTest, SetParameterWhenValueIsThisThrowsError)
{
    // Arrange
    const std::string key("key");
    std::shared_ptr<GraphQlParameterImpl> parameter = std::make_shared<GraphQlParameterImpl>();

    // Assert
    ASSERT_THROW(parameter->SetParameter(key, parameter), std::invalid_argument);
}
