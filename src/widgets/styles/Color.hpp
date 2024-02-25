//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_COLOR_HPP
#define ROLLANDPLAY_COLOR_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Widgets::Styles {
    enum Color {
        WHITE,
        GRAY,
        BLACK,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        ORANGE,
        VIOLET,
        LIGHT_GRAY,
        LIGHT_BLUE,
        LIGHT_VIOLET,
        LIGHT_GREEN,
        DARK_GRAY,
        DARK_BLUE,
        DARK_GREEN,
    };

    [[maybe_unused]] glm::vec3 getRGB(Color color);
}    //namespace Forms

#endif    //ROLLANDPLAY_COLOR_HPP
