#ifndef ENJINPLATFORMSDK_PLATFORMREQUEST_HPP
#define ENJINPLATFORMSDK_PLATFORMREQUEST_HPP

#include "enjinplatformsdk_export.h"
#include "EnjinPlatformSdk/IGraphQlRequest.hpp"
#include "EnjinPlatformSdk/IPlatformRequest.hpp"
#include "EnjinPlatformSdk/MultipartFormData.hpp"
#include "EnjinPlatformSdk/Upload.hpp"
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace enjin::platform::sdk
{
/// \brief Contains HTTP data for sending a request to the platform.
class ENJINPLATFORMSDK_EXPORT PlatformRequest final : public IPlatformRequest
{
    std::string _contentType;
    std::map<std::string, std::string> _headers;
    std::string _path;
    std::map<std::string, Upload&> _uploadVariables;

    // Optional fields
    std::optional<std::string> _body;
    std::optional<std::vector<MultipartFormData>> _forms;

    static constexpr char FormData[] = "multipart/form-data";
    static constexpr char Json[] = "application/json";
    static constexpr char Text[] = "text/plain";
    static constexpr char VariablesKey[] = "variables";

    struct Operation;

public:
    class PlatformRequestBuilder;

    PlatformRequest() = delete;

    /// \brief Copy constructor.
    /// \param other The other instance to copy from.
    [[maybe_unused]]
    PlatformRequest(const PlatformRequest& other);

    /// \brief Move constructor.
    /// \param other The other instance to move.
    [[maybe_unused]]
    PlatformRequest(PlatformRequest&& other) noexcept;

    /// \brief Class destructor.
    ~PlatformRequest() override;

    PlatformRequest& operator=(const PlatformRequest& rhs);

    PlatformRequest& operator=(PlatformRequest&&) noexcept;

    /// \brief Creates a builder instance for this class.
    /// \return The builder instance.
    [[maybe_unused]]
    [[nodiscard]]
    static PlatformRequestBuilder Builder();

    // region IPlatformRequest

    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::string>& GetBody() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetContentType() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::map<std::string, std::string>& GetHeaders() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::optional<std::vector<MultipartFormData>>& GetMultipartFormData() const override;

    [[maybe_unused]]
    [[nodiscard]]
    const std::string& GetPath() const override;

    // endregion IPlatformRequest

    /// \brief The builder class for defining and creating a new instance of the PlatformRequest class.
    class ENJINPLATFORMSDK_EXPORT PlatformRequestBuilder final
    {
        std::map<std::string, std::string> _headers;
        std::vector<Operation> _operations;
        std::optional<std::string> _path;

    public:
        /// \brief Class destructor.
        ~PlatformRequestBuilder();

        /// \brief Adds a header for the request.
        /// \param key The header key.
        /// \param value The header value.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformRequestBuilder& AddHeader(std::string key, std::string value);

        /// \brief Adds an operation for the request.
        /// \param query The query of the operation.
        /// \param variables The variables of the operation.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformRequestBuilder& AddOperation(std::string query,
                                             std::map<std::string, SerializablePtr> variables);

        /// \brief Adds an operation for the request with the given file uploads.
        /// \param query The query of the operation.
        /// \param variables The variables of the operation.
        /// \param uploads The file uploads.
        /// \return This builder for chaining.
        [[maybe_unused]]
        PlatformRequestBuilder& AddOperation(std::string query,
                                             std::map<std::string, SerializablePtr> variables,
                                             std::map<std::string, Upload&> uploads);

        /// \brief Build an instance of a platform request wrapped in a pointer using the set values.
        /// \return The pointer for the request.
        /// \throws std::logic_error Thrown if no operations have been added at the time this member-function is called.
        [[maybe_unused]]
        [[nodiscard]]
        PlatformRequestPtr Build() const;

        /// \brief Sets the relative path of the URI to be used for the request.
        /// \param path The The relative path.
        /// \return This builder for chaining.
        /// \remarks Defaults to an empty string if not set.
        [[maybe_unused]]
        PlatformRequestBuilder& SetPath(std::string path);

    private:
        /// \brief Constructs an instance of this class.
        PlatformRequestBuilder();

        friend PlatformRequestBuilder PlatformRequest::Builder();
    };

private:
    /// \brief Constructs an instance of this class.
    /// \param operations The operations of the request.
    explicit PlatformRequest(const std::vector<Operation>& operations);

    /// \brief Creates the operation content for this request and compiles any upload variables.
    /// \param operations The operations of this request.
    /// \return The content body.
    [[nodiscard]]
    std::string CreateOperationContent(const std::vector<Operation>& operations);

    /// \brief Initializes this request.
    /// \param operations The operations of this request.
    void Init(const std::vector<Operation>& operations);

    /// \brief Initializes this request for multipart form-data.
    /// \param operations The operations of this request.
    void InitForMultipartFormData(const std::vector<Operation>& operations);

    /// \brief Initializes this request for single content data.
    /// \param operations The operations of this request.
    void InitForSingleContent(const std::vector<Operation>& operations);

    /// \brief Struct representing an operation for a request.
    struct Operation
    {
        std::string query;
        std::map<std::string, SerializablePtr> variables;
        std::map<std::string, Upload&> uploads;
    };
};
}

#endif //ENJINPLATFORMSDK_PLATFORMREQUEST_HPP
