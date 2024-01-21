//
// Created by VerOchka on 05.10.2023.
//

#include "Race.hpp"

namespace Data {
    Race::Race(std::string name) : _name(std::move(name)) {}

    void Race::addInitialSkillLevel(Skill::Ptr skill, unsigned int level) {
        _skillParameters.push_back(SkillLevel{.skill = std::move(skill), .level = level});
    }

    void Race::setModel(Graphic::Model::Ptr model) {
        _model = std::move(model);
    }

    void Race::setIconPath(const std::string& iconPath) {
        _iconPath = iconPath;
    }

    void Race::setName(const std::string& name) {
        _name = name;
    }
}    //namespace Data
