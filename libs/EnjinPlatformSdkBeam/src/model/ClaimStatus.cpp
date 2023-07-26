#include "EnjinPlatformSdkBeam/ClaimStatus.hpp"

#include <stdexcept>

using namespace enjin::platform::sdk;
using namespace enjin::platform::sdk::beam;

constexpr char Pending[] = "PENDING";
constexpr char InProgress[] = "IN_PROGRESS";
constexpr char Completed[] = "COMPLETED";
constexpr char Failed[] = "FAILED";

[[maybe_unused]]
std::string enjin::platform::sdk::beam::ToString(const ClaimStatus value)
{
    switch (value)
    {
        case ClaimStatus::Pending:
            return Pending;

        case ClaimStatus::InProgress:
            return InProgress;

        case ClaimStatus::Completed:
            return Completed;

        case ClaimStatus::Failed:
            return Failed;

        default:
            throw std::out_of_range("Value out of range for ClaimStatus enum");
    }
}

[[maybe_unused]]
bool enjin::platform::sdk::beam::TryGetField(const JsonValue& json,
                                             const std::string& key,
                                             std::optional<ClaimStatus>& outField)
{
    outField.reset();

    std::string value;

    if (!json.TryGetStringField(key, value))
    {
        return false;
    }

    if (value == Pending)
    {
        outField = ClaimStatus::Pending;
    }
    else if (value == InProgress)
    {
        outField = ClaimStatus::InProgress;
    }
    else if (value == Completed)
    {
        outField = ClaimStatus::Completed;
    }
    else if (value == Failed)
    {
        outField = ClaimStatus::Failed;
    }

    return outField.has_value();
}
