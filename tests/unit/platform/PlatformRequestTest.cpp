#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include "EnjinPlatformSdk/PlatformRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/Upload.hpp"
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

using namespace enjin::platform::sdk;
using namespace testing;
using RequestBuilder = PlatformRequest::PlatformRequestBuilder;
using UploadArray = std::shared_ptr<SerializableArray<Upload>>;
using UploadPtr = std::shared_ptr<Upload>;

class PlatformRequestTest : public Test
{
};

TEST_F(PlatformRequestTest, BuildRequestWithoutAddingOperationsThrowsError)
{
    // Arrange
    RequestBuilder builder = PlatformRequest::Builder();

    // Assert
    ASSERT_THROW(const PlatformRequest request = builder.Build(), std::logic_error);
}

TEST_F(PlatformRequestTest, BuildRequestWithNoVariablesReturnsRequestWithNoVariablesField)
{
    // Arrange
    const std::string expected(R"({"query":""})");
    const std::string query;
    const std::map<std::string, SerializablePtr> variables;
    RequestBuilder builder = PlatformRequest::Builder()
        .AddOperation(query, variables);

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    ASSERT_THAT(actual.GetBody().has_value(), IsTrue()) << "Assert request has content body";
    ASSERT_THAT(actual.GetBody().value(), Eq(expected)) << "Assert content body equals expected";
}

TEST_F(PlatformRequestTest, BuildBatchRequestWithNoVariablesReturnsRequestWithNoVariablesField)
{
    // Arrange
    const std::string expected(R"([{"query":""},{"query":""}])");
    const std::string query;
    const std::map<std::string, SerializablePtr> variables;
    RequestBuilder builder = PlatformRequest::Builder()
        .AddOperation(query, variables)
        .AddOperation(query, variables);

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    ASSERT_THAT(actual.GetBody().has_value(), IsTrue()) << "Assert request has content body";
    ASSERT_THAT(actual.GetBody().value(), Eq(expected)) << "Assert content body equals expected";
}

TEST_F(PlatformRequestTest, BuildBatchRequestWithVariablesReturnsRequestWithExpectedVariablesField)
{
    // Arrange
    const std::string expected(R"([{"query":"","variables":{"key1":1}},{"query":"","variables":{"key2":2}}])");
    const std::string query;
    const std::map<std::string, SerializablePtr> variables1({{"key1", std::make_shared<SerializableInt>(1)}});
    const std::map<std::string, SerializablePtr> variables2({{"key2", std::make_shared<SerializableInt>(2)}});
    RequestBuilder builder = PlatformRequest::Builder()
        .AddOperation(query, variables1)
        .AddOperation(query, variables2);

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    ASSERT_THAT(actual.GetBody().has_value(), IsTrue()) << "Assert request has content body";
    ASSERT_THAT(actual.GetBody().value(), Eq(expected)) << "Assert content body equals expected";
}

TEST_F(PlatformRequestTest, BuildRequestWithSingleFileVariableReturnsRequestWithExpectedForms)
{
    // Arrange
    const int expectedFormsCount = 3;
    const std::string expectedOpsFormName(R"("operations")");
    const std::string expectedOpsFormContent(R"({"query":"","variables":{"file":null}})");
    const std::string expectedMapFormName(R"("map")");
    const std::string expectedMapVariables(R"({"0":["variables.file"]})");
    const std::string expectedFileFormName(R"("0")");
    const std::string expectedFileContent(R"(Alpha file content.)");
    const std::string expectedFileName("Test Data/a.txt");
    std::map<std::string, SerializablePtr> variables;
    std::map<std::string, Upload&> uploads;
    UploadPtr upload = std::make_shared<Upload>(expectedFileName);
    RequestBuilder builder = PlatformRequest::Builder();
    variables.emplace("file", upload);
    uploads.emplace("file", *upload);
    builder.AddOperation("", variables, uploads);

    // Assumptions
    ASSERT_THAT(upload->file.is_open(), IsTrue()) << "Assume upload file is open";

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    const std::optional<std::vector<MultipartFormData>>& formsOptional = actual.GetMultipartFormData();
    ASSERT_THAT(formsOptional.has_value(), IsTrue()) << "Assert request has multipart forms";

    const std::vector<MultipartFormData>& forms = formsOptional.value();
    ASSERT_THAT(forms.size(), Eq(expectedFormsCount)) << "Assert forms count equals expected";
    EXPECT_THAT(forms[0].contentName, HasSubstr(expectedOpsFormName)) << "Expect ops form contains ops name";
    EXPECT_THAT(forms[0].content, HasSubstr(expectedOpsFormContent)) << "Expect ops form contains ops content";
    EXPECT_THAT(forms[1].contentName, HasSubstr(expectedMapFormName)) << "Expect map form contains map name";
    EXPECT_THAT(forms[1].content, HasSubstr(expectedMapVariables)) << "Expect map form contains map variables";
    EXPECT_THAT(forms[2].contentName, HasSubstr(expectedFileFormName)) << "Expect file form contains file name";
    EXPECT_THAT(forms[2].content, HasSubstr(expectedFileContent)) << "Expect file form contains file content";
    EXPECT_THAT(forms[2].fileName, HasSubstr(expectedFileName)) << "Expect file form contains file name";
}

