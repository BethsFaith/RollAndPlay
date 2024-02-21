//
// Created by VerOchka on 14.01.2024.
//

#ifndef ROLLANDPLAY_HTTPRESPONSE_HPP
#define ROLLANDPLAY_HTTPRESPONSE_HPP

#include <asio.hpp>
#include <iostream>
#include <json/json.h>
#include <json/reader.h>

namespace Net {
    class HttpResponse {
    public:
        enum StatusCode {
            OK = 200,
            CREATED = 201,
            ACCEPTED = 202,
            BAD_REQUEST = 400,
            UNAUTHORIZED = 401,
            CLIENT_CLOSED_REQUEST = 499,
            INTERNAL_SERVER_ERROR = 500,
            NOT_IMPLEMENTED = 501,
            BAD_GATEWAY = 502,
            SERVICE_UNAVAILABLE = 503,
            OTHER,
        };

        HttpResponse() = default;
        ~HttpResponse() = default;

        void read(asio::ip::tcp::socket& socket);

        [[nodiscard]] const std::string& getHttpVersion() const;
        [[nodiscard]] const std::string& getStatusMessage() const;
        [[nodiscard]] const std::string& getCookie() const;
        [[nodiscard]] const std::string& getErrorMessage() const;
        [[nodiscard]] const Json::Value& getBody() const;
        [[nodiscard]] StatusCode getStatusCode() const;

    private:
        static StatusCode castToStatusCode(unsigned int code);

        std::string _httpVersion;
        std::string _statusMessage;
        std::string _cookie;
        std::string _errorMessage;

        std::map<std::string, std::string> _headers;

        Json::Value _body;

        StatusCode _statusCode{};
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPRESPONSE_HPP
