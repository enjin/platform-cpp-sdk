#ifndef ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP
#define ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP

#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set an idempotency key.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasIdempotencyKey
{
public:
    /// \brief Class destructor.
    ~HasIdempotencyKey() = default;

    /// \brief Sets the idempotency key to set. It is recommended to use a UUID for this.
    /// \param idempotencyKey The idempotency key.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetIdempotencyKey(SerializableStringPtr idempotencyKey)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("idempotencyKey", std::move(idempotencyKey));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasIdempotencyKey() = default;
};
}

#endif //ENJINPLATFORMSDK_HASIDEMPOTENCYKEY_HPP
