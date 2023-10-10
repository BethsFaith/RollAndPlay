//
// Created by VerOchka on 10.10.2023.
//

#include "Color.hpp"

namespace Forms {
    [[maybe_unused]] glm::vec3 Forms::getRGB(Color color) {
        switch (color) {
            case RED:
                return {255, 0, 0};
            case GREEN:
                return {102, 204, 0};
            case BLUE:
                return {102, 78, 255};
            case YELLOW:
                return {255, 255, 0};
            case WHITE:
                return {255, 255, 255};
            case GREY:
                return {160, 160, 160};
            case ORANGE:
                return {255, 128, 0};
            case VIOLET:
                return {204, 153, 255};
        };
    }
}