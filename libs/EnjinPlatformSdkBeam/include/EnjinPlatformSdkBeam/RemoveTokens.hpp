#ifndef ENJINPLATFORMSDKBEAM_REMOVETOKENS_HPP
#define ENJINPLATFORMSDKBEAM_REMOVETOKENS_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/IntegerRange.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for removing tokens from a beam.
class ENJINPLATFORMSDKBEAM_EXPORT RemoveTokens : public GraphQlRequest<RemoveTokens>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    RemoveTokens();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    RemoveTokens(const RemoveTokens& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    RemoveTokens(RemoveTokens&& other) noexcept;

    /// \brief Class destructor.
    ~RemoveTokens() override;

    /// \brief Sets the code of the beam.
    /// \param code The code.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveTokens& SetCode(SerializableStringPtr code);

    /// \brief Sets the IDs of the tokens to remove.
    /// \param tokenIds The token IDs.
    /// \return This request for chaining.
    [[maybe_unused]]
    RemoveTokens& SetTokenIds(std::shared_ptr<SerializableArray<IntegerRange>> tokenIds);

    RemoveTokens& operator=(const RemoveTokens& rhs);

    RemoveTokens& operator=(RemoveTokens&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_REMOVETOKENS_HPP
