#ifndef ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP
#define ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP

#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL fragments to extend from.
/// \tparam TFragment The fragment type. Must extend this class.
template<class TFragment>
class GraphQlFragment : public GraphQlParameterHolder<TFragment>,
                        public IGraphQlFragment<TFragment>
{
    std::map<std::string, GraphQlFragmentPtr> _fragmentFields;
    std::set<std::string> _scalarFields;

public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlFragment(const GraphQlFragment<TFragment>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlFragment(GraphQlFragment<TFragment>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlFragment() override = default;

    GraphQlFragment& operator=(const GraphQlFragment<TFragment>& rhs) = default;

    GraphQlFragment& operator=(GraphQlFragment<TFragment>&& rhs) noexcept = default;

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override
    {
        return GraphQlParameterHolder<TFragment>::CompileParameters();
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return GraphQlParameterHolder<TFragment>::HasParameters();
    }

    [[maybe_unused]]
    TFragment& SetParameter(std::string key, StringSerializablePtr value) override
    {
        return GraphQlParameterHolder<TFragment>::SetParameter(std::move(key), std::move(value));
    }

    [[maybe_unused]]
    TFragment& SetParameter(std::string key, std::vector<StringSerializablePtr> values) override
    {
        return GraphQlParameterHolder<TFragment>::SetParameter(std::move(key), std::move(values));
    }

    // endregion IGraphQlParameterHolder

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override
    {
        std::stringstream ss;

        const int fieldsCount = _fragmentFields.size() + _scalarFields.size();
        int i = 0;

        // Compile scalar fields
        for (const std::string& k : _scalarFields)
        {
            ss << k;

            if (i < fieldsCount - 1)
            {
                ss << " ";
            }

            i++;
        }

        // Compile fragment fields
        for (const auto& [k, v] : _fragmentFields)
        {
            ss << k << " { " << v->CompileFields() << " }";

            if (i < fieldsCount - 1)
            {
                ss << " ";
            }

            i++;
        }

        return ss.str();
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override
    {
        return _fragmentFields.contains(name) || _scalarFields.contains(name);
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override
    {
        return !_fragmentFields.empty() || !_scalarFields.empty();
    }

    [[maybe_unused]]
    TFragment& RemoveField(const std::string& name) override
    {
        _fragmentFields.erase(name);
        _scalarFields.erase(name);

        return static_cast<TFragment&>(*this);
    }

    [[maybe_unused]]
    TFragment& WithField(std::string name) override
    {
        RemoveField(name);

        _scalarFields.emplace(std::move(name));

        return static_cast<TFragment&>(*this);
    }

    [[maybe_unused]]
    TFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override
    {
        RemoveField(name);

        if (fragment != nullptr)
        {
            _fragmentFields.emplace(std::move(name), std::move(fragment));
        }

        return static_cast<TFragment&>(*this);
    }

    // endregion IGraphQlFragment

protected:
    /// \brief Constructs an instance of this class.
    GraphQlFragment() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP
