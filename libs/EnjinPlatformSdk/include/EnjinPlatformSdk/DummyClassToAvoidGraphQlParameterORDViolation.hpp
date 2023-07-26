#ifndef ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLPARAMETERORDVIOLATION_HPP
#define ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLPARAMETERORDVIOLATION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"

namespace enjin::platform::sdk
{
/// \brief Dummy class to avoid one definition rule violation when using IGraphQlParameter in other libraries.
class ENJINPLATFORMSDK_EXPORT DummyClassToAvoidGraphQlParameterORDViolation final
    : public GraphQlParameter<DummyClassToAvoidGraphQlParameterORDViolation>
{
};
}

#endif //ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLPARAMETERORDVIOLATION_HPP
