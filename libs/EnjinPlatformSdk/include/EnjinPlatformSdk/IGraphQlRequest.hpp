#ifndef ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP
#define ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP

#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlUploadHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

namespace enjin::platform::sdk
{
template<class...>
class IGraphQlRequest;

/// \brief Interface for GraphQL requests.
template<class...>
class IGraphQlRequest : virtual public IGraphQlUploadHolder
{
public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Returns the query string of this request.
    /// \return The query string for this request.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string Compile() const = 0;

    /// \brief Returns the name of this request.
    /// \return The name.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string GetName() const = 0;

    /// \brief Returns the variables mapping for this request without their types.
    /// \return The variables mapping.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::map<std::string, SerializablePtr>& GetVariablesWithoutTypes() const = 0;

    /// \brief Determines whether this request has a variable of the given name.
    /// \param name The variable name.
    /// \return Whether this request has the variable.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasVariable(const std::string& name) const = 0;

    /// \brief Determines whether this request has variables.
    /// \return Whether this request has variables.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasVariables() const = 0;
};

/// \brief Interface for GraphQL requests with a settable variables for the operation.
/// \tparam TRequest The type of the request. Must implement this interface.
template<class TRequest>
class IGraphQlRequest<TRequest> : virtual public IGraphQlRequest<>
{
public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Sets a variable for this request.
    /// \param name The variable name.
    /// \param type The variable type.
    /// \param value The variable value.
    /// \return This request for chaining.
    [[maybe_unused]]
    virtual TRequest& SetVariable(std::string name, std::string type, SerializablePtr value) = 0;

    /// \brief Removes a variable with the given name from this request.
    /// \param name The variable name.
    /// \return This request for chaining.
    [[maybe_unused]]
    virtual TRequest& RemoveVariable(const std::string& name) = 0;
};

/// \brief Interface for GraphQL requests with a settable fragment for response data.
/// \tparam TRequest The type of the request. Must implement this interface.
/// \tparam TFragment The type of the fragment. Must implement IGraphQlFragment.
template<class TRequest, class TFragment>
class IGraphQlRequest<TRequest, TFragment> : virtual public IGraphQlRequest<TRequest>
{
    static_assert(std::is_base_of<IGraphQlFragment<>, TFragment>::value,
                  "Type TFragment does not implement IGraphQlFragment<>");

public:
    /// \brief Class destructor.
    ~IGraphQlRequest() override = default;

    /// \brief Determines whether a fragment is attached to this request.
    /// \return Whether a fragment is attached to this request.
    [[maybe_unused]]
    [[nodiscard]]
    virtual bool HasFragment() const = 0;

    /// \brief Sets the fragment defining the response data for this request.
    /// \param fragment The fragment.
    /// \return This request for chaining.
    [[maybe_unused]]
    virtual TRequest& SetFragment(std::shared_ptr<TFragment> fragment) = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLREQUEST_HPP
