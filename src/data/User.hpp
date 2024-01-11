//
// Created by VerOchka on 11.01.2024.
//

#ifndef ROLLANDPLAY_USER_HPP
#define ROLLANDPLAY_USER_HPP

#include "IBitwiseSerializable.hpp"

namespace Data {
    class User : public IBitwiseSerializable {
    public:
        User() = default;
        ~User() override = default;

        size_t serialize(Storage::StreamWriter &writer) const override;

        size_t deserialize(Storage::StreamReader &reader) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        unsigned int getIndex() override;

        static bool validateName(const std::u16string& name);

        static bool validatePassword(const std::u16string& password);

        void setName(const std::u16string &name);

        void setPassword(const std::u16string &password);

    private:
        std::u16string _name;
        std::u16string _password;
    };
}

#endif //ROLLANDPLAY_USER_HPP
