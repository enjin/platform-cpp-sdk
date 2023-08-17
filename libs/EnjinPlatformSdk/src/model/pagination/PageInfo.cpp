#include "EnjinPlatformSdk/PageInfo.hpp"

#include "EnjinPlatformSdk/JsonUtil.hpp"

using namespace enjin::platform::sdk;

// region Impl

class PageInfo::Impl : public JsonDeserializableBase
{
public:
    std::optional<bool> hasNextPage;
    std::optional<bool> hasPreviousPage;
    std::optional<std::string> startCursor;
    std::optional<std::string> endCursor;

    Impl() = default;

    Impl(const Impl& other) = default;

    Impl(Impl&& other) noexcept = default;

    ~Impl() override = default;

    [[nodiscard]]
    const std::optional<bool>& GetHasNextPage() const
    {
        return hasNextPage;
    }

    [[nodiscard]]
    const std::optional<bool>& GetHasPreviousPage() const
    {
        return hasPreviousPage;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetStartCursor() const
    {
        return startCursor;
    }

    [[nodiscard]]
    const std::optional<std::string>& GetEndCursor() const
    {
        return endCursor;
    }

    Impl& operator=(const Impl& rhs) = default;

    Impl& operator=(Impl&& rhs) noexcept = default;

    // region IJsonDeserializable

    void Deserialize(const JsonValue& json) override
    {
        JsonDeserializableBase::Deserialize(json);
        JsonUtil::TryGetField(json, "hasNextPage", hasNextPage);
        JsonUtil::TryGetField(json, "hasPreviousPage", hasPreviousPage);
        JsonUtil::TryGetField(json, "startCursor", startCursor);
        JsonUtil::TryGetField(json, "endCursor", endCursor);
    }

    // endregion IJsonDeserializable
};

// endregion Impl

// region PageInfo

[[maybe_unused]]
PageInfo::PageInfo()
    : JsonDeserializableBase(),
      _pimpl(std::make_unique<Impl>())
{
}

[[maybe_unused]]
PageInfo::PageInfo(const PageInfo& other)
    : JsonDeserializableBase(other),
      _pimpl(std::make_unique<Impl>(*other._pimpl))
{
}

[[maybe_unused]]
PageInfo::PageInfo(PageInfo&& other) noexcept = default;

PageInfo::~PageInfo() = default;

[[maybe_unused]]
const std::optional<bool>& PageInfo::GetHasNextPage() const
{
    return _pimpl->GetHasNextPage();
}

[[maybe_unused]]
const std::optional<bool>& PageInfo::GetHasPreviousPage() const
{
    return _pimpl->GetHasPreviousPage();
}

[[maybe_unused]]
const std::optional<std::string>& PageInfo::GetStartCursor() const
{
    return _pimpl->GetStartCursor();
}

[[maybe_unused]]
const std::optional<std::string>& PageInfo::GetEndCursor() const
{
    return _pimpl->GetEndCursor();
}

PageInfo& PageInfo::operator=(const PageInfo& rhs)
{
    JsonDeserializableBase::operator=(rhs);
    _pimpl = std::make_unique<Impl>(*rhs._pimpl);

    return *this;
}

PageInfo& PageInfo::operator=(PageInfo&& rhs) noexcept = default;

// region IJsonDeserializable

[[maybe_unused]]
void PageInfo::Deserialize(const JsonValue& json)
{
    JsonDeserializableBase::Deserialize(json);
    _pimpl->Deserialize(json);
}

// endregion IJsonDeserializable

// endregion PageInfo
