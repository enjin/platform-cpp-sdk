#include "EnjinPlatformSdk/GraphQlUploadHolder.hpp"

using namespace enjin::platform::sdk;

[[maybe_unused]]
GraphQlUploadHolder::GraphQlUploadHolder() = default;

[[maybe_unused]]
GraphQlUploadHolder::GraphQlUploadHolder(const GraphQlUploadHolder& other) = default;

[[maybe_unused]]
GraphQlUploadHolder::GraphQlUploadHolder(GraphQlUploadHolder&& other) noexcept = default;

GraphQlUploadHolder::~GraphQlUploadHolder() = default;

[[maybe_unused]]
void GraphQlUploadHolder::UploadAdded(const std::string& key)
{
    _uploadPaths.emplace(key);
}

[[maybe_unused]]
void GraphQlUploadHolder::UploadAdded(const std::string& key, const int count)
{
    for (int i = 0; i < count; i++)
    {
        UploadAdded(key + "." + std::to_string(i));
    }
}

[[maybe_unused]]
void GraphQlUploadHolder::UploadRemoved(const std::string& key)
{
    _uploadPaths.erase(key);
}

GraphQlUploadHolder& GraphQlUploadHolder::operator=(const GraphQlUploadHolder& rhs) = default;

GraphQlUploadHolder& GraphQlUploadHolder::operator=(GraphQlUploadHolder&& rhs) noexcept = default;

// region IGraphQlUploadHolder

[[maybe_unused]]
const std::set<std::string>& GraphQlUploadHolder::GetUploadParameterPaths() const
{
    return _uploadPaths;
}

// endregion IGraphQlUploadHolder