TEST_F(PlatformRequestTest, BuildRequestWithFileListVariableReturnsRequestWithExpectedForms)
{
    // Arrange
    const int expectedFormsCount = 4;
    const std::string expectedOpsFormName(R"("operations")");
    const std::string expectedOpsFormContent(R"({"query":"","variables":{"files":[null,null]}})");
    const std::string expectedMapFormName(R"("map")");
    const std::string expectedMapVariables(R"({"0":["variables.files.0"],"1":["variables.files.1"]})");
    const std::string expectedFile0FormName(R"("0")");
    const std::string expectedFile0Content(R"(Alpha file content.)");
    const std::string expectedFile0Name("Test Data/a.txt");
    const std::string expectedFile1FormName(R"("1")");
    const std::string expectedFile1Content(R"(Bravo file content.)");
    const std::string expectedFile1Name("Test Data/b.txt");
    std::map<std::string, SerializablePtr> variables;
    std::map<std::string, Upload&> uploads;
    UploadArray files = std::make_shared<SerializableArray<Upload>>();
    RequestBuilder builder = PlatformRequest::Builder();
    files->PushBack(Upload(expectedFile0Name));
    files->PushBack(Upload(expectedFile1Name));
    variables.emplace("files", files);
    uploads.emplace("files.0", files->operator[](0));
    uploads.emplace("files.1", files->operator[](1));
    builder.AddOperation("", variables, uploads);

    // Assumptions
    ASSERT_THAT(files->operator[](0).file.is_open(), IsTrue()) << "Assume upload file '0' is open";
    ASSERT_THAT(files->operator[](1).file.is_open(), IsTrue()) << "Assume upload file '1' is open";

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    const std::optional<std::vector<MultipartFormData>>& formsOptional = actual.GetMultipartFormData();
    ASSERT_THAT(formsOptional.has_value(), IsTrue()) << "Assert request has multipart forms";

    const std::vector<MultipartFormData>& forms = formsOptional.value();
    ASSERT_THAT(forms.size(), Eq(expectedFormsCount)) << "Assert forms count equals expected";
    EXPECT_THAT(forms[0].contentName, HasSubstr(expectedOpsFormName)) << "Expect ops form contains ops name";
    EXPECT_THAT(forms[0].content, HasSubstr(expectedOpsFormContent)) << "Expect ops form contains ops content";
    EXPECT_THAT(forms[1].contentName, HasSubstr(expectedMapFormName)) << "Expect map form contains map name";
    EXPECT_THAT(forms[1].content, HasSubstr(expectedMapVariables)) << "Expect map form contains map variables";
    EXPECT_THAT(forms[2].contentName, HasSubstr(expectedFile0FormName)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[2].content, HasSubstr(expectedFile0Content)) << "Expect file form contains file '0' content";
    EXPECT_THAT(forms[2].fileName, HasSubstr(expectedFile0Name)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[3].contentName, HasSubstr(expectedFile1FormName)) << "Expect file form contains file '1' name";
    EXPECT_THAT(forms[3].content, HasSubstr(expectedFile1Content)) << "Expect file form contains file '1' content";
    EXPECT_THAT(forms[3].fileName, HasSubstr(expectedFile1Name)) << "Expect file form contains file '1' name";
}

