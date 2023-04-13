#ifndef ENJINPLATFORMSDK_ISTRINGSERIALIZABLE_HPP
#define ENJINPLATFORMSDK_ISTRINGSERIALIZABLE_HPP

#include <memory>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Interface for string serializable types.
class IStringSerializable
{
public:
    /// \brief Class destructor.
    virtual ~IStringSerializable() = default;

    /// \brief Converts this serializable into a string.
    /// \return The string representation of this class.
    [[maybe_unused]]
    [[nodiscard]]
    virtual std::string ToString() const = 0;
};

/// \brief Definition for a pointer containing a string serializable type.
[[maybe_unused]]
typedef std::shared_ptr<IStringSerializable> StringSerializablePtr;
}

#endif //ENJINPLATFORMSDK_ISTRINGSERIALIZABLE_HPP
