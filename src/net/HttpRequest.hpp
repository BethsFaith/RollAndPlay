//
// Created by VerOchka on 14.01.2024.
//

#ifndef ROLLANDPLAY_HTTPREQUEST_HPP
#define ROLLANDPLAY_HTTPREQUEST_HPP

#include <asio.hpp>
#include <json/json.h>

#include "HttpMethods.hpp"

namespace Net {
    class HttpRequest {
    public:
        HttpRequest(const std::string& target, const std::string& method, const std::string& host);

        void setCookie(const std::string& cookie);
        void setBodyJson(Json::Value& body);

        void write(asio::ip::tcp::socket& socket);

    private:
        std::string _host;
        std::string _cookie;
        std::string _body;

        std::vector<std::string> _headers;
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPREQUEST_HPP
