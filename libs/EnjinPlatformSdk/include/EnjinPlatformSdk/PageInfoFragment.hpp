#ifndef ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP
#define ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IGraphQlFragment.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class PageInfoFragment;

/// \brief Definition for a pointer containing a PageInfoFragment.
using PageInfoFragmentPtr [[maybe_unused]] = std::shared_ptr<PageInfoFragment>;

/// \brief A fragment for requesting properties of a PageInfo returned by the platform.
class ENJINPLATFORMSDK_EXPORT PageInfoFragment : public IGraphQlFragment<PageInfoFragment>
{
    /// \brief The implementation of this class.
    class Impl;

    std::unique_ptr<Impl> _pimpl;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    PageInfoFragment();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PageInfoFragment(const PageInfoFragment& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PageInfoFragment(PageInfoFragment&& other) noexcept;

    /// \brief Class destructor.
    ~PageInfoFragment() override;

    /// \brief Sets whether the page info is to be returned with its hasNextPage property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasNextPage(bool isIncluded = true);

    /// \brief Sets whether the page info is to be returned with its hasPreviousPage property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasPreviousPage(bool isIncluded = true);

    /// \brief Sets whether the page info is to be returned with its startCursor property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasStartCursor(bool isIncluded = true);

    /// \brief Sets whether the page info is to be returned with its endCursor property.
    /// \param isIncluded Whether the field is included.
    /// \return This fragment for chaining.
    [[maybe_unused]]
    PageInfoFragment& WithHasEndCursor(bool isIncluded = true);

    PageInfoFragment& operator=(const PageInfoFragment& rhs);

    PageInfoFragment& operator=(PageInfoFragment&& rhs) noexcept;

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
    PageInfoFragment& WithField(std::string name, bool isIncluded) override;

    [[maybe_unused]]
    PageInfoFragment& WithField(std::string name, GraphQlFragmentPtr fragment) override;

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
    PageInfoFragment& RemoveParameter(const std::string& key) override;

    [[maybe_unused]]
    PageInfoFragment& SetParameter(std::string key, SerializablePtr value) override;

    // endregion IGraphQlParameterHolder
};
}

#endif //ENJINPLATFORMSDK_PAGEINFOFRAGMENT_HPP
