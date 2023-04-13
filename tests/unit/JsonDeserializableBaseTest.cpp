#include "gtest/gtest.h"
#include "EnjinPlatformSdk/JsonValue.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <memory>
#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace testing;

class JsonDeserializableBaseTest : public Test
{
public:
    std::unique_ptr<JsonDeserializableBase> classUnderTest;

protected:
    void SetUp() override
    {
        classUnderTest = std::make_unique<JsonDeserializableBase>();
    }
};

TEST_F(JsonDeserializableBaseTest, DeserializeWhenInstanceHasNotBeenDeserializedDoesNotThrowError)
{
    // Arrange
    const JsonValue json;

    // Assert
    ASSERT_NO_THROW(classUnderTest->Deserialize(json));
}

TEST_F(JsonDeserializableBaseTest, DeserializeWhenInstanceHasAlreadyBeenDeserializedThrowsError)
{
    // Arrange
    const JsonValue json;
    classUnderTest->Deserialize(json);

    // Assert
    ASSERT_THROW(classUnderTest->Deserialize(json), std::runtime_error);
}
