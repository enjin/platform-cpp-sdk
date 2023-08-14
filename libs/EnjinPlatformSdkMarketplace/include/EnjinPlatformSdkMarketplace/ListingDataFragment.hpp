#ifndef ENJINPLATFORMSDKMARKETPLACE_LISTINGDATAFRAGMENT_HPP
#define ENJINPLATFORMSDKMARKETPLACE_LISTINGDATAFRAGMENT_HPP

#include "EnjinPlatformSdk/IGraphQlFragment.hpp"

namespace enjin::platform::sdk::marketplace
{
/// \brief A fragment for requesting properties of a ListingData returned by the platform.
/// \tparam TFragment The type of the listing data fragment. Must extend this class.
template<class TFragment>
class ListingDataFragment : public virtual IGraphQlFragment<TFragment>
{
public:
    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ListingDataFragment(const ListingDataFragment& other) = default;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ListingDataFragment(ListingDataFragment&& other) noexcept = default;

    /// \brief Class destructor.
    ~ListingDataFragment() override = default;

    ListingDataFragment& operator=(const ListingDataFragment& rhs) = default;

    ListingDataFragment& operator=(ListingDataFragment&& rhs) noexcept = default;

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ListingDataFragment() = default;
};
}

#endif //ENJINPLATFORMSDKMARKETPLACE_LISTINGDATAFRAGMENT_HPP
