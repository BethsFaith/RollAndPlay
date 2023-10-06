//
// Created by VerOchka on 05.10.2023.
//

#include "Skill.hpp"

namespace Data {
    uint8_t Skill::Category::index = 0;

    Skill::Category::Category(std::string name) : _index(index++), _name(std::move(name)) {
    }

    void Skill::Category::setIconPath(const std::string &imagePath) {
        _iconPath = imagePath;
    }
}