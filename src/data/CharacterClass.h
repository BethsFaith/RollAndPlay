//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_CHARACTERCLASS_H
#define ROLLANDPLAY_CHARACTERCLASS_H

#include <iostream>
#include <vector>

#include "Action.h"
#include "SkillLevel.h"

namespace Data {
    class CharacterClass {
    public:
        CharacterClass(const std::string &name, const std::string &iconPath);

        void addAction(Action* action);
        void removeAction(Action* action);

        void addInitialSkillLevel(Skill *skill, int level);
    private:
        std::string _name;
        std::string _iconPath;
        std::vector<Action*> _actions;
        std::vector<SkillLevel> _skillParameters;
    };
}


#endif //ROLLANDPLAY_CHARACTERCLASS_H
