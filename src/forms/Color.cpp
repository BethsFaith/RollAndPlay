//
// Created by VerOchka on 10.10.2023.
//

#include "Color.hpp"

namespace Forms {
    [[maybe_unused]] glm::vec3 Forms::getRGB(Color color) {
        switch (color) {
            case RED:
                return {1.0f, 0, 0};
            case GREEN:
                return {0.0f, 1.0f, 0};
            case BLUE:
                return {0.0f, 0.0f, 1.0f};
            case YELLOW:
                return {255, 255, 0};
            case WHITE:
                return {255, 255, 255};
            case GREY:
                return {0.48f, 0.48f, 0.48f};
            case ORANGE:
                return {255, 128, 0};
            case VIOLET:
                return {0.62f, 0.45f, 0.92f};
        };
    }
}