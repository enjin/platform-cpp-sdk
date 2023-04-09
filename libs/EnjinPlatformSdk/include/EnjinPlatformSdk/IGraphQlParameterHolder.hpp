#ifndef ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP

#include "EnjinPlatformSdk/IStringSerializable.hpp"
#include <map>
#include <string>
#include <vector>

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

    /// \brief Determines whether this holder has any parameters stored in it.
    /// \return Whether this holder has any parameters stored in it.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasParameters() const = 0;
};

/// \brief Interface for setting parameters for GraphQL inputs which hold parameters.
/// \tparam THolder The type of the parameter holder. Must implement this interface.
template<class THolder>
class IGraphQlParameterHolder<THolder> : public IGraphQlParameterHolder<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlParameterHolder() override = default;

    /// \brief Sets a singular parameter to be stored by this holder.
    /// \param key The parameter key.
    /// \param value The parameter value.
    /// \return This holder for chaining.
    [[maybe_unused]]
    virtual THolder& SetParameter(std::string key, StringSerializablePtr value) = 0;

    /// \brief Sets a value-array parameter to be stored by this holder.
    /// \param key The parameter key.
    /// \param values The parameter values.
    /// \return This holder for chaining.
    [[maybe_unused]]
    virtual THolder& SetParameter(std::string key, std::vector<StringSerializablePtr> values) = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLPARAMETERHOLDER_HPP
