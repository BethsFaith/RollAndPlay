//
// Created by VerOchka on 05.10.2023.
//

#include "CharacterClass.hpp"

namespace Data {
    CharacterClass::CharacterClass(std::string name, std::string iconPath)
        : _name(std::move(name)),
          _iconPath(std::move(iconPath)) {}

    void CharacterClass::addAction(const Action::Ptr& action) {
        _actions.push_back(action);
    }

    void CharacterClass::removeAction(const Action::Ptr& action) {
        auto num = std::erase(_actions, action);
        if (num < 1) {
            //
        }
    }

    void CharacterClass::addInitialSkillLevel(Skill::Ptr skill, unsigned int level) {
        _skillParameters.push_back(SkillLevel{.skill = std::move(skill), .level = level});
    }
}    //namespace Data
