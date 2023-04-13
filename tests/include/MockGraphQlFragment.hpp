#ifndef ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP
#define ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Mock class for IGraphQlFragment.
class MockGraphQlFragment : public IGraphQlFragment<MockGraphQlFragment>
{
public:
    // region IGraphQlFragment

    MOCK_METHOD(std::string, CompileFields, (), (const));

    MOCK_METHOD(bool, HasField, (const std::string& name), (const));

    MOCK_METHOD(bool, HasFields, (), (const));

    MOCK_METHOD(MockGraphQlFragment&, RemoveField, (const std::string& name), ());

    MOCK_METHOD(MockGraphQlFragment&, WithField, (std::string name), ());

    MOCK_METHOD(MockGraphQlFragment&, WithField, (std::string name, GraphQlFragmentPtr fragment), ());

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    MOCK_METHOD(std::string, CompileParameters, (), (const));

    MOCK_METHOD(bool, HasParameters, (), (const));

    MOCK_METHOD(MockGraphQlFragment&, SetParameter, (std::string key, StringSerializablePtr value), ());

    MOCK_METHOD(MockGraphQlFragment&, SetParameter, (std::string key, std::vector<StringSerializablePtr> values), ());

    // endregion IGraphQlParameterHolder
};

/// \brief Definition for a nice mock of IGraphQlFragment.
typedef testing::NiceMock<MockGraphQlFragment> NiceMockGraphQlFragment;

/// \brief Definition for a pointer containing a nice mock of IGraphQlFragment.
typedef std::shared_ptr<NiceMockGraphQlFragment> MockGraphQlFragmentPtr;
}

#endif //ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP
