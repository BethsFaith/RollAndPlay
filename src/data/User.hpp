//
// Created by VerOchka on 11.01.2024.
//

#ifndef ROLLANDPLAY_USER_HPP
#define ROLLANDPLAY_USER_HPP

#include "IBitwiseSerializable.hpp"
#include "IJsonSerializable.hpp"

namespace Data {
    class User : public IBitwiseSerializable, IJsonSerializable {
    public:
        User() = default;
        ~User() override = default;

        size_t serialize(Storage::StreamWriter &writer) const override;

        size_t deserialize(Storage::StreamReader &reader) override;

        void serialize(Json::Value &jsonValue) override;

        void deserialize(const Json::Value &jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        unsigned int getIndex() override;

        static bool validateEmail(const std::u16string& email);

        static bool validateName(const std::u16string& name);

        static bool validatePassword(const std::u16string& password);

        void setEmail(const std::u16string &email);

        void setPassword(const std::u16string &password);

    private:
        std::u16string _email;
        std::u16string _password;
        std::u16string _nickname;
    };
}

#endif //ROLLANDPLAY_USER_HPP
