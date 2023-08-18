#ifndef ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP

#include "EnjinPlatformSdk/ISerializable.hpp"
#include <map>
#include <string>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlParameterHolder;

/// \brief Interface for GraphQL inputs which hold parameters.
template<class...>
class IGraphQlParameterHolder
{
public:
    /// \brief Class destructor.
    virtual ~IGraphQlParameterHolder() = default;

    /// \brief Compiles the parameters within this holder and returns them as a string.
    /// \return The compiled string.
    /// \remarks This member-function will return an empty string if this holder has no parameters
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string CompileParameters() const = 0;

    /// \brief Returns the parameters held by this holder.
    /// \return The parameters.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, SerializablePtr>& GetParameters() const = 0;

    /// \brief Determines whether this holder currently has a parameter with the given key.
    /// \param key The parameter key.
    /// \return Whether a parameter is being held.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasParameter(const std::string& key) const = 0;

    /// \brief Determines whether this holder has any parameters stored in it.
    /// \return Whether this holder has any parameters stored in it.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasParameters() const = 0;
};

/// \brief Interface for setting parameters for GraphQL inputs which hold parameters.
/// \tparam THolder The type of the parameter holder. Must implement this interface.
template<class THolder>
class IGraphQlParameterHolder<THolder> : public virtual IGraphQlParameterHolder<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameterHolder() override = default;

    /// \brief Removes the specified parameter from this holder.
    /// \param key The parameter key.
    /// \return This holder for chaining.
    [[maybe_unused]]
    virtual THolder& RemoveParameter(const std::string& key) = 0;

    /// \brief Sets parameter to be stored by this holder.
    /// \param key The parameter key.
    /// \param value The parameter value.
    /// \return This holder for chaining.
    [[maybe_unused]]
    virtual THolder& SetParameter(std::string key, SerializablePtr value) = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP
