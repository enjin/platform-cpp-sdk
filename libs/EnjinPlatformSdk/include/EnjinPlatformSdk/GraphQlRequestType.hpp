#ifndef ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP
#define ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP

namespace enjin::platform::sdk
{
/// \brief Represents the types a GraphQL request may be.
enum class GraphQlRequestType
{
    Mutation, ///< Value for a mutation type of request.
    Query, ///< Value for a query type of request.
};
}

#endif //ENJINPLATFORMSDK_GRAPHQLREQUESTTYPE_HPP
