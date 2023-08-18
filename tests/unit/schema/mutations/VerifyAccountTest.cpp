#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/CryptoSignatureType.hpp"
#include "EnjinPlatformSdk/VerifyAccount.hpp"
#include <memory>

using namespace enjin::platform::sdk;
using namespace testing;

class VerifyAccountTestSuite
{
public:
    static inline const std::string CryptoSignatureTypeName = "cryptoSignatureType";
};

class VerifyAccountTest : public Test,
                          public VerifyAccountTestSuite
{
public:
    std::unique_ptr<VerifyAccount> classUnderTest;

protected:
    void SetUp() override
    {
        Test::SetUp();

        classUnderTest = std::make_unique<VerifyAccount>();
    }
};

class VerifyAccountCryptoSignatureTypeTest : public TestWithParam<CryptoSignatureType>,
                                             public VerifyAccountTestSuite
{
public:
    std::unique_ptr<VerifyAccount> classUnderTest;

protected:
    void SetUp() override
    {
        TestWithParam<CryptoSignatureType>::SetUp();

        classUnderTest = std::make_unique<VerifyAccount>();
    }
};

TEST_F(VerifyAccountTest, SetCryptoSignatureTypeWhenVariableIsNotSetAndGivenNoneDoesNotSetTheVariable)
{
    // Arrange
    const CryptoSignatureType cryptoSignatureType = CryptoSignatureType::None;

    // Assumptions
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsFalse())
                        << "Assume that the '" << CryptoSignatureTypeName << "' variable is not set";

    // Act
    classUnderTest->SetCryptoSignatureType(cryptoSignatureType);

    // Assert
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsFalse())
                        << "Assert that the '" << CryptoSignatureTypeName << "' variable was not set";
}

TEST_F(VerifyAccountTest, SetCryptoSignatureTypeWhenVariableIsSetAndGivenNoneRemovesTheVariable)
{
    // Arrange
    const CryptoSignatureType cryptoSignatureType = CryptoSignatureType::None;
    classUnderTest->SetCryptoSignatureType(CryptoSignatureType::Ed25519);

    // Assumptions
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsTrue())
                        << "Assume that the '" << CryptoSignatureTypeName << "' variable is set";

    // Act
    classUnderTest->SetCryptoSignatureType(cryptoSignatureType);

    // Assert
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsFalse())
                        << "Assert that the '" << CryptoSignatureTypeName << "' variable was removed";
}

TEST_P(VerifyAccountCryptoSignatureTypeTest, SetCryptoSignatureTypeWhenGivenNonNoneTypeVariableIsSet)
{
    // Arrange
    const CryptoSignatureType cryptoSignatureType = GetParam();

    // Assumptions
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsFalse())
                        << "Assume that the '" << CryptoSignatureTypeName << "' variable is not set";

    // Act
    classUnderTest->SetCryptoSignatureType(cryptoSignatureType);

    // Assert
    ASSERT_THAT(classUnderTest->HasVariable(CryptoSignatureTypeName), IsTrue())
                        << "Assert that the '" << CryptoSignatureTypeName << "' variable was set";
}

INSTANTIATE_TEST_SUITE_P(NonNoneCryptoSignatureType,
                         VerifyAccountCryptoSignatureTypeTest,
                         Values(CryptoSignatureType::Ed25519,
                                CryptoSignatureType::Sr25519));
