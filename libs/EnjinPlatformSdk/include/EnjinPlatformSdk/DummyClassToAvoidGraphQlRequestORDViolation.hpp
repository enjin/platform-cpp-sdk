#ifndef ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLREQUESTORDVIOLATION_HPP
#define ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLREQUESTORDVIOLATION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"

namespace enjin::platform::sdk
{
/// \brief Dummy class to avoid one definition rule violation when using IGraphQlRequest in other libraries.
class ENJINPLATFORMSDK_EXPORT DummyClassToAvoidGraphQlRequestORDViolation final
    : public GraphQlRequest<DummyClassToAvoidGraphQlRequestORDViolation>
{
};
}

#endif //ENJINPLATFORMSDK_DUMMYCLASSTOAVOIDGRAPHQLREQUESTORDVIOLATION_HPP