TEST_F(PlatformRequestTest, BuildBatchRequestWithFileVariablesReturnsRequestWithExpectedForms)
{
    // Arrange
    const int expectedFormsCount = 4;
    const std::string expectedOpsFormName(R"("operations")");
    const std::string expectedOpsFormContent(
        R"([{"query":"","variables":{"file":null}},{"query":"","variables":{"file":null}}])");
    const std::string expectedMapFormName(R"("map")");
    const std::string expectedMapVariables(R"({"0":["0.variables.file"],"1":["1.variables.file"]})");
    const std::string expectedFile0FormName(R"("0")");
    const std::string expectedFile0Content(R"(Alpha file content.)");
    const std::string expectedFile0Name("Test Data/a.txt");
    const std::string expectedFile1FormName(R"("1")");
    const std::string expectedFile1Content(R"(Bravo file content.)");
    const std::string expectedFile1Name("Test Data/b.txt");
    std::map<std::string, SerializablePtr> variables0;
    std::map<std::string, SerializablePtr> variables1;
    std::map<std::string, Upload&> uploads0;
    std::map<std::string, Upload&> uploads1;
    UploadPtr upload0 = std::make_shared<Upload>(expectedFile0Name);
    UploadPtr upload1 = std::make_shared<Upload>(expectedFile1Name);
    RequestBuilder builder = PlatformRequest::Builder();
    variables0.emplace("file", upload0);
    variables1.emplace("file", upload1);
    uploads0.emplace("file", *upload0);
    uploads1.emplace("file", *upload1);
    builder.AddOperation("", variables0, uploads0);
    builder.AddOperation("", variables1, uploads1);

    // Assumptions
    ASSERT_THAT(upload0->file.is_open(), IsTrue()) << "Assume upload file '0' is open";
    ASSERT_THAT(upload1->file.is_open(), IsTrue()) << "Assume upload file '1' is open";

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    const std::optional<std::vector<MultipartFormData>>& formsOptional = actual.GetMultipartFormData();
    ASSERT_THAT(formsOptional.has_value(), IsTrue()) << "Assert request has multipart forms";

    const std::vector<MultipartFormData>& forms = formsOptional.value();
    ASSERT_THAT(forms.size(), Eq(expectedFormsCount)) << "Assert forms count equals expected";
    EXPECT_THAT(forms[0].contentName, HasSubstr(expectedOpsFormName)) << "Expect ops form contains ops name";
    EXPECT_THAT(forms[0].content, HasSubstr(expectedOpsFormContent)) << "Expect ops form contains ops content";
    EXPECT_THAT(forms[1].contentName, HasSubstr(expectedMapFormName)) << "Expect map form contains map name";
    EXPECT_THAT(forms[1].content, HasSubstr(expectedMapVariables)) << "Expect map form contains map variables";
    EXPECT_THAT(forms[2].contentName, HasSubstr(expectedFile0FormName)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[2].content, HasSubstr(expectedFile0Content)) << "Expect file form contains file '0' content";
    EXPECT_THAT(forms[2].fileName, HasSubstr(expectedFile0Name)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[3].contentName, HasSubstr(expectedFile1FormName)) << "Expect file form contains file '1' name";
    EXPECT_THAT(forms[3].content, HasSubstr(expectedFile1Content)) << "Expect file form contains file '1' content";
    EXPECT_THAT(forms[3].fileName, HasSubstr(expectedFile1Name)) << "Expect file form contains file '1' name";
}

