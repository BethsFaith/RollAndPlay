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

    size_t User::serialized_size() const noexcept {
        return 0;
    }

    unsigned int User::getIndex() {
        return 0;
    }

    void User::setName(const std::u16string &name) {
        _name = name;
    }

    void User::setPassword(const std::u16string &password) {
        _password = password;
    }
}