#ifndef ENJINPLATFORMSDK_REQUESTMESSAGE_HPP
#define ENJINPLATFORMSDK_REQUESTMESSAGE_HPP

#include <map>
#include <string>

/// \brief Represents the data of a request received by the mock HTTP server.
class RequestMessage
{
    std::string _body;
    std::map<std::string, std::string> _headers;
    std::string _method;
    std::string _path;

public:
    /// \brief Class destructor.
    ~RequestMessage();

private:
    RequestMessage();

    friend class MockHttpServer;
};

#endif //ENJINPLATFORMSDK_REQUESTMESSAGE_HPP
