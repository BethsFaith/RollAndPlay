//
// Created by VerOchka on 11.01.2024.
//

#ifndef ROLLANDPLAY_USER_HPP
#define ROLLANDPLAY_USER_HPP

#include "AData.hpp"
#include "IBitwiseSerializable.hpp"
#include "IJsonSerializable.hpp"

namespace Data {
    class User : public AData {
    public:
        using Ptr = std::shared_ptr<User>;

        User() = default;
        ~User() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        void setId(unsigned int index) override;

        int getId() override;

        static bool validateEmail(const std::u16string& email);
        static bool validateName(const std::u16string& name);
        static bool validatePassword(const std::u16string& password);

        void setEmail(const std::u16string& email);
        void setPassword(const std::u16string& password);
        void setNickname(const std::u16string& nickname);

        Type getType() override;

        [[nodiscard]] const std::u16string& getEmail() const;
        [[nodiscard]] const std::u16string& getPassword() const;
        [[nodiscard]] const std::u16string& getNickname() const;

    private:
        std::u16string _email;
        std::u16string _password;
        std::u16string _nickname;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_USER_HPP
