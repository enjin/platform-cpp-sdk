#ifndef ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLFRAGMENTORDVIOLATION_HPP
#define ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLFRAGMENTORDVIOLATION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief Dummy class to avoid one definition rule violation when using IGraphQlFragment in other libraries.
class ENJINPLATFORMSDK_EXPORT DummyClassToAvoidGraphQlFragmentORDViolation final
    : public GraphQlFragment<DummyClassToAvoidGraphQlFragmentORDViolation>
{
};
}

#endif //ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLFRAGMENTORDVIOLATION_HPP
