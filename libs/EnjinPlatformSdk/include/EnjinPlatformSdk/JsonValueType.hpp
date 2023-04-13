#ifndef ENJINPLATFORMSDK_JSONVALUETYPE_HPP
#define ENJINPLATFORMSDK_JSONVALUETYPE_HPP

namespace enjin::platform::sdk
{
/// \brief Values representing the types of a JSON value.
enum class JsonValueType
{
    Null, ///< Represents a null value.
    Array, ///< Represents an array value.
    Object, ///< Represents an object value.
    String, ///< Represents a string value.
    Bool, ///< Represents a boolean value.
    Number, ///< Represents a number value.
};
}

#endif //ENJINPLATFORMSDK_JSONVALUETYPE_HPP
