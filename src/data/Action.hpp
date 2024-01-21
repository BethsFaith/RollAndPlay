//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_ACTION_HPP
#define ROLLANDPLAY_ACTION_HPP

#include <iostream>
#include <utility>

#include "IBitwiseSerializable.hpp"
#include "Skill.hpp"

namespace Data {
    class Action : public IBitwiseSerializable {
    public:
        using Ptr = std::shared_ptr<Action>;

        Action() = default;
        ~Action() override = default;

        size_t serialize(Storage::StreamWriter& writer) const override;

        size_t deserialize(Storage::StreamReader& reader) override;

        [[nodiscard]] size_t serialized_size() const noexcept override;

        void setName(const std::string& name);
        void setPointsNumber(uint8_t pointsNumber);
        void setLevel(uint8_t level);
        void setSkill(Skill::Ptr skill);

        [[nodiscard]] const std::string& getName() const;
        [[nodiscard]] uint8_t getPointsNumber() const;
        [[nodiscard]] uint8_t getLevel() const;
        [[nodiscard]] Skill::Ptr getSkill() const;

    private:
        std::string _name;
        uint8_t _pointsNumber{};
        uint8_t _level{};
        Skill::Ptr _skill{};
    };
}    //namespace Data

#endif    //ROLLANDPLAY_ACTION_HPP
