//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_HTTPSESSION_HPP
#define ROLLANDPLAY_HTTPSESSION_HPP

#include "ApiClient.hpp"
#include "Route.hpp"
#include "../data/User.hpp"
#include "../data/DataFactory.hpp"

namespace Net {
    class HttpSession {
    public:
        struct Result {
            std::string statusMessage;
            std::string errorMessage;

            bool haveError = false;

            std::vector<Data::AData::Ptr> data;
        };

        using Ptr = std::shared_ptr<HttpSession>;

        HttpSession(std::string host, std::string service, std::string domain, Route* route);

        Result createUser(Data::User& user);
        Result getCurrentUser();
        Result logIn(Data::User& user);
        Result updateUserData(Data::User& user);

        Result create(const Data::AData::Ptr& data);
        Result getList(Data::Type type);

    private:
        ApiClient _client;
        Route& _route;

        std::string _domain;
        std::string _cookie;
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPSESSION_HPP
