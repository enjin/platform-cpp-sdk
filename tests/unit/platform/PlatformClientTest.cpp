#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MockHttpServer.hpp"
#include "MockPlatformRequest.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "VerificationTestSuite.hpp"
#include "EnjinPlatformSdk/GraphQlBatchResponse.hpp"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"
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

class PlatformClientTest : public Test,
                           public VerificationTestSuite
{
public:
    PlatformClientPtr classUnderTest;

    // Mocks
    MockPlatformRequestPtr mockRequest;
    MockHttpServer mockServer;

    inline static const std::string ContentType = std::string("Content-Type");
    inline static const std::string MediaType = std::string("application/json");
    inline static const std::string Path = std::string("/graphql");
    inline static const std::chrono::seconds Timeout = std::chrono::seconds(5);

protected:
    void SetUp() override
    {
        Test::SetUp();

        mockRequest = std::make_shared<NiceMockPlatformRequest>();
        mockServer.Start();

        // Default stubs for mock request
        ON_CALL(*mockRequest, GetContentType())
            .WillByDefault(Const(ReturnRef(MediaType)));
        ON_CALL(*mockRequest, GetPath())
            .WillByDefault(Const(ReturnRef(Path)));

        classUnderTest = PlatformClient::Builder()
            .SetBaseAddress(mockServer.GetUri().value())
            .Build();
    }

    void TearDown() override
    {
        Test::TearDown();

        mockServer.Stop();
    }
};

TEST_F(PlatformClientTest, SendRequestClientSetsExpectedUserAgentHeader)
{
    // Arrange - Data
    const std::future_status expectedStatus = std::future_status::ready;
    const std::string expectedKey("User-Agent");
    const std::string expectedValue = classUnderTest->GetUserAgent();
    const std::string responseBody(R"({"data": {"result": true}})");
    const std::optional<std::string> body("");
    const std::optional<std::vector<MultipartFormData>> forms;
    const std::map<std::string, std::string> headers;

    // Arrange - Stubbing
    EXPECT_CALL(*mockRequest, GetBody())
        .WillRepeatedly(ReturnRef(body));
    EXPECT_CALL(*mockRequest, GetMultipartFormData())
        .WillRepeatedly(ReturnRef(forms));
    EXPECT_CALL(*mockRequest, GetHeaders())
        .WillRepeatedly(ReturnRef(headers));
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithHeader(ContentType, MediaType)
                               .WithBody(responseBody));

    // Arrange - Expectations
    mockServer.NextMessage([this, expectedKey, expectedValue](const IPlatformRequest& request) {
        IncrementCallCount();

        const std::map<std::string, std::string>& headers = request.GetHeaders();
        ASSERT_THAT(headers.find(expectedKey), Not(Eq(headers.end()))) << "Assert request contains expected header key";
        ASSERT_THAT(headers.at(expectedKey), Eq(expectedValue)) << "Assert request contains expected header value";
    });
    SetExpectedCallCount(1);

    // Act
    auto future = classUnderTest->SendRequest<GraphQlResponse<bool>>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), Eq(expectedStatus)) << "Assert future is ready";

    // Verify
    Verify();
}

TEST_F(PlatformClientTest, SendRequestWhenClientIsAuthenticatedSendsRequestWithAuthorizationHeader)
{
    // Arrange - Data
    const std::string expectedKey("Authorization");
    const std::string expectedValue("xyz");
    const std::string responseBody(R"({"data": {"result": true}})");
    const std::optional<std::string> body("");
    const std::optional<std::vector<MultipartFormData>> forms;
    const std::map<std::string, std::string> headers;
    classUnderTest->Auth(expectedValue);

    // Arrange - Stubbing
    EXPECT_CALL(*mockRequest, GetBody())
        .WillRepeatedly(ReturnRef(body));
    EXPECT_CALL(*mockRequest, GetMultipartFormData())
        .WillRepeatedly(ReturnRef(forms));
    EXPECT_CALL(*mockRequest, GetHeaders())
        .WillRepeatedly(ReturnRef(headers));
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithHeader(ContentType, MediaType)
                               .WithBody(responseBody));

    // Arrange - Expectations
    mockServer.NextMessage([this, expectedKey, expectedValue](const IPlatformRequest& request) {
        IncrementCallCount();

        const std::map<std::string, std::string>& headers = request.GetHeaders();
        ASSERT_THAT(headers.find(expectedKey), Not(Eq(headers.end()))) << "Assert request contains expected header key";
        ASSERT_THAT(headers.at(expectedKey), Eq(expectedValue)) << "Assert request contains expected header value";
    });
    SetExpectedCallCount(1);

    // Act
    auto future = classUnderTest->SendRequest<GraphQlResponse<bool>>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), Eq(std::future_status::ready)) << "Assert future is ready";

    // Verify
    Verify();
}

