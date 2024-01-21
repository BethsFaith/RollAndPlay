//
// Created by VerOchka on 13.01.2024.
//

#include "ApiClient.hpp"

#include <utility>

namespace Net {
    ApiClient::ApiClient(ApiClient& other) {
        _host = other._host;
        _service = other._service;
    }

    ApiClient::ApiClient(std::string host, std::string service)
        : _host(std::move(host)),
          _service(std::move(service)) {}

    HttpResponse ApiClient::connect(HttpRequest& request) {
        using asio::ip::tcp;

        tcp::resolver resolver(_ioContext);
        tcp::resolver::query query(_host, _service);
        tcp::resolver::results_type endpoints = resolver.resolve(query);

        tcp::socket socket(_ioContext);
        asio::error_code errorCode;
        asio::connect(socket, endpoints, errorCode);

        if (errorCode) {
            std::cout << errorCode.message() << errorCode << std::endl;
            return {};
        }
        request.write(socket);

        HttpResponse response;
        response.read(socket);

        return response;
    }
}    //namespace Net
