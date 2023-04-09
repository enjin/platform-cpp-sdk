#ifndef ENJINPLATFORMSDK_IJSONSERIALIZABLE_HPP
#define ENJINPLATFORMSDK_IJSONSERIALIZABLE_HPP

#include "EnjinPlatformSdk/JsonValue.hpp"
#include <memory>

namespace enjin::platform::sdk
{
/// \brief Interface for JSON serializable types.
class IJsonSerializable
{
public:
    /// \brief Class destructor.
    virtual ~IJsonSerializable() = default;

    /// \brief Converts this serializable to a JSON value.
    /// \return The JSON representation of this class.
    [[maybe_unused]]
    [[nodiscard]]
    virtual JsonValue ToJson() const = 0;
};

/// \brief Definition for a pointer containing a JSON serializable type.
[[maybe_unused]]
typedef std::shared_ptr<IJsonSerializable> JsonSerializablePtr;
}

#endif //ENJINPLATFORMSDK_IJSONSERIALIZABLE_HPP
