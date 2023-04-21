#ifndef ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP
#define ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP

#include <set>
#include <string>

namespace enjin::platform::sdk
{
/// \brief Interface for GraphQL types which hold parameters for file uploads.
class IGraphQlUploadHolder
{
public:
    /// \brief Class destructor.
    virtual ~IGraphQlUploadHolder() = default;

    /// \brief Returns the path of the upload parameters.
    /// \return The parameter paths.
    [[maybe_unused]]
    [[nodiscard]]
    virtual const std::set<std::string>& GetUploadParameterPaths() const = 0;
};
}

#endif //ENJINPLATFORMSDK_IGRAPHQLUPLOADHOLDER_HPP
