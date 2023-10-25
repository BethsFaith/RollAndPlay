//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_COLOR_HPP
#define ROLLANDPLAY_COLOR_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Forms {
    enum Color {
        RED,
        GREEN,
        BLUE,
        YELLOW,
        WHITE,
        DARK_GRAY,
        GRAY,
        LIGHT_GRAY,
        ORANGE,
        VIOLET,
        BLACK,
        LIGHT_BLUE
    };

    [[maybe_unused]] glm::vec3 getRGB(Color color);
}

#endif //ROLLANDPLAY_COLOR_HPP
