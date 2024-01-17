//
// Created by VerOchka on 14.01.2024.
//

#include "HttpResponse.hpp"

namespace Net {
    void HttpResponse::read(asio::ip::tcp::socket &socket) {
        asio::streambuf response;
        asio::read_until(socket, response, "\r\n");

        std::istream responseStream(&response);

        responseStream >> _httpVersion;
        responseStream >> _statusCode;
        std::getline(responseStream, _statusMessage);

        if (!responseStream || _httpVersion.substr(0, 5) != "HTTP/")
        {
            std::cout << "Invalid response\n";
        }
        if (_statusCode != 200)
        {
            std::cout << "Response returned with status code " << _statusCode << "\n";
        }

        // Read the response headers, which are terminated by a blank line.
        asio::read_until(socket, response, "\r\n\r\n");
        // Process the response headers.
        std::string header;
        while (std::getline(responseStream, header) && header != "\r") {
            if (header.find("Set-Cookie") != std::string::npos) {
                auto endPos = header.find_first_of(';');
                if (endPos != std::string::npos) {
                    _cookie = header.substr(12, endPos-12);
                }
            }
            std::cout << header << "\n";
        }
        std::cout << "\n";

        std::string bodyLine;
        std::getline(responseStream, bodyLine);
        Json::Reader reader;
        bool parsingSuccessful = reader.parse(bodyLine.c_str(), _body);     //parse process
        if ( !parsingSuccessful )
        {
            std::cout  << "Failed to parse"
                       << reader.getFormattedErrorMessages();
        }

        // удалить потом
        Json::ValueIterator it = _body.begin();
        while (it != _body.end()) {
            std::cout <<  it.key() << ":" << it->asString() << std::endl;
            ++it;
        } // конец удаления

        if (_body.isMember("error")) {
            _errorMessage = _body["error"].asString();
        }

        // Write whatever content we already have to output.
        if (response.size() > 0)
            std::cout << &response;

        if (!_cookie.empty()) {
            std::cout << "Cookies: " << _cookie << std::endl;
        }

        asio::error_code error;
        // Read until EOF, writing data to output as we go.
        while (asio::read(socket, response,
                          asio::transfer_at_least(1), error)) {
            std::cout << &response;
        }
        if (error != asio::error::eof)
            std::cout << "SERVER ERROR: " << error << std::endl;
    }

    const std::string &HttpResponse::getHttpVersion() const {
        return _httpVersion;
    }

    const std::string &HttpResponse::getStatusMessage() const {
        return _statusMessage;
    }

    const std::string &HttpResponse::getCookie() const {
        return _cookie;
    }

    const std::string &HttpResponse::getErrorMessage() const {
        return _errorMessage;
    }

    const Json::Value &HttpResponse::getBody() const {
        return _body;
    }

    unsigned int HttpResponse::getStatusCode() const {
        return _statusCode;
    }
}