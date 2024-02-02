//
// Created by VerOchka on 10.10.2023.
//

#include "Color.hpp"

namespace Widgets::Styles {
    glm::vec3 getRGB(Color color) {
        switch (color) {
            case WHITE:
                return {255, 255, 255};
            case GRAY:
                return glm::vec3{0.4f};
            case BLACK:
                return glm::vec3{0.0f};
            case RED:
                return {1.0f, 0, 0};
            case GREEN:
                return {0.0f, 1.0f, 0};
            case BLUE:
                return {0.0f, 0.0f, 1.0f};
            case YELLOW:
                return {255, 255, 0};
            case ORANGE:
                return {255, 128, 0};
            case VIOLET:
                return {0.62f, 0.45f, 0.92f};
            case LIGHT_GRAY:
                return glm::vec3{0.7f};
            case LIGHT_BLUE:
                return {0.47f, 0.65f, 0.75f};
            case DARK_GRAY:
                return glm::vec3{0.1f};
            default:
                return glm::vec3{0.0f};
        }
    }
}    //namespace Forms
