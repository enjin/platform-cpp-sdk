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

#include "EnjinPlatformSdk/PlatformRequest.hpp"

#include "FileUtil.hpp"
#include "RapidJsonUtil.hpp"
#include "rapidjson/document.h"
#include <stdexcept>
#include <utility>

using namespace enjin::platform::sdk;
using namespace rapidjson;

// region PlatformRequest

PlatformRequest::PlatformRequest(const std::vector<Operation>& operations)
{
    Init(operations);
}

[[maybe_unused]]
PlatformRequest::PlatformRequest(const PlatformRequest& other) = default;

[[maybe_unused]]
PlatformRequest::PlatformRequest(PlatformRequest&& other) noexcept = default;

PlatformRequest::~PlatformRequest() = default;

std::string PlatformRequest::CreateOperationContent(const std::vector<Operation>& operations)
{
    Document document;

    if (operations.size() > 1)
    {
        document = Document(kArrayType);
        Document::AllocatorType& allocator = document.GetAllocator();

        // Adds each operation to the operations array
        for (size_t i = 0; i < operations.size(); i++)
        {
            const Operation& operation = operations[i];

            Value opValue(kObjectType);
            Value queryValue(operation.query.c_str(), allocator);
            opValue.AddMember("query", queryValue.Move(), allocator);

            // Checks if the operation contains any variables and adds them to the operation element
            if (!operation.variables.empty())
            {
                Value variablesValue(kObjectType);

                for (const auto& [varKey, varVal] : operation.variables)
                {
                    if (varVal == nullptr)
                    {
                        continue;
                    }

                    Value k(varKey.c_str(), allocator);
                    Document valDoc(&allocator);
                    valDoc.Parse(varVal->ToJson().ToString().c_str());

                    variablesValue.AddMember(k.Move(), valDoc.Move(), allocator);
                }

                opValue.AddMember(VariablesKey, variablesValue.Move(), allocator);

                // Add uploads to map with position and 'variables' as the root
                for (const auto& [k, v] : operation.uploads)
                {
                    _uploadVariables.try_emplace(std::to_string(i) + "." + VariablesKey + "." + k, v);
                }
            }

            document.PushBack(opValue.Move(), allocator);
        }
    }
    else
    {
        document = Document(kObjectType);
        Document::AllocatorType& allocator = document.GetAllocator();

        const Operation& operation = operations[0];
        Value queryValue(operation.query.c_str(), allocator);
        document.AddMember("query", queryValue.Move(), allocator);

        // Checks if the operation contains any variables and adds them to the operation document
        if (!operation.variables.empty())
        {
            Value variablesValue(kObjectType);

            for (const auto& [varKey, varVal] : operation.variables)
            {
                if (varVal == nullptr)
                {
                    continue;
                }

                Value k(varKey.c_str(), allocator);
                Document valDoc(&allocator);
                valDoc.Parse(varVal->ToJson().ToString().c_str());

                variablesValue.AddMember(k.Move(), valDoc.Move(), allocator);
            }

            document.AddMember(VariablesKey, variablesValue.Move(), allocator);

            // Add uploads to map with 'variables' as the root
            for (const auto& [k, v] : operation.uploads)
            {
                _uploadVariables.try_emplace(std::string() + VariablesKey + "." + k, v);
            }
        }
    }

    return RapidJsonUtil::DocumentToString(document);
}

void PlatformRequest::Init(const std::vector<Operation>& operations)
{
    // Checks if this request needs to be created as a multipart due to having file uploads
    bool hasUploads = false;
    const size_t count = operations.size();
    size_t i = 0;

    while (!hasUploads && i < count)
    {
        if (!operations[i++].uploads.empty())
        {
            hasUploads = true;
        }
    }

    if (hasUploads)
    {
        InitForMultipartFormData(operations);
    }
    else
    {
        InitForSingleContent(operations);
    }
}

