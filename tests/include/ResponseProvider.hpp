//  Copyright 2023 Enjin Pte. Ltd.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.

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
