#ifndef ENJINPLATFORMSDK_EDGEFRAGMENT_HPP
#define ENJINPLATFORMSDK_EDGEFRAGMENT_HPP

#include "EnjinPlatformSdk/internal/EdgeFragmentBase.hpp"
#include <memory>
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
template<class...>
class EdgeFragment;

/// \brief A fragment for requesting properties of a scalar edge returned by the platform.
template<class...>
class EdgeFragment : public EdgeFragmentBase<EdgeFragment<>>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    EdgeFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EdgeFragment(const EdgeFragment& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EdgeFragment(EdgeFragment&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragment() override = default;

    /// \brief Sets this fragment to request that the node property be returned with the page info.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& WithNode(bool isIncluded = true)
    {
        return GraphQlFragment<EdgeFragment>::WithField("node", isIncluded);
    }

    EdgeFragment& operator=(const EdgeFragment& rhs) = default;

    EdgeFragment& operator=(EdgeFragment&& rhs) noexcept = default;
};

/// \brief A fragment for requesting properties of a non-scalar edge returned by the platform.
/// \tparam TFragment The fragment describing the non-scalar data. Must implement IGraphQlFragment<TFragment>.
template<class TFragment>
class EdgeFragment<TFragment> : public EdgeFragmentBase<EdgeFragment<TFragment>>
{
    static_assert(std::is_base_of<IGraphQlFragment<TFragment>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<TFragment>");

public:
    /// \brief Constructs an instance of this class.
    EdgeFragment() = default;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    EdgeFragment(const EdgeFragment<TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    EdgeFragment(EdgeFragment<TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragment() override = default;

    /// \brief Sets this fragment to request that the node property be returned with the page info.
    /// \param fragment The fragment.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    EdgeFragment& WithNode(std::shared_ptr<TFragment> fragment)
    {
        return GraphQlFragment<EdgeFragment>::WithField("node", std::move(fragment));
    }

    EdgeFragment& operator=(const EdgeFragment<TFragment>& rhs) = default;

    EdgeFragment& operator=(EdgeFragment<TFragment>&& rhs) noexcept = default;
};
}

#endif //ENJINPLATFORMSDK_EDGEFRAGMENT_HPP