TEST_F(PlatformClientTest, SendRequestWhenProcessingValidResponseReturnsExpectedResult)
{
    // Arrange - Data
    const bool expectedResult = true;
    const std::string responseBody(R"({"data": {"result": true}})");
    const std::optional<std::string> body("");
    const std::optional<std::vector<MultipartFormData>> forms;
    const std::map<std::string, std::string> headers;

    // Arrange - Stubbing
    EXPECT_CALL(*mockRequest, GetBody())
        .WillRepeatedly(ReturnRef(body));
    EXPECT_CALL(*mockRequest, GetMultipartFormData())
        .WillRepeatedly(ReturnRef(forms));
    EXPECT_CALL(*mockRequest, GetHeaders())
        .WillRepeatedly(ReturnRef(headers));
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithHeader(ContentType, MediaType)
                               .WithBody(responseBody));

    // Act
    auto future = classUnderTest->SendRequest<GraphQlResponse<bool>>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), Eq(std::future_status::ready)) << "Assert future is ready";

    const PlatformResponsePtr<GraphQlResponse<bool>>& platformRes = future.get();
    ASSERT_THAT(platformRes, NotNull()) << "Assert platform response is not null";
    ASSERT_THAT(platformRes->GetResult().has_value(), IsTrue()) << "Assert platform response has GraphQL response";

    const GraphQlResponse<bool>& gqlRes = platformRes->GetResult().value();
    ASSERT_THAT(gqlRes.GetData().has_value(), IsTrue()) << "Assert GraphQL response has data";

    const GraphQlData<bool>& data = gqlRes.GetData().value();
    ASSERT_THAT(data.GetResult().has_value(), IsTrue()) << "Assert data has result";
    ASSERT_THAT(data.GetResult().value(), Eq(expectedResult)) << "Assert data equals expected";
}

TEST_F(PlatformClientTest, SendRequestWhenProcessingValidBatchResponseReturnsExpectedResult)
{
    // Arrange - Data
    const int expectedCount = 2;
    const JsonValue expectedResult = JsonValue::FromJson("true");
    const std::string responseBody(R"([{"data": {"result": true}}, {"data": {"result": true}}])");
    const std::optional<std::string> body("");
    const std::optional<std::vector<MultipartFormData>> forms;
    const std::map<std::string, std::string> headers;

    // Arrange - Stubbing
    EXPECT_CALL(*mockRequest, GetBody())
        .WillRepeatedly(ReturnRef(body));
    EXPECT_CALL(*mockRequest, GetMultipartFormData())
        .WillRepeatedly(ReturnRef(forms));
    EXPECT_CALL(*mockRequest, GetHeaders())
        .WillRepeatedly(ReturnRef(headers));
    mockServer.Given(Request::Create()
                         .WithPath(Path)
                         .UsingPost())
              .RespondWith(Response::Create()
                               .WithSuccess()
                               .WithHeader(ContentType, MediaType)
                               .WithBody(responseBody));

    // Act
    auto future = classUnderTest->SendRequest<GraphQlBatchResponse>(mockRequest);

    // Assert
    ASSERT_THAT(future.wait_for(Timeout), Eq(std::future_status::ready)) << "Assert future is ready";

    const PlatformResponsePtr<GraphQlBatchResponse>& platformRes = future.get();
    ASSERT_THAT(platformRes, NotNull()) << "Assert platform response is not null";
    ASSERT_THAT(platformRes->GetResult().has_value(), IsTrue()) << "Assert platform response has batch";

    const GraphQlBatchResponse& gqlBatch = platformRes->GetResult().value();
    ASSERT_THAT(gqlBatch.Size(), Eq(expectedCount)) << "Assert batch has expected count";

    ASSERT_THAT(gqlBatch[0].GetData().has_value(), IsTrue()) << "Assert first GraphQL response has data";
    ASSERT_THAT(gqlBatch[1].GetData().has_value(), IsTrue()) << "Assert second GraphQL response has data";

    const GraphQlData<JsonValue>& first = gqlBatch[0].GetData().value();
    ASSERT_THAT(first.GetResult().has_value(), IsTrue()) << "Assert first data has result";
    ASSERT_THAT(first.GetResult().value(), Eq(expectedResult)) << "Assert first data equals expected";

    const GraphQlData<JsonValue>& second = gqlBatch[1].GetData().value();
    ASSERT_THAT(second.GetResult().has_value(), IsTrue()) << "Assert second data has result";
    ASSERT_THAT(second.GetResult().value(), Eq(expectedResult)) << "Assert second data equals expected";
}
