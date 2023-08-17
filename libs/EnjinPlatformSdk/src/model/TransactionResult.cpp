#include "EnjinPlatformSdk/TransactionResult.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char ExtrinsicSuccess[] = "EXTRINSIC_SUCCESS";
constexpr char ExtrinsicFailed[] = "EXTRINSIC_FAILED";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TransactionResult value)
{
    switch (value)
    {
        case TransactionResult::None:
            return {};

        case TransactionResult::ExtrinsicSuccess:
            return ExtrinsicSuccess;

        case TransactionResult::ExtrinsicFailed:
            return ExtrinsicFailed;

        default:
            throw std::out_of_range("Value out of range for TransactionResult enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TransactionResult>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == "EXTRINSIC_SUCCESS")
    {
        outField = TransactionResult::ExtrinsicSuccess;
    }
    else if (value == "EXTRINSIC_FAILED")
    {
        outField = TransactionResult::ExtrinsicFailed;
    }

    return outField.has_value();
}
