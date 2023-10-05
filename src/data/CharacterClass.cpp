//
// Created by VerOchka on 05.10.2023.
//

#include "CharacterClass.h"

namespace Data {
    CharacterClass::CharacterClass(const std::string &name, const std::string &iconPath) : _name(name),
                                                                                           _iconPath(iconPath) {}

    void CharacterClass::addAction(Action *action) {
        _actions.push_back(action);
    }

    void CharacterClass::removeAction(Action *action) {
        auto num = std::erase(_actions, action);
        if (num < 1) {
            //
        }
    }

    void CharacterClass::addInitialSkillLevel(Skill *skill, int level) {
        _skillParameters.push_back(SkillLevel{.skill = skill, .level = level});
    }
}
