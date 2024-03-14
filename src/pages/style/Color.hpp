//
// Created by BethsFaith on 13.03.2024.
//

#ifndef INC_1_BIN_COLOR_HPP
#define INC_1_BIN_COLOR_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Pages::Style {
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
        LIGHT_RED,
        LIGHT_GREEN,
        LIGHT_BLUE,
        LIGHT_YELLOW,
        LIGHT_ORANGE,
        LIGHT_VIOLET,
        DARK_GRAY,
        DARK_RED,
        DARK_GREEN,
        DARK_BLUE,
        DARK_YELLOW,
        DARK_ORANGE,
        DARK_VIOLET,
    };

    [[maybe_unused]] glm::vec3 getRGB(Color color);
}

#endif    //INC_1_BIN_COLOR_HPP
