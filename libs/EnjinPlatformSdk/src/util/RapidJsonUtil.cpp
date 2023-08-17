#include "RapidJsonUtil.hpp"

#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace rapidjson;

[[maybe_unused]]
std::string RapidJsonUtil::DocumentToString(const Document& document)
{
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);

    return {buffer.GetString()};
}

void RapidJsonUtil::RemoveMemberIfPresent(Document& document, const char* kStr)
{
    if (document.HasMember(kStr))
    {
        document.RemoveMember(kStr);
    }
}

[[maybe_unused]]
void RapidJsonUtil::SetDocumentMember(Document& document, const std::string& key, const Document& value)
{
    SetMemberAssert(document, key);

    const char* kStr = key.c_str();
    RemoveMemberIfPresent(document, kStr);

    Document::AllocatorType& allocator = document.GetAllocator();
    Value k(kStr, allocator);
    Value v(value, allocator);

    document.AddMember(k.Move(), v.Move(), allocator);
}

void RapidJsonUtil::SetMemberAssert(Document& document, const std::string& key)
{
    if (!document.IsObject())
    {
        throw std::invalid_argument("JSON document is not an object type");
    }

    if (key.empty())
    {
        throw std::invalid_argument("Member key cannot be empty");
    }
}

[[maybe_unused]]
void RapidJsonUtil::SetStringMember(Document& document, const std::string& key, const std::string& value)
{
    SetMemberAssert(document, key);

    const char* kStr = key.c_str();
    RemoveMemberIfPresent(document, kStr);

    Document::AllocatorType& allocator = document.GetAllocator();
    Value k(kStr, allocator);
    Value v(value.c_str(), allocator);

    document.AddMember(k.Move(), v.Move(), allocator);
}

[[maybe_unused]]
rapidjson::Document RapidJsonUtil::StringToDocument(const std::string& json)
{
    Document document;
    document.Parse(json.c_str());

    return document;
}
