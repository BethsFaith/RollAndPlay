//
// Created by VerOchka on 20.01.2024.
//

#ifndef ROLLANDPLAY_HTTPSESSION_HPP
#define ROLLANDPLAY_HTTPSESSION_HPP

#include "../data/DataFactory.hpp"
#include "../data/User.hpp"
#include "HttpSession.hpp"
#include "Route.hpp"

namespace Net {
    class ApiClient {
    public:
        struct Result {
            std::string statusMessage;
            std::string errorMessage;

            bool haveError = false;

            std::vector<Data::AData::Ptr> data;
        };

        using Ptr = std::shared_ptr<ApiClient>;

        ApiClient(std::string host, std::string service, std::string domain, Route* route);

        Result createUser(Data::User& user);
        Result getUser(unsigned int id);
        Result getCurrentUser();
        Result logIn(Data::User& user);
        Result updateUserData(Data::User& user);

        Result create(const Data::AData::Ptr& data);
        Result getList(Data::Type type);
        Result getListByRef(Data::Type type, const std::string& referenceParameterName, int referenceParameter);
        Result get(Data::Type type, int id);
        Result update(const Data::AData::Ptr& data);
        Result deleteById(Data::Type type, int id);

    private:
        HttpSession _session;
        Route& _route;

        std::string _domain;
        std::string _cookie;
    };
}    //namespace Net

#endif    //ROLLANDPLAY_HTTPSESSION_HPP
