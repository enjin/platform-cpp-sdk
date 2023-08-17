#ifndef ENJINPLATFORMSDK_MUTATECOLLECTION_HPP
#define ENJINPLATFORMSDK_MUTATECOLLECTION_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/CollectionMutationInput.hpp"
#include "EnjinPlatformSdk/GraphQlRequest.hpp"
#include "EnjinPlatformSdk/HasIdempotencyKey.hpp"
#include "EnjinPlatformSdk/HasSkipValidation.hpp"
#include "EnjinPlatformSdk/SerializableString.hpp"
#include "EnjinPlatformSdk/TransactionFragment.hpp"

namespace enjin::platform::sdk
{
/// \brief A request to act as a mutation for changing the default values of a collection.
class ENJINPLATFORMSDK_EXPORT MutateCollection : public GraphQlRequest<MutateCollection, TransactionFragment>,
                                                 public HasIdempotencyKey<MutateCollection>,
                                                 public HasSkipValidation<MutateCollection>
{
public:
    /// \brief Constructs an instance of this class.
    [[maybe_unused]]
    MutateCollection();

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    MutateCollection(const MutateCollection& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    MutateCollection(MutateCollection&& other) noexcept;

    /// \brief Class destructor.
    ~MutateCollection() override;

    /// \brief Sets the ID of the collection that will be mutated.
    /// \param collectionId The ID of the collection.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateCollection& SetCollectionId(SerializableStringPtr collectionId);

    /// \brief Sets the parameters that will be mutated.
    /// \param mutation The parameters.
    /// \return This request for chaining.
    [[maybe_unused]]
    MutateCollection& SetMutation(CollectionMutationInputPtr mutation);

    MutateCollection& operator=(const MutateCollection& rhs);

    MutateCollection& operator=(MutateCollection&& rhs) noexcept;
};
}

#endif //ENJINPLATFORMSDK_MUTATECOLLECTION_HPP
