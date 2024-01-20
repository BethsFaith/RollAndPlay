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
        HttpResponse() = default;
        ~HttpResponse() = default;

        void read(asio::ip::tcp::socket& socket);

        [[nodiscard]] const std::string& getHttpVersion() const;
        [[nodiscard]] const std::string& getStatusMessage() const;
        [[nodiscard]] const std::string& getCookie() const;
        [[nodiscard]] const std::string& getErrorMessage() const;
        [[nodiscard]] const Json::Value& getBody() const;
        [[nodiscard]] unsigned int getStatusCode() const;

    private:
        std::string _httpVersion;
        std::string _statusMessage;
        std::string _cookie;
        std::string _errorMessage;
        Json::Value _body;

        unsigned int _statusCode{};
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPRESPONSE_HPP
