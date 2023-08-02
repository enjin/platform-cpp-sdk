#ifndef ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP
#define ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP

#include "EnjinPlatformSdk/DateTime.hpp"
#include "EnjinPlatformSdk/IGraphQlParameterHolder.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <type_traits>
#include <utility>

namespace enjin::platform::sdk::beam
{
/// \brief Abstract class to be inherited by a GraphQL parameter holder to set common beam parameters.
/// \tparam THolder The type of the parameter setter. Must extend this class and implement IGraphQlParameterHolder.
template<class THolder>
class HasBeamCommonFields
{
public:
    /// \brief Class destructor.
    ~HasBeamCommonFields() = default;

    /// \brief Sets the name of the beam.
    /// \param name The name.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetName(SerializableStringPtr name)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("name", std::move(name));
    }

    /// \brief Sets the description of the beam.
    /// \param description The description.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetDescription(SerializableStringPtr description)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("description", std::move(description));
    }

    /// \brief Sets the image URL of the beam.
    /// \param image The image URL.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetImage(SerializableStringPtr image)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("image", std::move(image));
    }

    /// \brief Sets the start date of the claim period.
    /// \param start The start date.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetStart(DateTimePtr start)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("start", std::move(start));
    }

    /// \brief Sets the end date of the claim period.
    /// \param end The end date.
    /// \return This parameter holder for chaining.
    [[maybe_unused]]
    THolder& SetEnd(DateTimePtr end)
    {
        static_assert(std::is_base_of<IGraphQlParameterHolder<THolder>, THolder>::value,
                      "Type THolder does not implement IGraphQlParameterHolder<THolder>");

        return static_cast<THolder&>(*this).SetParameter("end", std::move(end));
    }

protected:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    HasBeamCommonFields() = default;
};
}

#endif //ENJINPLATFORMSDKBEAM_HASBEAMCOMMONFIELDS_HPP
