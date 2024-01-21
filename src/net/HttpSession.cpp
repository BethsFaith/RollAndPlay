//
// Created by VerOchka on 20.01.2024.
//

#include "HttpSession.hpp"

#include <utility>

namespace Net {
    HttpSession::HttpSession(std::string host, std::string service, std::string domain)
        : _client(std::move(host), std::move(service)), _domain(std::move(domain)) {}

    HttpSession::Result HttpSession::createUser(Data::User& user) {
        Json::Value body;
        user.serialize(body);
        Net::HttpRequest request("/users", Net::Http::MethodPost, _domain);
        request.setBodyJson(body);

        auto response = _client.connect(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::CREATED) {
            Data::User::Ptr createdUser = std::make_shared<Data::User>();
            createdUser->deserialize(response.getBody());

            result.containData = true;
            result.data = createdUser;
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::logIn(Data::User& user) {
        Json::Value body;
        user.serialize(body);
        Net::HttpRequest request("/sessions", Net::Http::MethodPost, _domain);
        request.setBodyJson(body);

        auto response = _client.connect(request);

        _cookie = response.getCookie();

        Result result;

        if (response.getStatusCode() != HttpResponse::StatusCode::OK) {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::getCurrentUser() {
        Net::HttpRequest request("/private/who-am-i", Net::Http::MethodGet, _domain);
        request.setCookie(_cookie);

        auto response = _client.connect(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            Data::User::Ptr user = std::make_shared<Data::User>();
            user->deserialize(response.getBody());

            result.containData = true;
            result.data = user;
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::updateUserData(Data::User& user) {
        Net::HttpRequest request("/private/users", Net::Http::MethodPut, _domain);
        request.setCookie(_cookie);

        Json::Value body;
        user.serialize(body);
        request.setBodyJson(body);

        auto response = _client.connect(request);

        Result result;

        if (response.getStatusCode() != HttpResponse::StatusCode::OK) {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }
}