void PlatformRequest::InitForMultipartFormData(const std::vector<Operation>& operations)
{
    std::vector<MultipartFormData> forms;

    // Create and add operations form
    MultipartFormData operationsForm;
    operationsForm.content = CreateOperationContent(operations);
    operationsForm.contentName = R"("operations")";
    operationsForm.contentType = Json;
    forms.push_back(std::move(operationsForm));

    // Create initial map form
    MultipartFormData mapForm;
    mapForm.contentName = R"("map")";
    mapForm.contentType = Json;

    // Create file forms and compile content for map form
    Document mapDocument(kObjectType);
    Document::AllocatorType& mapAllocator = mapDocument.GetAllocator();
    std::vector<MultipartFormData> fileForms;
    int i = 0;

    for (const auto& [uploadPath, upload] : _uploadVariables)
    {
        const std::string iStr = std::to_string(i);

        Value k(iStr.c_str(), mapAllocator);
        Value v(kArrayType);
        Value vEl(uploadPath.c_str(), mapAllocator);
        v.PushBack(vEl.Move(), mapAllocator);
        mapDocument.AddMember(k.Move(), v.Move(), mapAllocator);
        mapForm.content = RapidJsonUtil::DocumentToString(mapDocument);

        // Create file form
        MultipartFormData fileForm;
        fileForm.content = FileUtil::GetFileContent(upload.file);
        fileForm.contentName = "\"" + iStr + "\"";
        fileForm.contentType = Text;
        fileForm.fileName = upload.filename;
        fileForms.push_back(std::move(fileForm));

        i++;
    }

    forms.push_back(std::move(mapForm));
    std::move(fileForms.begin(), fileForms.end(), std::back_inserter(forms));

    _forms = std::move(forms);
    _contentType = FormData;
}

void PlatformRequest::InitForSingleContent(const std::vector<Operation>& operations)
{
    _body = CreateOperationContent(operations);
    _contentType = Json;
}

PlatformRequest& PlatformRequest::operator=(const PlatformRequest& rhs) = default;

PlatformRequest& PlatformRequest::operator=(PlatformRequest&&) noexcept = default;

[[maybe_unused]]
PlatformRequest::PlatformRequestBuilder PlatformRequest::Builder()
{
    return {};
}

// region IPlatformRequest

[[maybe_unused]]
const std::optional<std::string>& PlatformRequest::GetBody() const
{
    return _body;
}

[[maybe_unused]]
const std::string& PlatformRequest::GetContentType() const
{
    return _contentType;
}

[[maybe_unused]]
const std::map<std::string, std::string>& PlatformRequest::GetHeaders() const
{
    return _headers;
}

[[maybe_unused]]
const std::optional<std::vector<MultipartFormData>>& PlatformRequest::GetMultipartFormData() const
{
    return _forms;
}

[[maybe_unused]]
const std::string& PlatformRequest::GetPath() const
{
    return _path;
}

// endregion IPlatformRequest

// endregion PlatformRequest

// region PlatformRequestBuilder

PlatformRequest::PlatformRequestBuilder::PlatformRequestBuilder() = default;

PlatformRequest::PlatformRequestBuilder::~PlatformRequestBuilder() = default;

[[maybe_unused]]
PlatformRequest::PlatformRequestBuilder& PlatformRequest::PlatformRequestBuilder::AddHeader(std::string key,
                                                                                            std::string value)
{
    _headers.emplace(std::move(key), std::move(value));
    return *this;
}

[[maybe_unused]]
PlatformRequest::PlatformRequestBuilder&
PlatformRequest::PlatformRequestBuilder::AddOperation(std::string query,
                                                      std::map<std::string, SerializablePtr> variables)
{
    Operation o;
    o.query = std::move(query);
    o.variables = std::move(variables);
    _operations.push_back(std::move(o));

    return *this;
}

[[maybe_unused]]
PlatformRequest::PlatformRequestBuilder&
PlatformRequest::PlatformRequestBuilder::AddOperation(std::string query,
                                                      std::map<std::string, SerializablePtr> variables,
                                                      std::map<std::string, Upload&> uploads)
{
    Operation op;
    op.query = std::move(query);
    op.variables = std::move(variables);
    op.uploads = std::move(uploads);
    _operations.push_back(std::move(op));

    return *this;
}

[[maybe_unused]]
PlatformRequestPtr PlatformRequest::PlatformRequestBuilder::Build() const
{
    if (_operations.empty())
    {
        throw std::logic_error("Cannot build request with no operations");
    }

    std::shared_ptr<PlatformRequest> request = std::shared_ptr<PlatformRequest>(new PlatformRequest(_operations));
    request->_path = _path.value_or("");
    request->_headers = _headers;

    return request;
}

[[maybe_unused]]
PlatformRequest::PlatformRequestBuilder& PlatformRequest::PlatformRequestBuilder::SetPath(std::string path)
{
    _path = std::move(path);
    return *this;
}

// endregion PlatformRequestBuilder
