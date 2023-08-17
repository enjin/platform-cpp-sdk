#include "EnjinPlatformSdk/BurnParamsInput.hpp"

#include <utility>

using namespace enjin::platform::sdk;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput() = default;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput(const BurnParamsInput& other) = default;

[[maybe_unused]]
BurnParamsInput::BurnParamsInput(BurnParamsInput&& other) noexcept = default;

BurnParamsInput::~BurnParamsInput() = default;

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetAmount(SerializableStringPtr amount)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("amount", std::move(amount));
}

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetKeepAlive(SerializableBoolPtr keepAlive)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("keepAlive", std::move(keepAlive));
}

[[maybe_unused]]
BurnParamsInput& BurnParamsInput::SetRemoveTokenStorage(SerializableBoolPtr removeTokenStorage)
{
    return GraphQlParameter<BurnParamsInput>::SetParameter("removeTokenStorage", std::move(removeTokenStorage));
}

BurnParamsInput& BurnParamsInput::operator=(const BurnParamsInput& rhs) = default;

BurnParamsInput& BurnParamsInput::operator=(BurnParamsInput&& rhs) noexcept = default;
