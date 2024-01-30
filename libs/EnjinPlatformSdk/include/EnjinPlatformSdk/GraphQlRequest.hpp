#ifndef ENJINPLATFORMSDK_GRAPHQLREQUEST_HPP
#define ENJINPLATFORMSDK_GRAPHQLREQUEST_HPP

#include "EnjinPlatformSdk/GraphQlRequestType.hpp"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include "EnjinPlatformSdk/internal/GraphQlRequestBase.hpp"
#include <memory>
#include <optional>
#include <stdexcept>
#include <sstream>
#include <string>
#include <utility>

namespace enjin::platform::sdk
{
template<class...>
class GraphQlRequest;

/// \brief Abstract class implementation for GraphQL requests which expect a scalar type in the response.
/// \tparam TRequest The type of the request. Must extend this class.
template<class TRequest>
class GraphQlRequest<TRequest> : public GraphQlRequestBase<TRequest>
{
public:
    GraphQlRequest() = delete;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlRequest(const GraphQlRequest<TRequest>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlRequest(GraphQlRequest<TRequest>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlRequest() override = default;

    GraphQlRequest<TRequest>& operator=(const GraphQlRequest<TRequest>& rhs) = default;

    GraphQlRequest<TRequest>& operator=(GraphQlRequest<TRequest>&& rhs) noexcept = default;

    // region IGraphQlRequest

    [[maybe_unused]]
    [[nodiscard]]
    std::string Compile() const override
    {
        std::stringstream ss;

        GraphQlRequestBase<TRequest>::AppendHeader(ss);
        ss << " }";

        return ss.str();
    }

    // endregion IGraphQlRequest

protected:
    /// \brief Initializes an instance of this class.
    /// \param name The name of the request.
    /// \param type The type of the request.
    GraphQlRequest(std::string name, GraphQlRequestType type)
        : GraphQlRequestBase<TRequest>(std::move(name), type)
    {
    }
};

/// \brief Abstract class implementation for GraphQL requests which expect an object type in the response.
/// \tparam TRequest The type of the request. Must extend this class.
/// \tparam TFragment The type of the fragment. Must implement IGraphQlFragment.
template<class TRequest, class TFragment>
class GraphQlRequest<TRequest, TFragment> : public GraphQlRequestBase<TRequest>,
                                            public virtual IGraphQlRequest<TRequest, TFragment>
{
    std::shared_ptr<TFragment> _fragment;

public:
    GraphQlRequest() = delete;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlRequest(const GraphQlRequest<TRequest, TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlRequest(GraphQlRequest<TRequest, TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlRequest() override = default;

    GraphQlRequest& operator=(const GraphQlRequest<TRequest, TFragment>& rhs) = default;

    GraphQlRequest& operator=(GraphQlRequest<TRequest, TFragment>&& rhs) noexcept = default;

    // region IGraphQlParameterHolder

    /// \brief Compiles the parameters within this request and returns them as a string.
    /// \return The compiled string.
    /// \remarks This method will return an empty string if neither this request nor its fragment currently hold any
    /// parameters.
    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override
    {
        const bool hasRequestParameters = HasRequestParameters();
        const bool hasFragmentParameters = HasFragmentParameters();

        if (!hasRequestParameters && !hasFragmentParameters)
        {
            return {};
        }

        std::stringstream ss;

        if (hasRequestParameters)
        {
            ss << GraphQlRequestBase<TRequest>::CompileParameters();

            if (hasFragmentParameters)
            {
                ss << " ";
            }
        }

        if (hasFragmentParameters)
        {
            ss << _fragment->CompileParameters();
        }

        //ss << GraphQlParameterHolder<TRequest>::CompileParameters();

        return ss.str();
    }

    /// \brief Determines whether this request has any parameters stored in it.
    /// \return Whether this request has any parameters stored in it.
    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return HasRequestParameters() || HasFragmentParameters();
    }

    // endregion IGraphQlParameterHolder

    // region IGraphQlRequest

    /// \brief Returns the query string of this request.
    /// \return The query string for this request.
    /// \throws std::runtime If this request has no attached fragment.
    [[maybe_unused]]
    [[nodiscard]]
    std::string Compile() const override
    {
        if (!HasFragment())
        {
            throw std::runtime_error("Cannot serialize request without a fragment");
        }

        std::stringstream ss;

        GraphQlRequestBase<TRequest>::AppendHeader(ss);
        ss << " { " << static_cast<IGraphQlFragment<>&>(*_fragment).CompileFields() << " } }";

        return ss.str();
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFragment() const override
    {
        return _fragment != nullptr;
    }

    [[maybe_unused]]
    TRequest& SetFragment(std::shared_ptr<TFragment> fragment) override
    {
        _fragment = std::move(fragment);
        return static_cast<TRequest&>(*this);
    }

    // endregion IGraphQlRequest

protected:
    /// \brief Initializes an instance of this class.
    /// \param name The name of the request.
    /// \param type The type of the request.
    GraphQlRequest(std::string name, GraphQlRequestType type)
        : GraphQlRequestBase<TRequest>(std::move(name), type)
    {
    }

private:
    /// \brief Determines whether this request has parameters from its attached fragment.
    /// \return Whether there are any parameters from the fragment.
    [[nodiscard]]
    bool HasFragmentParameters() const
    {
        return _fragment != nullptr && _fragment->HasParameters();
    }

    /// \brief Determines whether this request itself has any parameters. (Excludes parameters from its fragment)
    /// \return Whether there are any parameters exclusively from this request.
    [[nodiscard]]
    bool HasRequestParameters() const
    {
        return GraphQlRequestBase<TRequest>::HasParameters();
    }
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLREQUEST_HPP
