//
// Created by VerOchka on 05.10.2023.
//

#include "Action.hpp"

namespace Data {
    size_t Action::serialize(Storage::StreamWriter& writer) const {
        return 0;
    }

    size_t Action::deserialize(Storage::StreamReader& reader) {
        return 0;
    }

    size_t Action::serialized_size() const noexcept {
        return 0;
    }

    void Action::setName(const std::string& name) {
        _name = name;
    }

    void Action::setPointsNumber(uint8_t pointsNumber) {
        _pointsNumber = pointsNumber;
    }

    void Action::setLevel(uint8_t level) {
        _level = level;
    }

    void Action::setSkill(Skill::Ptr skill) {
        _skill = skill;
    }

    const std::string& Action::getName() const {
        return _name;
    }

    uint8_t Action::getPointsNumber() const {
        return _pointsNumber;
    }

    uint8_t Action::getLevel() const {
        return _level;
    }

    Skill::Ptr Action::getSkill() const {
        return _skill;
    }
}    //namespace Data
