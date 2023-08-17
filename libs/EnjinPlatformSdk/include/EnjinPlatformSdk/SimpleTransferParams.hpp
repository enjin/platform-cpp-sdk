#ifndef ENJINPLATFORMSDK_SIMPLETRANSFERPARAMS_HPP
#define ENJINPLATFORMSDK_SIMPLETRANSFERPARAMS_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/HasEncodableTokenId.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class SimpleTransferParams;

/// \brief Definition for a pointer containing a simple transfer parameters.
using SimpleTransferParamsPtr [[maybe_unused]] = std::shared_ptr<SimpleTransferParams>;

/// \brief Models a parameter for parameters to make a simple transfer.
class ENJINPLATFORMSDK_EXPORT SimpleTransferParams : public GraphQlParameter<SimpleTransferParams>,
                                                     public HasEncodableTokenId<SimpleTransferParams>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    SimpleTransferParams();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    SimpleTransferParams(const SimpleTransferParams& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    SimpleTransferParams(SimpleTransferParams&& other) noexcept;

    /// \brief Class destructor.
    ~SimpleTransferParams() override;

    /// \brief Sets the amount to transfer.
    /// \param amount The amount.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    SimpleTransferParams& SetAmount(SerializableStringPtr amount);

    /// \brief Sets whether the transaction will be kept from failing if the balance drops below the minimum
    /// requirement.
    /// \param keepAlive Whether the transaction will be kept from failing.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    SimpleTransferParams& SetKeepAlive(SerializableBoolPtr keepAlive);

    SimpleTransferParams& operator=(const SimpleTransferParams& rhs);

    SimpleTransferParams& operator=(SimpleTransferParams&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_SIMPLETRANSFERPARAMS_HPP
