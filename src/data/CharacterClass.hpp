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

        void addAction(Action::Ptr action);

        void removeAction(Action::Ptr action);

        void addInitialSkillLevel(Skill::Ptr skill, int level);

    private:
        std::string _name;
        std::string _iconPath;
        std::vector<Action::Ptr> _actions;
        std::vector<SkillLevel> _skillParameters;
    };
}


#endif //ROLLANDPLAY_CHARACTERCLASS_HPP
