#ifndef ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP
#define ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP

#include "EnjinPlatformSdk/GraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <map>
#include <set>
#include <sstream>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL fragments to extend from.
/// \tparam TFragment The fragment type. Must extend this class.
template<class TFragment>
class GraphQlFragment : public GraphQlParameterHolder<TFragment>,
                        virtual public IGraphQlFragment<TFragment>
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
    TFragment& WithField(std::string name, bool isIncluded) override
    {
        _fragmentFields.erase(name);

        if (isIncluded)
        {
            _scalarFields.emplace(std::move(name));
        }
        else
        {
            _scalarFields.erase(name);
        }

        return static_cast<TFragment&>(*this);
    }

    [[maybe_unused]]
    TFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override
    {
        _scalarFields.erase(name);

        if (fragment == nullptr)
        {
            _fragmentFields.erase(name);
        }
        else
        {
            _fragmentFields.emplace(std::move(name), std::move(fragment));
        }

        return static_cast<TFragment&>(*this);
    }

    // endregion IGraphQlFragment

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlFragment() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLFRAGMENT_HPP