TEST_F(PlatformRequestTest, BuildBatchRequestWithFileListVariablesReturnsRequestWithExpectedForms)
{
    // Arrange
    const int expectedFormsCount = 6;
    const std::string expectedOpsFormName(R"("operations")");
    const std::string expectedOpsFormContent(
        R"([{"query":"","variables":{"files":[null,null]}},{"query":"","variables":{"files":[null,null]}}])");
    const std::string expectedMapFormName(R"("map")");
    const std::string expectedMapVariables(
        R"({"0":["0.variables.files.0"],"1":["0.variables.files.1"],"2":["1.variables.files.0"],"3":["1.variables.files.1"]})");
    const std::string expectedFile0FormName(R"("0")");
    const std::string expectedFile0Content(R"(Alpha file content.)");
    const std::string expectedFile0Name("Test Data/a.txt");
    const std::string expectedFile1FormName(R"("1")");
    const std::string expectedFile1Content(R"(Bravo file content.)");
    const std::string expectedFile1Name("Test Data/b.txt");
    const std::string expectedFile2FormName(R"("2")");
    const std::string expectedFile2Content(R"(Charlie file content.)");
    const std::string expectedFile2Name("Test Data/c.txt");
    const std::string expectedFile3FormName(R"("3")");
    const std::string expectedFile3Content(R"(Delta file content.)");
    const std::string expectedFile3Name("Test Data/d.txt");
    std::map<std::string, SerializablePtr> variables0;
    std::map<std::string, SerializablePtr> variables1;
    std::map<std::string, Upload&> uploads0;
    std::map<std::string, Upload&> uploads1;
    UploadArray files0 = std::make_shared<SerializableArray<Upload>>();
    UploadArray files1 = std::make_shared<SerializableArray<Upload>>();
    RequestBuilder builder = PlatformRequest::Builder();
    files0->PushBack(Upload(expectedFile0Name));
    files0->PushBack(Upload(expectedFile1Name));
    files1->PushBack(Upload(expectedFile2Name));
    files1->PushBack(Upload(expectedFile3Name));
    variables0.emplace("files", files0);
    variables1.emplace("files", files1);
    uploads0.emplace("files.0", files0->operator[](0));
    uploads0.emplace("files.1", files0->operator[](1));
    uploads1.emplace("files.0", files1->operator[](0));
    uploads1.emplace("files.1", files1->operator[](1));
    builder.AddOperation("", variables0, uploads0);
    builder.AddOperation("", variables1, uploads1);

    // Assumptions
    ASSERT_THAT(files0->operator[](0).file.is_open(), IsTrue()) << "Assume upload file '0' is open";
    ASSERT_THAT(files0->operator[](1).file.is_open(), IsTrue()) << "Assume upload file '1' is open";
    ASSERT_THAT(files1->operator[](0).file.is_open(), IsTrue()) << "Assume upload file '2' is open";
    ASSERT_THAT(files1->operator[](1).file.is_open(), IsTrue()) << "Assume upload file '3' is open";

    // Act
    const PlatformRequest actual = builder.Build();

    // Assert
    const std::optional<std::vector<MultipartFormData>>& formsOptional = actual.GetMultipartFormData();
    ASSERT_THAT(formsOptional.has_value(), IsTrue()) << "Assert request has multipart forms";

    const std::vector<MultipartFormData>& forms = formsOptional.value();
    ASSERT_THAT(forms.size(), Eq(expectedFormsCount)) << "Assert forms count equals expected";
    EXPECT_THAT(forms[0].contentName, HasSubstr(expectedOpsFormName)) << "Expect ops form contains ops name";
    EXPECT_THAT(forms[0].content, HasSubstr(expectedOpsFormContent)) << "Expect ops form contains ops content";
    EXPECT_THAT(forms[1].contentName, HasSubstr(expectedMapFormName)) << "Expect map form contains map name";
    EXPECT_THAT(forms[1].content, HasSubstr(expectedMapVariables)) << "Expect map form contains map variables";
    EXPECT_THAT(forms[2].contentName, HasSubstr(expectedFile0FormName)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[2].content, HasSubstr(expectedFile0Content)) << "Expect file form contains file '0' content";
    EXPECT_THAT(forms[2].fileName, HasSubstr(expectedFile0Name)) << "Expect file form contains file '0' name";
    EXPECT_THAT(forms[3].contentName, HasSubstr(expectedFile1FormName)) << "Expect file form contains file '1' name";
    EXPECT_THAT(forms[3].content, HasSubstr(expectedFile1Content)) << "Expect file form contains file '1' content";
    EXPECT_THAT(forms[3].fileName, HasSubstr(expectedFile1Name)) << "Expect file form contains file '1' name";
    EXPECT_THAT(forms[4].contentName, HasSubstr(expectedFile2FormName)) << "Expect file form contains file '2' name";
    EXPECT_THAT(forms[4].content, HasSubstr(expectedFile2Content)) << "Expect file form contains file '2' content";
    EXPECT_THAT(forms[4].fileName, HasSubstr(expectedFile2Name)) << "Expect file form contains file '2' name";
    EXPECT_THAT(forms[5].contentName, HasSubstr(expectedFile3FormName)) << "Expect file form contains file '3' name";
    EXPECT_THAT(forms[5].content, HasSubstr(expectedFile3Content)) << "Expect file form contains file '3' content";
    EXPECT_THAT(forms[5].fileName, HasSubstr(expectedFile3Name)) << "Expect file form contains file '3' name";
}
