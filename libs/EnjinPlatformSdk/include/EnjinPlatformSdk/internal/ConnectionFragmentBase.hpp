#ifndef ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP
#define ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP

#include "EnjinPlatformSdk/GraphQlFragment.hpp"
#include "EnjinPlatformSdk/PageInfoFragment.hpp"
#include "EnjinPlatformSdk/SerializableInt.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract base class for GraphQL fragments of the platform's Connection type to extend from.
/// \tparam TConnection The inheriting connection class. Must extend this class.
template<class TConnection>
class ConnectionFragmentBase : public GraphQlFragment<TConnection>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragmentBase() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragmentBase(const ConnectionFragmentBase<TConnection>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragmentBase(ConnectionFragmentBase<TConnection>&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragmentBase() override = default;

    /// \brief Sets the cursor to fetch.
    /// \param after The cursor.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& SetAfter(SerializableStringPtr after)
    {
        return GraphQlFragment<TConnection>::SetParameter("after", std::move(after));
    }

    /// \brief Sets the number results to return per page.
    /// \param first The number of result per page.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& SetFirst(SerializableIntPtr first)
    {
        return GraphQlFragment<TConnection>::SetParameter("first", std::move(first));
    }

    /// \brief Sets the page info fragment to be used for getting the pageInfo property of the connection.
    /// \param fragment The page info fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& WithPageInfo(PageInfoFragmentPtr fragment)
    {
        return GraphQlFragment<TConnection>::WithField("pageInfo", std::move(fragment));
    }

    /// \brief Sets whether the connection is to be returned with its totalCount property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TConnection& WithTotalCount(bool isIncluded = true)
    {
        return GraphQlFragment<TConnection>::WithField("totalCount", isIncluded);
    }

    ConnectionFragmentBase& operator=(const ConnectionFragmentBase<TConnection>& rhs) = default;

    ConnectionFragmentBase& operator=(ConnectionFragmentBase<TConnection>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_CONNECTIONFRAGMENTBASE_HPP
