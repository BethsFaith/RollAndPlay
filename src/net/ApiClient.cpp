//
// Created by VerOchka on 13.01.2024.
//

#include "ApiClient.hpp"

#include <utility>

namespace Net {
    ApiClient::ApiClient(ApiClient& other) : _resolver(_ioContext) {
        _host = other._host;
        _service = other._service;
    }

    ApiClient::ApiClient(std::string host, std::string service)
        : _host(std::move(host)),
          _service(std::move(service)), _resolver(_ioContext)  {}

    void ApiClient::connect() {
        using asio::ip::tcp;

        tcp::resolver::query query(_host, _service);
        tcp::resolver::results_type endpoints = _resolver.resolve(query);

        _socket = std::make_unique<tcp::socket>(_ioContext);
        asio::error_code errorCode;
        asio::connect(*_socket, endpoints, errorCode);

        if (errorCode) {
            Logger::error("Error {1} when connect: {0}", errorCode.message(), (int)errorCode.value());
        }
    }

    HttpResponse ApiClient::send(HttpRequest& request) {
        auto code = request.write(*_socket);
        if (code == asio::error::connection_aborted) {
            connect();
            code = request.write(*_socket);
        }

        HttpResponse response;
        try {
            response.read(*_socket);
        }
        catch (std::exception &e) {
            Logger::error("Error when request: {0}", e.what());
            connect();
            return send(request);
        }

        return response;
    }
}    //namespace Net
