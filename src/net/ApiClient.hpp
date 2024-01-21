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

namespace Net {
    class ApiClient {
    public:
        using Ptr = std::shared_ptr<ApiClient>;

        ApiClient() = default;
        ApiClient(ApiClient& other);
        ApiClient(std::string host, std::string service);
        ~ApiClient() = default;

        HttpResponse connect(HttpRequest& request);

    private:
        std::string _host;
        std::string _service;

        asio::io_context _ioContext{};
    };
}    //namespace Net

#endif    //ROLLANDPLAY_APICLIENT_HPP
