#ifndef ENJINPLATFORMSDK_UPLOAD_HPP
#define ENJINPLATFORMSDK_UPLOAD_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/ISerializable.hpp"
#include <fstream>
#include <memory>

namespace enjin::platform::sdk
{
/// \brief Represents a file to be uploaded in an HTTP request.
struct ENJINPLATFORMSDK_EXPORT Upload : public ISerializable
{
    /// \brief The file for this upload.
    std::ifstream file;

    /// \brief Constructs an instance of this struct.
    [[maybe_unused]]
    Upload();

    /// \brief Constructs an instance of this struct with the given filestream.
    /// \param file The filestream.
    [[maybe_unused]]
    explicit Upload(std::ifstream file);

    Upload(const Upload& other) = delete;

    /// \brief Move constructor.
    /// \param other The other instance to move.
    Upload(Upload&& other) noexcept;

    /// \brief Struct destructor.
    ~Upload() override;

    Upload& operator=(const Upload& rhs) = delete;

    Upload& operator=(Upload&& rhs) noexcept;

    // region ISerializable

    [[maybe_unused]]
    [[nodiscard]]
    JsonValue ToJson() const override;

    [[maybe_unused]]
    [[nodiscard]]
    std::string ToString() const override;

    // endregion ISerializable
};
}

#endif //ENJINPLATFORMSDK_UPLOAD_HPP
