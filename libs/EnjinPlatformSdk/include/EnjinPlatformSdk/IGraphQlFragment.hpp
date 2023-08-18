#ifndef ENJINPLATFORMSDK_IGRAPHQLFRAGMENT_HPP
#define ENJINPLATFORMSDK_IGRAPHQLFRAGMENT_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include <memory>
#include <string>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlFragment;

/// \brief Definition for a pointer containing a GraphQL fragment type.
using GraphQlFragmentPtr [[maybe_unused]] = std::shared_ptr<IGraphQlFragment<>>;

/// \brief Interface for GraphQL fragments.
template<class...>
class IGraphQlFragment : public virtual IGraphQlParameterHolder<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlFragment() override = default;

    /// \brief Compiles the fields within this fragment and returns them as a string.
    /// \return The compiled string.
    /// \throws std::runtime Thrown if called while no fields have been set on this fragment.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string CompileFields() const = 0;

    /// \brief Determines whether this fragment has requested a field of the given name is to be returned in the
    /// response data.
    /// \param name The name of the field.
    /// \return Whether the field has been requested.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasField(const std::string& name) const = 0;

    /// \brief Determines whether this fragment has any fields to be requested in the response data.
    /// \return Whether this fragment has any fields.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasFields() const = 0;
};

/// \brief Interface for GraphQL fragments with settable fields.
/// \tparam TFragment The fragment type. Must implement this interface.
template<class TFragment>
class IGraphQlFragment<TFragment> : public virtual IGraphQlParameterHolder<TFragment>,
                                    public virtual IGraphQlFragment<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlFragment() override = default;

    /// \brief Sets this fragment to request the scalar field with the given name be returned in the response type.
    /// \param name The name of the field.
    /// \param isIncluded Whether the field ought to be included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    virtual TFragment& WithField(std::string name, bool isIncluded) = 0;

    /// \brief Sets whether this fragment is to request the fragment field with the given name be returned in the
    /// response type.
    /// \param name The name of the field.
    /// \param fragment The fragment field.
    /// \return This fragment for chaining.
    /// \remarks If the given fragment for the field is a null pointer, then the field will be removed.
    [[maybe_unused]]
    virtual TFragment& WithField(std::string name, GraphQlFragmentPtr fragment) = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLFRAGMENT_HPP
