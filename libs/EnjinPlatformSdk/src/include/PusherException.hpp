#ifndef ENJINPLATFORMSDK_PUSHEREXCEPTION_HPP
#define ENJINPLATFORMSDK_PUSHEREXCEPTION_HPP

#include "enjinplatformsdk_export.h"
#include <exception>
#include <string>

namespace pusher
{
/// \brief Exception class for Pusher events.
class ENJINPLATFORMSDK_EXPORT PusherException : public std::exception
{
    int _code;
    std::string _what;

public:
    PusherException() = delete;

    /// \brief Constructs an instance of this class with the given error code and message.
    /// \param code The error code.
    /// \param message The message.
    [[maybe_unused]]
    PusherException(int code, const std::string& message);

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PusherException(const PusherException& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PusherException(PusherException&& other) noexcept;

    /// \brief Class destructor.
    ~PusherException() override;

    /// \brief Returns the error code of this exception.
    /// \return The error code.
    [[maybe_unused]]
    [[nodiscard]]
    int GetCode() const;

    PusherException& operator=(const PusherException& rhs);

    PusherException& operator=(PusherException&& rhs) noexcept;

    // region exception

    [[maybe_unused]]
    [[nodiscard]]
    const char* what() const noexcept override;

    // endregion exception
};
}

#endif //ENJINPLATFORMSDK_PUSHEREXCEPTION_HPP
