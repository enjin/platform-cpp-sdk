#ifndef ENJINPLATFORMSDKBEAM_EXPIRESSINGLEUSECODES_HPP
#define ENJINPLATFORMSDKBEAM_EXPIRESSINGLEUSECODES_HPP

#include "enjinplatformsdkbeam_export.h"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/SerializableArray.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"

#ifdef WIN32

#include "EnjinPlatformSdk/DummyClassToAvoidGraphQlRequestORDViolation.hpp"

#endif

namespace enjin::platform::sdk::beam
{
/// \brief A request to act as a mutation for setting single use beam codes to expire.
class ENJINPLATFORMSDKBEAM_EXPORT ExpiresSingleUseCodes : public GraphQlRequest<ExpiresSingleUseCodes>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    ExpiresSingleUseCodes();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    ExpiresSingleUseCodes(const ExpiresSingleUseCodes& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    ExpiresSingleUseCodes(ExpiresSingleUseCodes&& other) noexcept;

    /// \brief Class destructor.
    ~ExpiresSingleUseCodes() override;

    /// \brief Sets the array of single use codes.
    /// \param codes The single use codes.
    /// \return This request for chaining.
    [[maybe_unused]]
    ExpiresSingleUseCodes& SetCodes(SerializableStringArrayPtr codes);

    ExpiresSingleUseCodes& operator=(const ExpiresSingleUseCodes& rhs);

    ExpiresSingleUseCodes& operator=(ExpiresSingleUseCodes&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDKBEAM_EXPIRESSINGLEUSECODES_HPP
