#ifndef ENJINPLATFORMSDKFUELTANKS_FUELTANKSTYPES_HPP
#define ENJINPLATFORMSDKFUELTANKS_FUELTANKSTYPES_HPP

#include "enjinplatformsdkfueltanks_export.h"

namespace enjin::platform::sdk::fuelTanks
{
/// \brief Contains fields describing variable types used in the platform's Fuel Tanks API.
class ENJINPLATFORMSDKFUELTANKS_EXPORT FuelTanksTypes final
{
public:
    // AccountRuleInputType

    /// <summary>
    /// String for AccountRuleInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char AccountRuleInputType[] = "AccountRuleInputType!";

    /// <summary>
    /// String for an array of AccountRuleInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char AccountRuleInputTypeArray[] = "[AccountRuleInputType!]!";

    // DispatchInputType

    /// <summary>
    /// String for DispatchInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchInputType[] = "DispatchInputType!";

    /// <summary>
    /// String for an array of DispatchInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchInputTypeArray[] = "[DispatchInputType!]!";

    // DispatchRuleEnum

    /// <summary>
    /// String for DispatchRuleEnum type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchRuleEnum[] = "DispatchRuleEnum!";

    /// <summary>
    /// String for an array of DispatchRuleEnum type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchRuleEnumArray[] = "[DispatchRuleEnum!]!";

    // DispatchRuleInputType

    /// <summary>
    /// String for DispatchRuleInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchRuleInputType[] = "DispatchRuleInputType!";

    /// <summary>
    /// String for an array of DispatchRuleInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char DispatchRuleInputTypeArray[] = "[DispatchRuleInputType!]!";

    // FuelTankMutationInputType

    /// <summary>
    /// String for FuelTankMutationInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char FuelTankMutationInputType[] = "FuelTankMutationInputType!";

    /// <summary>
    /// String for an array of FuelTankMutationInputType type.
    /// </summary>
    [[maybe_unused]]
    static constexpr char FuelTankMutationInputTypeArray[] = "[FuelTankMutationInputType!]!";

    FuelTanksTypes() = delete;
};
}

#endif //ENJINPLATFORMSDKFUELTANKS_FUELTANKSTYPES_HPP
