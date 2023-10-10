//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_RACE_HPP
#define ROLLANDPLAY_RACE_HPP

#include <iostream>
#include <vector>
#include <utility>

#include "SkillLevel.hpp"
#include "graphic/Model.hpp"

namespace Data {
    class Race {
    public:
        explicit Race(std::string name);

        void addInitialSkillLevel(Skill *skill, int level);

        void setModel(Graphic::Model *model);

        void setName(const std::string &name);

        void setIconPath(const std::string &iconPath);

    private:
        std::string _name;
        std::string _iconPath;
        Graphic::Model *_model{};
        std::vector<SkillLevel> _skillParameters;
    };
} // Data

#endif //ROLLANDPLAY_RACE_HPP
