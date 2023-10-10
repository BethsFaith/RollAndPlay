//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_CHARACTERCLASS_HPP
#define ROLLANDPLAY_CHARACTERCLASS_HPP

#include <iostream>
#include <vector>

#include "Action.hpp"
#include "SkillLevel.hpp"

namespace Data {
    class CharacterClass {
    public:
        CharacterClass(const std::string &name, const std::string &iconPath);

        void addAction(Action *action);

        void removeAction(Action *action);

        void addInitialSkillLevel(Skill *skill, int level);

    private:
        std::string _name;
        std::string _iconPath;
        std::vector<Action *> _actions;
        std::vector<SkillLevel> _skillParameters;
    };
}


#endif //ROLLANDPLAY_CHARACTERCLASS_HPP
