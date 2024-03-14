//
// Created by BethsFaith on 13.03.2024.
//

#include "Color.hpp"

namespace Pages::Style {
    glm::vec3 getRGB(Color color) {
        switch (color) {
            case WHITE:
                return {1.0f, 1.0f, 1.0f};
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
            case LIGHT_RED:
                return {0.59f, 0.33f, 0.33f};
            case LIGHT_GREEN:
                return  {0.79f, 1.0f, 0.79f};
            case LIGHT_YELLOW:
                return glm::vec3{0.0f};
            case LIGHT_ORANGE:
                return {0.7f, 0.46f, 0.34f};
            case LIGHT_BLUE:
                return {0.47f, 0.65f, 0.75f};
            case LIGHT_VIOLET:
                return {0.57f, 0.45f, 0.68f};
            case DARK_GRAY:
                return glm::vec3{0.1f};
            case DARK_RED:
                return {0.35f, 0.06f, 0.06f};
            case DARK_YELLOW:
                return glm::vec3{0.0f};
            case DARK_ORANGE:
                return {0.42f, 0.26f, 0.18f};;
            case DARK_VIOLET:
                return glm::vec3{0.0f};
            case DARK_GREEN:
                return {0.23f, 0.31f, 0.2f};
            case DARK_BLUE:
                return {0.0f, 0.31f, 0.37f};
            default:
                return glm::vec3{0.0f};
        }
    }
}