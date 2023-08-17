#include "EnjinPlatformSdk/TransactionState.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;

constexpr char Abandoned[] = "ABANDONED";
constexpr char Pending[] = "PENDING";
constexpr char Processing[] = "PROCESSING";
constexpr char Broadcast[] = "BROADCAST";
constexpr char Executed[] = "EXECUTED";
constexpr char Finalized[] = "FINALIZED";

[[maybe_unused]]
std::string enjin::platform::sdk::ToString(const TransactionState value)
{
    switch (value)
    {
        case TransactionState::None:
            return {};

        case TransactionState::Abandoned:
            return Abandoned;

        case TransactionState::Pending:
            return Pending;

        case TransactionState::Processing:
            return Processing;

        case TransactionState::Broadcast:
            return Broadcast;

        case TransactionState::Executed:
            return Executed;

        case TransactionState::Finalized:
            return Finalized;

        default:
            throw std::out_of_range("Value out of range for TransactionState enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::TryGetField(const JsonValue& json,
                                       const std::string& key,
                                       std::optional<TransactionState>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Abandoned)
    {
        outField = TransactionState::Abandoned;
    }
    else if (value == Pending)
    {
        outField = TransactionState::Pending;
    }
    else if (value == Processing)
    {
        outField = TransactionState::Processing;
    }
    else if (value == Broadcast)
    {
        outField = TransactionState::Broadcast;
    }
    else if (value == Executed)
    {
        outField = TransactionState::Executed;
    }
    else if (value == Finalized)
    {
        outField = TransactionState::Finalized;
    }

    return outField.has_value();
}
