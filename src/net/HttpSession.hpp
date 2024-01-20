//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_HTTPSESSION_HPP
#define ROLLANDPLAY_HTTPSESSION_HPP

#include "ApiClient.hpp"
#include "../data/User.hpp"

namespace Net {
    class HttpSession {
    public:
        struct Result {
            std::string statusMessage;
            std::string errorMessage;

            bool haveError = false;
            bool containData = false;

            Data::AData::Ptr data;
        };

        using Ptr = std::shared_ptr<HttpSession>;

        HttpSession(std::string host, std::string service, std::string domain);

        Result createUser(Data::User& user);
        Result getCurrentUser();
        Result logIn(Data::User& user);
    private:
        ApiClient _client;

        std::string _domain;
        std::string _cookie;
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPSESSION_HPP
