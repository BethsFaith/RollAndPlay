//
// Created by VerOchka on 05.10.2023.
//

#ifndef ROLLANDPLAY_SKILL_H
#define ROLLANDPLAY_SKILL_H

#include <iostream>
#include <utility>

namespace Data {
    class Skill {
    public:
        struct Category {
        public:
            explicit Category(std::string name);
            ~Category() = default;

            void setIconPath(const std::string &imagePath);
        private:
            uint8_t _index;
            std::string _name;
            std::string _iconPath;

            static uint8_t index;
        };

    private:
        std::string _name;
        Category *category;
    };
}

#endif //ROLLANDPLAY_SKILL_H
