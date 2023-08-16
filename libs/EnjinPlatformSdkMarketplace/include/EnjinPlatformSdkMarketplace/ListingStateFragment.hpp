#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEFRAGMENT_HPP

#include "EnjinPlatformSdk/IGraphQlFragment.hpp"

namespace enjin::platform::sdk::marketplace
{
/// \brief A fragment for requesting properties of a ListingState returned by the platform.
/// \tparam TFragment The type of the listing data fragment. Must extend this class.
template<class TFragment>
class ListingStateFragment : public virtual IGraphQlFragment<TFragment>
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ListingStateFragment(const ListingStateFragment& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ListingStateFragment(ListingStateFragment&& other) noexcept = default;

    /// \brief Class destructor.
    ~ListingStateFragment() override = default;

    ListingStateFragment& operator=(const ListingStateFragment& rhs) = default;

    ListingStateFragment& operator=(ListingStateFragment&& rhs) noexcept = default;

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ListingStateFragment() = default;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGSTATEFRAGMENT_HPP
