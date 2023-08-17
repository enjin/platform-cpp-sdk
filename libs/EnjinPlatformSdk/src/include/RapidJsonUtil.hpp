#ifndef ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
#define ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP

#include "enjinplatformsdk_export.h"
#include "rapidjson/document.h"
#include <string>

namespace enjin::platform::sdk
{
/// \brief Utility class for RapidJSON functions.
class ENJINPLATFORMSDK_EXPORT RapidJsonUtil final
{
public:
    RapidJsonUtil() = delete;

    /// \brief Converts the content of the given document into a string.
    /// \param document The document.
    /// \return The stringified contents of the document.
    [[maybe_unused]]
    [[nodiscard]]
    static std::string DocumentToString(const rapidjson::Document& document);

    /// \brief Sets the given document as the value of a member on another document.
    /// \param document The document to set the member on.
    /// \param key The member key.
    /// \param value The document being set as the member value.
    [[maybe_unused]]
    static void SetDocumentMember(rapidjson::Document& document,
                                  const std::string& key,
                                  const rapidjson::Document& value);

    /// \brief Sets the given string as a member of a document.
    /// \param document The document to set the member on.
    /// \param key The member key.
    /// \param value The member value.
    [[maybe_unused]]
    static void SetStringMember(rapidjson::Document& document, const std::string& key, const std::string& value);

    /// \brief Parses the given JSON string into a document.
    /// \param json The JSON string.
    /// \return The document.
    [[maybe_unused]]
    [[nodiscard]]
    static rapidjson::Document StringToDocument(const std::string& json);

private:
    /// \brief Removes the member from the document if it is present.
    /// \param document The document.
    /// \param kStr The member key.
    static void RemoveMemberIfPresent(rapidjson::Document& document, const char* kStr);

    /// \brief Checks if the given document and key are valid for setting object member.
    /// \param document The document.
    /// \param key The member key.
    /// \throws std::invalid_argument Thrown if the document is not an object or if the key is an empty string.
    static void SetMemberAssert(rapidjson::Document& document, const std::string& key);
};
}

#endif //ENJINPLATFORMSDK_RAPIDJSONUTIL_HPP
