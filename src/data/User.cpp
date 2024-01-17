//
// Created by VerOchka on 11.01.2024.
//

#include "User.hpp"

namespace Data {
    bool User::validateName(const std::u16string &name) {
        return false;
    }

    bool User::validatePassword(const std::u16string &password) {
        return false;
    }

    size_t User::serialize(Storage::StreamWriter &writer) const {
        return 0;
    }

    size_t User::deserialize(Storage::StreamReader &reader) {
        return 0;
    }

    void User::serialize(Json::Value &jsonValue) {
        jsonValue["email"] = std::string(_email.begin(), _email.end());
        jsonValue["password"] = std::string(_password.begin(), _password.end());
        if (!_nickname.empty()) {
            jsonValue["nickname"] = std::string(_nickname.begin(), _nickname.end());
        }
    }

    void User::deserialize(Json::Value &jsonValue) {
        auto email = jsonValue["email"].asString();
        auto nickname = jsonValue["nickname"].asString();
        auto password = jsonValue["password"].asString();

        _email = std::u16string(email.begin(), email.end());
        _nickname = std::u16string(nickname.begin(), nickname.end());
        _password = std::u16string(password.begin(), password.end());
    }

    size_t User::serialized_size() const noexcept {
        return 0;
    }

    unsigned int User::getIndex() {
        return 0;
    }

    void User::setEmail(const std::u16string &email) {
        _email = email;
    }

    void User::setPassword(const std::u16string &password) {
        _password = password;
    }
}