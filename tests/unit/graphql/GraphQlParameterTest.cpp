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
