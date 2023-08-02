#ifndef ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP
#define ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP

#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/SerializableBool.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk::beam
{
template<class THolder>
class HasBeamCommonFields
{
public:
    ~HasBeamCommonFields() = default;

    [[maybe_unused]]
    THolder& SetName(SerializableStringPtr name)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("name", std::move(name));
    }

    [[maybe_unused]]
    THolder& SetDescription(SerializableStringPtr description)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("description", std::move(description));
    }

    [[maybe_unused]]
    THolder& SetImage(SerializableStringPtr image)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("image", std::move(image));
    }

    [[maybe_unused]]
    THolder& SetStart(DateTimePtr start)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("start", std::move(start));
    }

    [[maybe_unused]]
    THolder& SetEnd(DateTimePtr end)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("end", std::move(end));
    }

    [[maybe_unused]]
    THolder& SetSingleUse(SerializableBoolPtr singleUse)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("singleUse", std::move(singleUse));
    }

protected:
    [[maybe_unused]]
    HasBeamCommonFields() = default;
};
}

#endif //ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP
