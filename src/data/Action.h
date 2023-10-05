//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_ACTION_H
#define ROLLANDPLAY_ACTION_H

#include <iostream>
#include <utility>

#include "Skill.h"

namespace Data {
    class Action {
    public:
        Action(std::string name, uint8_t pointsNumber, uint8_t level, Skill *skill);

        ~Action() = default;

    private:
        std::string _name;
        uint8_t _pointsNumber;
        uint8_t _level;
        Skill *_skill;
    };
}

#endif //ROLLANDPLAY_ACTION_H
