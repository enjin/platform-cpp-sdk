#ifndef ENJINPLATFORMSDK_GETTOKENS_HPP
#define ENJINPLATFORMSDK_GETTOKENS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenIdArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TokenFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request for querying an array of tokens from a collection, optionally filtered by token IDs.
class ENJINPLATFORMSDK_EXPORT GetTokens : public GraphQlRequest<GetTokens, TokenConnectionFragment>,
                                          public HasEncodableTokenIdArray<GetTokens>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GetTokens();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GetTokens(const GetTokens& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GetTokens(GetTokens&& other) noexcept;

    /// \brief Class destructor.
    ~GetTokens() override;

    /// \brief Sets the ID of the collection to return tokens from.
    /// \param collectionId The collection ID.
    /// \return This request for chaining.
    [[maybe_unused]]
    GetTokens& SetCollectionId(SerializableStringPtr collectionId);

    GetTokens& operator=(const GetTokens& rhs);

    GetTokens& operator=(GetTokens&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_GETTOKENS_HPP
