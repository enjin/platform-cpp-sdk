#ifndef ENJINPLATFORMSDK_RESPONSEPROVIDER_HPP
#define ENJINPLATFORMSDK_RESPONSEPROVIDER_HPP

#include "Response.hpp"
#include <optional>

/// \brief Provider for stubbed responses.
class ResponseProvider
{
    std::optional<Response> _response;

public:
    /// \brief Class destructor.
    ~ResponseProvider();

    /// \brief Sets the response to be stubbed.
    /// \param response The stubbed response.
    [[maybe_unused]]
    void RespondWith(Response response);

private:
    ResponseProvider();

    friend class MockHttpServer;
};

#endif //ENJINPLATFORMSDK_RESPONSEPROVIDER_HPP
