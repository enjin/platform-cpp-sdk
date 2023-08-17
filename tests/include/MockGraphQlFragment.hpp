#ifndef ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP
#define ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP

#include "gmock/gmock.h"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <string>

namespace enjin::platform::sdk
{
class MockGraphQlFragment;

/// \brief Definition for a nice mock of IGraphQlFragment.
using NiceMockGraphQlFragment [[maybe_unused]] = testing::NiceMock<MockGraphQlFragment>;

/// \brief Definition for a pointer containing a nice mock of IGraphQlFragment.
using MockGraphQlFragmentPtr [[maybe_unused]] = std::shared_ptr<NiceMockGraphQlFragment>;

/// \brief Mock class for IGraphQlFragment.
class MockGraphQlFragment : virtual public IGraphQlFragment<MockGraphQlFragment>
{
public:
    // region IGraphQlFragment

    MOCK_METHOD(std::string, CompileFields, (), (const));

    MOCK_METHOD(bool, HasField, (const std::string& name), (const));

    MOCK_METHOD(bool, HasFields, (), (const));

    MOCK_METHOD(MockGraphQlFragment &, WithField, (std::string name, bool isIncluded), ());

    MOCK_METHOD(MockGraphQlFragment &, WithField, (std::string name, GraphQlFragmentPtr fragment), ());

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    MOCK_METHOD(std::string, CompileParameters, (), (const));

    MOCK_METHOD((const std::map<std::string, SerializablePtr>&), GetParameters, (), (const));

    MOCK_METHOD(bool, HasParameter, (const std::string& key), (const));

    MOCK_METHOD(bool, HasParameters, (), (const));

    MOCK_METHOD(MockGraphQlFragment &, RemoveParameter, (const std::string& key), ());

    MOCK_METHOD(MockGraphQlFragment &, SetParameter, (std::string key, SerializablePtr value), ());

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_MOCKGRAPHQLFRAGMENT_HPP
