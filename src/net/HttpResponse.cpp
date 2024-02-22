//
// Created by VerOchka on 14.01.2024.
//

#include "HttpResponse.hpp"

namespace Net {
    void HttpResponse::read(asio::ip::tcp::socket& socket) {
        asio::streambuf response;
        asio::read_until(socket, response, "\r\n");

        std::istream responseStream(&response);

        responseStream >> _httpVersion;

        unsigned int statusCode;
        responseStream >> statusCode;
        _statusCode = castToStatusCode(statusCode);

        std::getline(responseStream, _statusMessage);

        if (!responseStream || _httpVersion.substr(0, 5) != "HTTP/") {
            Logger::error("Invalid response");
        }
        if (_statusCode != StatusCode::OK && _statusCode != StatusCode::CREATED) {
            Logger::error("Response returned with status code: {}", (int)_statusCode);
        }

        // Read the response headers, which are terminated by a blank line.
        asio::read_until(socket, response, "\r\n\r\n");
        // Process the response headers.
        std::string header;
        while (std::getline(responseStream, header) && header != "\r") {
            auto valuePos = header.find_first_of(':');
            auto endPos = header.find_first_of('\r');
            if (endPos != std::string::npos && valuePos != std::string::npos) {
                _headers[header.substr(0, valuePos)] = header.substr(valuePos + 2, endPos - valuePos - 2);
            }
            Logger::debug(header);
        }

        if (_headers.contains("Set-Cookie")) {
            _cookie = _headers["Set-Cookie"];
        }

        auto contentSize = std::stoi(_headers["Content-Length"]);
        if  (contentSize > 0) {
            char* content = new char[contentSize];

            responseStream.get(content, contentSize);
            std::string body{content};

            delete[] content;

            if (contentSize > body.size() + 1) {
                asio::error_code errorCode;

                asio::streambuf endBuf;
                asio::read(socket, endBuf, asio::transfer_at_least(1), errorCode);
                std::istream endStream(&endBuf);

                std::string end;
                std::getline(endStream, end);

                body += end;
            }
            Logger::debug(body);

            Json::Reader reader;
            bool parsingSuccessful = reader.parse(body, _body);
            if (!parsingSuccessful) {
                Logger::error("Failed to parse response content : {}", reader.getFormattedErrorMessages());
            }

            // удалить потом
            Json::ValueIterator it = _body.begin();
            while (it != _body.end()) {
                if (it->isString()) {
                    Logger::debug("{} : {}", it.key().asString(), it->asString());
                }
                ++it;
            }    // конец удаления

            if (_body.isObject()) {
                if (_body.isMember("error")) {
                    _errorMessage = _body["error"].asString();
                }
            }
        }
    }

    const std::string& HttpResponse::getHttpVersion() const {
        return _httpVersion;
    }

    const std::string& HttpResponse::getStatusMessage() const {
        return _statusMessage;
    }

    const std::string& HttpResponse::getCookie() const {
        return _cookie;
    }

    const std::string& HttpResponse::getErrorMessage() const {
        return _errorMessage;
    }

    const Json::Value& HttpResponse::getBody() const {
        return _body;
    }

    HttpResponse::StatusCode HttpResponse::getStatusCode() const {
        return _statusCode;
    }

    HttpResponse::StatusCode HttpResponse::castToStatusCode(unsigned int code) {
        switch (code) {
            case OK:
                return OK;
            case CREATED:
                return CREATED;
            case ACCEPTED:
                return ACCEPTED;
            case BAD_REQUEST:
                return BAD_REQUEST;
            case UNAUTHORIZED:
                return UNAUTHORIZED;
            case CLIENT_CLOSED_REQUEST:
                return CLIENT_CLOSED_REQUEST;
            case INTERNAL_SERVER_ERROR:
                return INTERNAL_SERVER_ERROR;
            case NOT_IMPLEMENTED:
                return NOT_IMPLEMENTED;
            case BAD_GATEWAY:
                return BAD_GATEWAY;
            case SERVICE_UNAVAILABLE:
                return SERVICE_UNAVAILABLE;
            default:
                return OTHER;
        };
    }
}    //namespace Net
