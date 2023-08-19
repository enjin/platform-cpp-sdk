#ifndef ENJINPLATFORMSDK_ATTRIBUTEFRAGMENT_HPP
#define ENJINPLATFORMSDK_ATTRIBUTEFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ConnectionFragment.hpp"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class AttributeFragment;

/// \brief Definition for a pointer containing an AttributeFragment.
using AttributeFragmentPtr [[maybe_unused]] = std::shared_ptr<AttributeFragment>;

/// \brief Definition for a ConnectionFragment containing an AttributeFragment.
using AttributeConnectionFragment [[maybe_unused]] = ConnectionFragment<AttributeFragment>;

/// \brief Definition for a pointer containing an AttributeConnectionFragment.
using AttributeConnectionFragmentPtr [[maybe_unused]] = std::shared_ptr<AttributeConnectionFragment>;

/// \brief A fragment for requesting properties of an attribute returned by the platform.
class ENJINPLATFORMSDK_EXPORT AttributeFragment : public IGraphQlFragment<AttributeFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    AttributeFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    AttributeFragment(const AttributeFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    AttributeFragment(AttributeFragment&& other) noexcept;

    /// \brief Class destructor.
    ~AttributeFragment() override;

    /// \brief Sets whether the attribute is to be returned with its key property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AttributeFragment& WithKey(bool isIncluded = true);

    /// \brief Sets whether the attribute is to be returned with its value property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    AttributeFragment& WithValue(bool isIncluded = true);

    AttributeFragment& operator=(const AttributeFragment& rhs);

    AttributeFragment& operator=(AttributeFragment&& rhs) noexcept;

    // region IGraphQlFragment

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileFields() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasField(const std::string& name) const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasFields() const override;

    [[maybe_unused]]
    AttributeFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    AttributeFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

    // endregion IGraphQlFragment

    // region IGraphQlParameterHolder

    [[maybe_unused]]
    [[nodiscard]]
    std::string CompileParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, SerializablePtr>& GetParameters() const override;

    [[maybe_unused]]
    [[nodiscard]]
    bool HasParameters() const override;

    [[maybe_unused]]
    AttributeFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    AttributeFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_ATTRIBUTEFRAGMENT_HPP
