//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_SKILL_HPP
#define ROLLANDPLAY_SKILL_HPP

#include <iostream>
#include <utility>

#include "BaseData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class Skill : public BaseData {
    public:
        using Ptr = std::shared_ptr<Skill>;

        Skill() = default;
        ~Skill() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        Type getType() override;

        void setName(const std::u16string& name);
        void setName(const std::string& name);
        void setIconPath(const std::string& iconPath);
        void setCategoryId(const uint8_t& index);
        void setCharacteristicId(const uint8_t& index);
        void setUserId(unsigned int userId);
        void setUserName(const std::u16string& userName);

        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] int getCategoryId() const;
        [[nodiscard]] int getCharacteristicId() const;
        [[nodiscard]] const unsigned int& getUserId() const;
        [[nodiscard]] const std::u16string& getUserName() const;
    private:
        std::u16string _name;
        std::string _iconPath;
        unsigned int _categoryId = NULL_ID;
        unsigned int _characteristicId = NULL_ID;
        unsigned int _userId;
        std::u16string _userName;
    };
}    //namespace Data

#endif    //ROLLANDPLAY_SKILL_HPP
