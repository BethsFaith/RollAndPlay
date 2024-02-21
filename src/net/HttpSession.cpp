//
// Created by VerOchka on 20.01.2024.
//

#include "HttpSession.hpp"

#include <utility>

namespace Net {
    HttpSession::HttpSession(std::string host, std::string service, std::string domain, Route* route)
        : _client(std::move(host), std::move(service)),
          _domain(std::move(domain)),
          _route(*route) {
        _client.connect();
    }

    HttpSession::Result HttpSession::createUser(Data::User& user) {
        Json::Value body;
        user.serialize(body);
        Net::HttpRequest request("/users", Net::Http::MethodPost, _domain);
        request.setBodyJson(body);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::CREATED) {
            Data::User::Ptr createdUser = std::make_shared<Data::User>();
            createdUser->deserialize(response.getBody());

            result.data.push_back(createdUser);
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

        auto response = _client.send(request);

        _cookie = response.getCookie();

        Result result;

        if (response.getStatusCode() != HttpResponse::StatusCode::OK) {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::getUser(unsigned int id) {
        Net::HttpRequest request("/view-user", Net::Http::MethodGet, _domain);
        request.setCookie(_cookie);

        Json::Value body;
        body["id"] = id;
        request.setBodyJson(body);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            Data::User::Ptr user = std::make_shared<Data::User>();
            user->deserialize(response.getBody());

            result.data.push_back(user);
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::getCurrentUser() {
        Net::HttpRequest request("/private/who-am-i", Net::Http::MethodGet, _domain);
        request.setCookie(_cookie);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            Data::User::Ptr user = std::make_shared<Data::User>();
            user->deserialize(response.getBody());

            result.data.push_back(user);
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

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() != HttpResponse::StatusCode::OK) {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::create(const Data::AData::Ptr& data) {
        auto type = data->getType();
        if (type == Data::USER) {
            return createUser(*std::dynamic_pointer_cast<Data::User>(data));
        }

        auto paths = _route.getPaths();
        auto target = std::string(paths[type][Net::Http::MethodPost]);
        Net::HttpRequest request(target,Net::Http::MethodPost, _domain);

        Json::Value body;
        auto jsonData = std::dynamic_pointer_cast<Data::IJsonSerializable>(data);
        jsonData->serialize(body);
        request.setBodyJson(body);

        request.setCookie(_cookie);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::CREATED) {
            auto createdData = Data::DataFactory::create(type);
            auto createdJsonData =  std::dynamic_pointer_cast<Data::IJsonSerializable>(createdData);

            createdJsonData->deserialize(response.getBody());

            result.data.push_back(createdData);
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::getList(Data::Type type) {
        auto paths = _route.getPaths();
        auto target = std::string(paths[type][Net::Http::MethodGet]);
        Net::HttpRequest request(target,Net::Http::MethodGet, _domain);

        request.setCookie(_cookie);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            auto body = response.getBody();
            if (body.isArray()) {
                for (int i{}; i < body.size(); ++i) {
                    auto createdData = Data::DataFactory::create(type);
                    auto createdJsonData =  std::dynamic_pointer_cast<Data::IJsonSerializable>(createdData);

                    createdJsonData->deserialize(body[i]);

                    result.data.push_back(createdData);
                }
            }
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }

    HttpSession::Result HttpSession::get(Data::Type type, int id) {
        if (type == Data::USER) {
            return getUser(id);
        }

        auto paths = _route.getPaths();
        auto target = std::string(paths[type][Net::Http::MethodGet]);
        Net::HttpRequest request(target,Net::Http::MethodPut, _domain);

        Json::Value body;
        body["id"] = id;

        request.setCookie(_cookie);

        auto response = _client.send(request);

        Result result;
        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            auto createdData = Data::DataFactory::create(type);
            auto createdJsonData =  std::dynamic_pointer_cast<Data::IJsonSerializable>(createdData);

            createdJsonData->deserialize(response.getBody());

            result.data.push_back(createdData);
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        return result;
    }

    HttpSession::Result HttpSession::update(const Data::AData::Ptr& data) {
        auto type = data->getType();
        if (type == Data::USER) {
            return updateUserData(*std::dynamic_pointer_cast<Data::User>(data));
        }

        auto paths = _route.getPaths();
        auto target = std::string(paths[type][Net::Http::MethodPut]);
        Net::HttpRequest request(target,Net::Http::MethodPut, _domain);

        Json::Value body;
        auto jsonData = std::dynamic_pointer_cast<Data::IJsonSerializable>(data);
        jsonData->serialize(body);
        request.setBodyJson(body);

        request.setCookie(_cookie);

        auto response = _client.send(request);

        Result result;

        if (response.getStatusCode() == HttpResponse::StatusCode::OK) {
            auto updatedData = Data::DataFactory::create(type);
            auto updatedJsonData =  std::dynamic_pointer_cast<Data::IJsonSerializable>(updatedData);

            updatedJsonData->deserialize(response.getBody());

            result.data.push_back(updatedData);
        } else {
            result.haveError = true;
            result.errorMessage = response.getErrorMessage();
        }

        result.statusMessage = response.getStatusMessage();

        return result;
    }
}    //namespace Net
