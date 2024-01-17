//
// Created by VerOchka on 14.01.2024.
//

#include "HttpRequest.hpp"

#include <utility>

namespace Net {
    HttpRequest::HttpRequest(const std::string &target, const std::string &method, const std::string &host) {
        _headers.push_back(method + " " + target + " HTTP/1.1");
        _headers.emplace_back("Accept: */*");
        _headers.emplace_back("Connection: close");

        _host = host;
    }

    void HttpRequest::setCookie(const std::string &cookie) {
        _cookie = cookie;
    }

    void HttpRequest::setBodyJson(Json::Value& body) {
        Json::StyledWriter styledWriter;
        _body = styledWriter.write(body);

        _headers.emplace_back("Content-Length: " + std::to_string(_body.length()));
        _headers.emplace_back("Content-Type: application/json");
    }

    void HttpRequest::write(asio::ip::tcp::socket &socket) {
        asio::streambuf request;
        std::ostream request_stream(&request);

        for (const auto& header : _headers) {
            request_stream << header << "\r\n";
        }

        request_stream << "Host: " << _host << "\r\n";

        if (!_cookie.empty()) {
            request_stream << "Cookie: " << _host << "\r\n";
        }

        request_stream << "\r\n";

        if (!_body.empty()){
            request_stream << _body << "\r\n";
            request_stream << "\r\n";
        }

        asio::write(socket, request);
    }
}