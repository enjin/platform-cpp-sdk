#ifndef ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP
#define ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP

#include "EnjinPlatformSdk/EdgeFragment.hpp"
#include "EnjinPlatformSdk/PageInfoFragment.hpp"
#include "EnjinPlatformSdk/internal/ConnectionFragmentBase.hpp"
#include <memory>
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
template<class...>
class ConnectionFragment;

/// \brief A fragment for requesting properties of a scalar connection returned by the platform.
template<class...>
class ConnectionFragment : public ConnectionFragmentBase<ConnectionFragment<>>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragment(const ConnectionFragment& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragment(ConnectionFragment&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragment() override = default;

    /// \brief Sets the scalar edge fragment to be used for getting the edges property of the connection.
    /// \param fragment The scalar edge fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& WithEdge(std::shared_ptr<EdgeFragment<>> fragment)
    {
        return GraphQlFragment<ConnectionFragment<>>::WithField("edge", std::move(fragment));
    }

    ConnectionFragment& operator=(const ConnectionFragment& rhs) = default;

    ConnectionFragment& operator=(ConnectionFragment&& rhs) noexcept = default;
};

/// \brief A fragment for requesting properties of a non-scalar connection returned by the platform.
/// \tparam TFragment The fragment describing the non-scalar data. Must implement IGraphQlFragment<TFragment>.
template<class TFragment>
class ConnectionFragment<TFragment> : public ConnectionFragmentBase<ConnectionFragment<TFragment>>
{
    static_assert(std::is_base_of<IGraphQlFragment<TFragment>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<TFragment>");

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ConnectionFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ConnectionFragment(const ConnectionFragment<TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ConnectionFragment(ConnectionFragment<TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~ConnectionFragment() override = default;

    /// \brief Sets the non-scalar edge fragment to be used for getting the edges property of the connection.
    /// \param fragment The fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    ConnectionFragment& WithEdge(std::shared_ptr<EdgeFragment<TFragment>> fragment)
    {
        return GraphQlFragment<ConnectionFragment<TFragment>>::WithField("edge", std::move(fragment));
    }

    ConnectionFragment& operator=(const ConnectionFragment<TFragment>& rhs) = default;

    ConnectionFragment& operator=(ConnectionFragment<TFragment>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_CONNECTIONFRAGMENT_HPP
