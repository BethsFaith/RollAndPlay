//
// Created by VerOchka on 13.01.2024.
//

#ifndef ROLLANDPLAY_APICLIENT_HPP
#define ROLLANDPLAY_APICLIENT_HPP

#include <asio.hpp>
#include <iostream>
#include <json/json.h>

#include "HttpRequest.hpp"
#include "HttpResponse.hpp"
#include "../logger/Logger.hpp"

namespace Net {
    class HttpSession {
    public:
        using Ptr = std::shared_ptr<HttpSession>;

        HttpSession() = default;
        HttpSession(HttpSession& other);
        HttpSession(std::string host, std::string service);
        ~HttpSession() = default;

        void connect();
        HttpResponse send(HttpRequest& request);

    private:
        std::string _host;
        std::string _service;

        asio::io_context _ioContext{};
        asio::ip::tcp::resolver _resolver;
        std::unique_ptr<asio::ip::tcp::socket> _socket;
    };
}    //namespace Net

#endif    //ROLLANDPLAY_APICLIENT_HPP
