#ifndef ENJINPLATFORMSDK_HASCONTINUEONFAILURE_HPP
#define ENJINPLATFORMSDK_HASCONTINUEONFAILURE_HPP

#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set the continueOnFailure flag. Intended for
/// implementation by batch requests.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasContinueOnFailure
{
public:
    /// \brief Class destructor.
    ~HasContinueOnFailure() = default;

    /// \brief Sets whether data that would cause the whole batch to fail ought to be skipped.
    /// \param continueOnFailure Whether to skip data that would cause the batch to fail.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetContinueOnFailure(SerializableBoolPtr continueOnFailure)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("continueOnFailure", std::move(continueOnFailure));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasContinueOnFailure() = default;
};
}

#endif //ENJINPLATFORMSDK_HASCONTINUEONFAILURE_HPP
