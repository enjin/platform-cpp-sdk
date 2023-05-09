#include "RapidJsonUtil.hpp"

#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

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
