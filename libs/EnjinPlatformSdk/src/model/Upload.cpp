#include "EnjinPlatformSdk/Upload.hpp"

#include <sstream>
#include <stdexcept>
#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
Upload::Upload() = default;

[[maybe_unused]]
Upload::Upload(std::ifstream file)
    : file(std::move(file))
{
}

[[maybe_unused]]
Upload::Upload(Upload&& other) noexcept = default;

Upload::~Upload()
{
    if (file.is_open())
    {
        file.close();
    }
}

Upload& Upload::operator=(Upload&& rhs) noexcept = default;

// region ISerializable

JsonValue Upload::ToJson() const
{
    return JsonValue::FromJson("null");
}

[[maybe_unused]]
std::string Upload::ToString() const
{
    return "null";
}

// endregion ISerializable
