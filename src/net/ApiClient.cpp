//
// Created by VerOchka on 13.01.2024.
//

#include "ApiClient.hpp"

#include <utility>

namespace Net {
    ApiClient::ApiClient(std::string host, std::string service) : _host(std::move(host)), _service(std::move(service)){}

    HttpResponse ApiClient::connect(HttpRequest& request) {
        using asio::ip::tcp;

        tcp::resolver resolver(_ioContext);
        tcp::resolver::query query(_host, _service);
        tcp::resolver::results_type endpoints = resolver.resolve(query);

        tcp::socket socket(_ioContext);
        asio::error_code errorCode;
        asio::connect(socket, endpoints, errorCode);

        if (errorCode) {
            std::cout << errorCode.message() << std::endl;
            return {};
        }
        request.write(socket);

        HttpResponse response;
        response.read(socket);

        return response;
    }
}

//        Json::Value body;
//        body["email"] = "user@example20.org";
//        body["password"] = "pass10202";
//        Json::StyledWriter styledWriter;
//        std::string json = styledWriter.write(body);
//        std::cout << json << std::endl;

//        asio::streambuf request;
//        std::ostream request_stream(&request);
//        request_stream << "POST " << "private/users" << " HTTP/1.1\r\n";
//        request_stream << "Accept: */*\r\n";
//        request_stream << "Connection: close\r\n";
//        request_stream << "Content-Length: " << json.length() << "\r\n";
//        request_stream << "Content-Type: application/json \r\n";
//        request_stream << "Host: " << "localhost:8080" << "\r\n\r\n";
//        request_stream << json << "\r\n\r\n";

//        Json::Value body;
//        body["name"] = "name";
//        body["model"] = "model.path";
//        Json::StyledWriter styledWriter;
//        std::string json = styledWriter.write(body);
//        std::cout << json << std::endl;

//        asio::streambuf request;
//        std::ostream request_stream(&request);
//        request_stream << "POST " << "/private/races" << " HTTP/1.1\r\n";
//        request_stream << "Accept: */*\r\n";
//        request_stream << "Connection: close\r\n";
//        request_stream << "Content-Length: " << json.length() << "\r\n";
//        request_stream << "Content-Type: application/json \r\n";
//        request_stream << "Host: " << "localhost:8080" << "\r\n";
//        request_stream << "Cookie: " << "rnpsession=MTcwNTE4MzU2NHxEdi1CQkFFQ180SUFBUkFCRUFBQUh2LUNBQUVHYzNSeWFXNW5EQWtBQjNWelpYSmZhV1FEYVc1MEJBSUFGQT09fPSdyqeCKEplVqlnDf4h4DiboVdaWD_wI_XZcNQOBeBM" << "\r\n";
//        request_stream << "\r\n";
//        request_stream << json << "\r\n";
//        request_stream << "\r\n";
//
//        asio::write(socket, request);
//        asio::streambuf response;
//        asio::read_until(socket, response, "\r\n");
//
//        std::istream response_stream(&response);
//        std::string http_version;
//        std::string status_message;
//        unsigned int status_code;
//
//        response_stream >> http_version;
//        response_stream >> status_code;
//        std::getline(response_stream, status_message);
//
//        if (!response_stream || http_version.substr(0, 5) != "HTTP/")
//        {
//            std::cout << "Invalid response\n";
//        }
//        if (status_code != 200)
//        {
//            std::cout << "Response returned with status code " << status_code << "\n";
//        }
//
//        // Read the response headers, which are terminated by a blank line.
//        asio::read_until(socket, response, "\r\n\r\n");
//        // Process the response headers.
//        std::string header;
//        std::string request_id;
//        while (std::getline(response_stream, header) && header != "\r") {
//            if (header.find("Set-Cookie") != std::string::npos) {
//                auto endPos = header.find_first_of(';');
//                if (endPos != std::string::npos) {
//                    request_id = header.substr(12, endPos-12);
//                }
//            }
//            std::cout << header << "\n";
//        }
//        std::cout << "\n";
//
//        // Write whatever content we already have to output.
//        if (response.size() > 0)
//            std::cout << &response;
//
//        if (!request_id.empty()) {
//            std::cout << "Cookies: " << request_id << std::endl;
//        }
//
//        asio::error_code error;
//        // Read until EOF, writing data to output as we go.
//        while (asio::read(socket, response,
//                                 asio::transfer_at_least(1), error))
//            std::cout << &response;
//        if (error != asio::error::eof)
//            std::cout << "SERVER ERROR: " << error << std::endl;