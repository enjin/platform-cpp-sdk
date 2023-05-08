#ifndef ENJINPLATFORMSDK_RESPONSEMESSAGE_HPP
#define ENJINPLATFORMSDK_RESPONSEMESSAGE_HPP

#include <map>
#include <string>

/// \brief Represents the data of a response sent by the mock HTTP server.
class ResponseMessage
{
    std::string _body;
    std::map<std::string, std::string> _headers;
    int _statusCode = 0;

public:
    /// \brief Class destructor.
    ~ResponseMessage();

private:
    ResponseMessage();

    friend class MockHttpServer;
};

#endif //ENJINPLATFORMSDK_RESPONSEMESSAGE_HPP
