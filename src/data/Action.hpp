//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_ACTION_HPP
#define ROLLANDPLAY_ACTION_HPP

#include <iostream>
#include <utility>

#include "BaseData.hpp"
#include "convert/Convert.hpp"

namespace Data {
    class Action : public BaseData {
    public:
        using Ptr = std::shared_ptr<Action>;

        Action() = default;
        ~Action() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;
        size_t deserialize(Storage::StreamReader& reader) override;

        void serialize(Json::Value& jsonValue) override;
        void deserialize(const Json::Value& jsonValue) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        Type getType() override;

        void setName(const std::u16string& name);
        void setPointsNumber(uint8_t pointsNumber);
        void setIconPath(const std::string& iconPath);
        void setSkillId(int skillId);

        void setUserId(unsigned int userId);
        [[nodiscard]] const std::u16string& getName() const;
        [[nodiscard]] uint8_t getPointsNumber() const;
        [[nodiscard]] const std::string& getIconPath() const;
        [[nodiscard]] int getSkillId() const;
        [[nodiscard]] unsigned int getUserId() const;

    private:
        std::u16string _name;
        std::string _iconPath;

        uint8_t _pointsNumber{};
        unsigned int _userId{};
        int _skillId{-1};
    };
}    //namespace Data

#endif    //ROLLANDPLAY_ACTION_HPP
