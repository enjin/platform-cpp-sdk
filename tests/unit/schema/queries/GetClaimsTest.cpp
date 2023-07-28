#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdkBeam/ClaimStatus.hpp"
#include "EnjinPlatformSdkBeam/GetClaims.hpp"
#include <map>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;
using namespace testing;

class GetClaimsTest : public Test
{
};

TEST_F(GetClaimsTest, SomeTest)
{
    // Arrange
    const std::string expectedKey("states");
    const std::string expectedString(R"(["COMPLETED","IN_PROGRESS"])");
    const std::vector<ClaimStatus> states({ClaimStatus::Completed, ClaimStatus::InProgress});
    GetClaims request;

    // Act
    request.SetStates(states);

    // Assert
    std::map<std::string, SerializablePtr> variables = request.GetVariablesWithoutTypes();
    ASSERT_THAT(variables, Contains(Key(expectedKey)))
                        << "Assert that variables contains expected key";
    ASSERT_THAT(variables[expectedKey], NotNull())
                        << "Assert that the serializable value is not null";
    ASSERT_THAT(variables[expectedKey]->ToString(), Eq(expectedString))
                        << "Assert that the serializable value outputs the expected string";
}
