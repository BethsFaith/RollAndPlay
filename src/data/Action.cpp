//
// Created by VerOchka on 05.10.2023.
//

#include "Action.h"

namespace Data {
    Action::Action(std::string name, uint8_t pointsNumber, uint8_t level, Data::Skill *skill)
            : _name(std::move(name)),
              _pointsNumber(pointsNumber),
              _level(level),
              _skill(skill) {}

}