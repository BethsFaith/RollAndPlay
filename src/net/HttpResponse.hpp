//
// Created by VerOchka on 14.01.2024.
//

#ifndef ROLLANDPLAY_HTTPRESPONSE_HPP
#define ROLLANDPLAY_HTTPRESPONSE_HPP

#include <iostream>
#include <asio.hpp>

namespace Net {
    class HttpResponse {
    public:
        HttpResponse() = default;
        ~HttpResponse() = default;

        void read(asio::ip::tcp::socket& socket);
    private:
        std::string _httpVersion;
        std::string _statusMessage;
        std::string _cookie;

        unsigned int _statusCode;
    };
}


#endif //ROLLANDPLAY_HTTPRESPONSE_HPP
