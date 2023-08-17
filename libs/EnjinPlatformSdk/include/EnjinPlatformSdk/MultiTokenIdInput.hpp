#ifndef ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP
#define ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlParameter.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include <memory>

namespace enjin::platform::sdk
{
class MultiTokenIdInput;

using MultiTokenIdInputPtr [[maybe_unused]] = std::shared_ptr<MultiTokenIdInput>;

/// \brief Models a parameter for setting the unique identifier for a token. Composed using a collection ID and a token
/// ID.
class ENJINPLATFORMSDK_EXPORT MultiTokenIdInput : public GraphQlParameter<MultiTokenIdInput>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MultiTokenIdInput();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MultiTokenIdInput(const MultiTokenIdInput& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MultiTokenIdInput(MultiTokenIdInput&& other) noexcept;

    /// \brief Class destructor.
    ~MultiTokenIdInput() override;

    /// \brief Sets the collection ID of a multi-token.
    /// \param collectionId The collection ID.
    /// \return This parameter for chaining.
    [[maybe_unused]]
    MultiTokenIdInput& SetCollectionId(SerializableStringPtr collectionId);

    MultiTokenIdInput& operator=(const MultiTokenIdInput& rhs);

    MultiTokenIdInput& operator=(MultiTokenIdInput&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MULTITOKENIDINPUT_HPP
