#ifndef ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP
#define ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP

#include "EnjinPlatformSdk/GraphQlFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief Abstract base class for GraphQL fragments of the platform's edge type to extend from.
/// \tparam TEdge The inheriting edge class. Must extend this class.
template<class TEdge>
class EdgeFragmentBase : public GraphQlFragment<TEdge>
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    EdgeFragmentBase(const EdgeFragmentBase<TEdge>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    EdgeFragmentBase(EdgeFragmentBase<TEdge>&& other) noexcept = default;

    /// \brief Class destructor.
    ~EdgeFragmentBase() override = default;

    /// \brief Sets whether the edge is to be returned with its cursor property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    TEdge& WithCursor(bool isIncluded = true)
    {
        return GraphQlFragment<TEdge>::WithField("cursor", isIncluded);
    }

    EdgeFragmentBase& operator=(const EdgeFragmentBase<TEdge>& rhs) = default;

    EdgeFragmentBase& operator=(EdgeFragmentBase<TEdge>&& rhs) noexcept = default;

protected:
    /// \brief Constructs an instance of this class.
    EdgeFragmentBase() = default;
};
}

#endif //ENJINPLATFORMSDK_EDGEFRAGMENTBASE_HPP
