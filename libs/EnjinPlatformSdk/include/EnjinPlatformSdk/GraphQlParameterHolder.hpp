//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

#ifndef ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
#define ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <map>
#include <sstream>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Abstract class implementation for GraphQL inputs which hold parameters.
/// \tparam THolder The type of the parameter holder. Must extend this class.
template<class THolder>
class GraphQlParameterHolder : virtual public IGraphQlParameterHolder<THolder>
{
    std::map<std::string, SerializablePtr> _parameters;

    static constexpr char ColonSeparator[] = ": ";
    static constexpr char CommaSeparator[] = ", ";

public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    GraphQlParameterHolder(const GraphQlParameterHolder<THolder>& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    GraphQlParameterHolder(GraphQlParameterHolder<THolder>&& other) noexcept = default;

    /// \brief Class destructor.
    ~GraphQlParameterHolder() override = default;

    GraphQlParameterHolder& operator=(const GraphQlParameterHolder<THolder>& rhs) = default;

    GraphQlParameterHolder& operator=(GraphQlParameterHolder<THolder>&& rhs) noexcept = default;

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override
    {
        if (!HasParameters())
        {
            return {};
        }

        std::stringstream ss;

        const int parametersCount = _parameters.size();
        int parameterIdx = 0;

        for (const auto& [k, v] : _parameters)
        {
            parameterIdx++;

            if (v == nullptr)
            {
                continue;
            }

            ss << k << ColonSeparator << v->ToString();

            if (parameterIdx < parametersCount)
            {
                ss << CommaSeparator;
            }
        }

        return ss.str();
    }

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override
    {
        return _parameters;
    }

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override
    {
        return !_parameters.empty();
    }

    [[maybe_unused]]
    THolder& RemoveParameter(const std::string& key) override
    {
        _parameters.erase(key);

        return static_cast<THolder&>(*this);
    }

    [[maybe_unused]]
    THolder& SetParameter(std::string key, SerializablePtr value) override
    {
        if (value == nullptr)
        {
            _parameters.erase(key);
        }
        else
        {
            _parameters.emplace(key, value);
        }

        return static_cast<THolder&>(*this);
    }

    // endregion IGraphQlParameterHolder

protected:
    /// \brief Constructs an instance of this class.
    GraphQlParameterHolder() = default;
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLPARAMETERHOLDER_HPP
