#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockHttpServer.hpp"
#include "MockLogger.hpp"
#include "MockPlatformRequest.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/HttpLogLevel.hpp"
#include "EnjinPlatformSdk/LogLevel.hpp"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include "EnjinPlatformSdk/PlatformClient.hpp"
#include <chrono>
#include <future>
#include <map>
#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace enjin::platform::sdk;
using namespace testing;
using Seconds = std::chrono::seconds;

class HttpLoggingHandlerTestSuite
{
public:
    // Mocks
    std::shared_ptr<StrictMock<MockLogger>> mockLogger;
    MockPlatformRequestPtr mockRequest;
    MockHttpServer mockServer;

    inline static const std::optional<std::string> Body = std::string("");
    inline static const std::map<std::string, std::string> Headers = {};
    inline static const std::string MediaType = std::string("application/json");
    inline static const std::optional<std::vector<MultipartFormData>> Forms;
    inline static const std::string Path = std::string("/graphql");
    inline static const Seconds Timeout = Seconds(5);

    [[nodiscard]]
    std::unique_ptr<PlatformClient> CreateClient(const HttpLogLevel httpLogLevel) const
    {
        return PlatformClient::Builder()
            .SetBaseAddress(mockServer.GetUri().value())
            .SetLogger(mockLogger)
            .SetHttpLogLevel(httpLogLevel)
            .Build();
    }
};

class HttpLoggingHandlerTest : public Test,
                               public HttpLoggingHandlerTestSuite
{
protected:
    void SetUp() override
    {
        Test::SetUp();

        mockLogger = std::make_shared<StrictMock<MockLogger>>();
        mockRequest = std::make_shared<NiceMockPlatformRequest>();
        mockServer.Start();

        // Default stubs for mock request
        ON_CALL(*mockRequest, GetBody())
            .WillByDefault(Const(ReturnRef(Body)));
        ON_CALL(*mockRequest, GetContentType())
            .WillByDefault(Const(ReturnRef(MediaType)));
        ON_CALL(*mockRequest, GetMultipartFormData())
            .WillByDefault(Const(ReturnRef(Forms)));
        ON_CALL(*mockRequest, GetPath())
            .WillByDefault(Const(ReturnRef(Path)));
        ON_CALL(*mockRequest, GetHeaders())
            .WillByDefault(Const(ReturnRef(Headers)));
    }

    void TearDown() override
    {
        Test::TearDown();

        mockServer.Stop();
    }
};

class HttpLoggingHandlerHttpLogLevelsTest : public TestWithParam<HttpLogLevel>,
                                            public HttpLoggingHandlerTestSuite
{
protected:
    void SetUp() override
    {
        TestWithParam<HttpLogLevel>::SetUp();

        mockLogger = std::make_shared<StrictMock<MockLogger>>();
        mockRequest = std::make_shared<NiceMockPlatformRequest>();
        mockServer.Start();

        // Default stubs for mock request
        ON_CALL(*mockRequest, GetBody())
            .WillByDefault(Const(ReturnRef(Body)));
        ON_CALL(*mockRequest, GetContentType())
            .WillByDefault(Const(ReturnRef(MediaType)));
        ON_CALL(*mockRequest, GetMultipartFormData())
            .WillByDefault(Const(ReturnRef(Forms)));
        ON_CALL(*mockRequest, GetPath())
            .WillByDefault(Const(ReturnRef(Path)));
        ON_CALL(*mockRequest, GetHeaders())
            .WillByDefault(Const(ReturnRef(Headers)));
    }

    void TearDown() override
    {
        TestWithParam<HttpLogLevel>::TearDown();

        mockServer.Stop();
    }
};

TEST_F(HttpLoggingHandlerTest, WhenClientHasHttpLogLevelOfNonePerformsNoLogging)
{
    // Arrange - Data
    const std::future_status expectedStatus = std::future_status::ready;
    const std::string responseBody(R"({"data": {"result": true}})");
    std::unique_ptr<PlatformClient> client = CreateClient(HttpLogLevel::None);

    // Arrange - Stubbing
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithBody(responseBody));

    // Arrange - Expectations
    EXPECT_CALL(*mockLogger, Log(An<LogLevel>(), An<const std::string&>()))
        .Times(0);

    // Act
    auto future = client->SendRequest<GraphQlResponse<bool>>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), expectedStatus) << "Assert future is ready";

    // Verify (Done by GTest)
}

TEST_P(HttpLoggingHandlerHttpLogLevelsTest, WhenClientHasHttpLogLevelNotOfNonePerformsLogging)
{
    // Arrange - Data
    const std::future_status expectedStatus = std::future_status::ready;
    const std::string responseBody(R"({"data": {"result": true}})");
    std::unique_ptr<PlatformClient> client = CreateClient(GetParam());

    // Arrange - Stubbing
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithBody(responseBody));

    // Arrange - Expectations
    EXPECT_CALL(*mockLogger, Log(LogLevel::Trace, An<const std::string&>()))
        .Times(2);

    // Act
    auto future = client->SendRequest<GraphQlResponse<bool>>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), expectedStatus) << "Assert future is ready";

    // Verify (Done by GTest)
}

INSTANTIATE_TEST_SUITE_P(NotNoneLogLevels,
                         HttpLoggingHandlerHttpLogLevelsTest,
                         Values(HttpLogLevel::Basic,
                                HttpLogLevel::Headers,
                                HttpLogLevel::Body));
