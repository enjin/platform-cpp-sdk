#include "EnjinPlatformSdk/MintRecipient.hpp"

#include <utility>

using namespace enjin::platform::sdk;
using ParameterType = GraphQlParameter<MintRecipient>;

[[maybe_unused]]
MintRecipient::MintRecipient() = default;

[[maybe_unused]]
MintRecipient::MintRecipient(const MintRecipient& other) = default;

[[maybe_unused]]
MintRecipient::MintRecipient(MintRecipient&& other) noexcept = default;

MintRecipient::~MintRecipient() = default;

[[maybe_unused]]
MintRecipient& MintRecipient::SetAccount(SerializableStringPtr account)
{
    return ParameterType::SetParameter("account", std::move(account));
}

[[maybe_unused]]
MintRecipient& MintRecipient::SetCreateParams(CreateTokenParamsPtr createParams)
{
    return ParameterType::SetParameter("createParams", std::move(createParams));
}

[[maybe_unused]]
MintRecipient& MintRecipient::SetMintParams(MintTokenParamsPtr mintParams)
{
    return ParameterType::SetParameter("mintParams", std::move(mintParams));
}

MintRecipient& MintRecipient::operator=(const MintRecipient& rhs) = default;

MintRecipient& MintRecipient::operator=(MintRecipient&& rhs) noexcept = default;
