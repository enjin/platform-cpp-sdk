#include "ResponseProvider.hpp"

#include <utility>

ResponseProvider::ResponseProvider() = default;

ResponseProvider::~ResponseProvider() = default;

[[maybe_unused]]
void ResponseProvider::RespondWith(Response response)
{
    _response = std::move(response);
}
