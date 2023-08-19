#ifndef ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP
#define ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/OperatorTransferParams.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/SimpleTransferParams.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class TransferRecipient;

/// \brief Definition for a pointer containing a TransferRecipient.
using TransferRecipientPtr [[maybe_unused]] = std::shared_ptr<TransferRecipient>;

/// \brief Models a parameter for setting the recipient account of a transfer.
class ENJINPLATFORMSDK_EXPORT TransferRecipient : public GraphQlParameter<TransferRecipient>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    TransferRecipient();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    TransferRecipient(const TransferRecipient& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    TransferRecipient(TransferRecipient&& other) noexcept;

    /// \brief Class destructor.
    ~TransferRecipient() override;

    /// \brief Sets the recipient account of the token.
    /// \param account The recipient account.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetAccount(SerializableStringPtr account);

    /// \brief Sets parameters for making a simple transfer.
    /// \param simpleParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetSimpleParams(SimpleTransferParamsPtr simpleParams);

    /// \brief Sets parameters for making an operator transfer.
    /// \param operatorParams The parameters.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    TransferRecipient& SetOperatorParams(OperatorTransferParamsPtr operatorParams);

    TransferRecipient& operator=(const TransferRecipient& rhs);

    TransferRecipient& operator=(TransferRecipient&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_TRANSFERRECIPIENT_HPP
