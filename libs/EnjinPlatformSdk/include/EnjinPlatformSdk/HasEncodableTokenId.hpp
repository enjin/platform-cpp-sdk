#ifndef ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP
#define ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP

#include "EnjinPlatformSdk/EncodableTokenIdInput.hpp"
#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set an encodable token ID.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasEncodableTokenId
{
public:
    /// \brief Class destructor.
    ~HasEncodableTokenId() = default;

    /// \brief Sets the token ID.
    /// \param tokenId The token ID.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetTokenId(EncodableTokenIdInputPtr tokenId)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("tokenId", std::move(tokenId));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasEncodableTokenId() = default;
};
}

#endif //ENJINPLATFORMSDK_HASENCODABLETOKENID_HPP
