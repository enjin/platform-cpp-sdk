#ifndef ENJINPLATFORMSDK_GRAPHQLBATCHRESPONSE_HPP
#define ENJINPLATFORMSDK_GRAPHQLBATCHRESPONSE_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/GraphQlResponse.hpp"
#include "EnjinPlatformSdk/internal/JsonDeserializableBase.hpp"
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Represents a batch GraphQL response message from the platform for a single operation.
/// \tparam TResult The type to be returned in the result.
class ENJINPLATFORMSDK_EXPORT GraphQlBatchResponse final : public JsonDeserializableBase
{
    std::vector<GraphQlResponse<JsonValue>> _responses;

public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    GraphQlBatchResponse();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    GraphQlBatchResponse(const GraphQlBatchResponse& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    GraphQlBatchResponse(GraphQlBatchResponse&& other) noexcept;

    /// \brief Class destructor.
    ~GraphQlBatchResponse() override;

    /// \brief Returns the number of responses in this batch.
    /// \return The number of responses.
    [[maybe_unused]]
    [[nodiscard]]
    size_t Size() const;

    GraphQlResponse<JsonValue>& operator[](size_t index);

    const GraphQlResponse<JsonValue>& operator[](size_t index) const;

    GraphQlBatchResponse& operator=(const GraphQlBatchResponse& rhs);

    GraphQlBatchResponse& operator=(GraphQlBatchResponse&& rhs) noexcept;

    bool operator==(const GraphQlBatchResponse& rhs) const;

    bool operator!=(const GraphQlBatchResponse& rhs) const;

    // region IJsonDeserializable

    [[maybe_unused]]
    void Deserialize(const JsonValue& json) override;

    // endregion IJsonDeserializable
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLBATCHRESPONSE_HPP
