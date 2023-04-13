#ifndef ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP
#define ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/JsonValue.hpp"

namespace enjin::platform::sdk
{
/// \brief Interface for JSON deserializable types.
class ENJINPLATFORMSDK_EXPORT [[maybe_unused]] IJsonDeserializable
{
public:
    /// \brief Class destructor.
    virtual ~IJsonDeserializable() = default;

    /// \brief Sets member-fields on this object using the given JSON value.
    /// \param json The JSON value.
    [[maybe_unused]]
    virtual void Deserialize(const JsonValue& json) = 0;

    bool operator==(const IJsonDeserializable& rhs) const = default;

    bool operator!=(const IJsonDeserializable& rhs) const = default;
};
}

#endif //ENJINPLATFORMSDK_IJSONDESERIALIZABLE_HPP
