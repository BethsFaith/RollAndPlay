//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GLCONTROLLER_HPP
#define ROLLANDPLAY_GLCONTROLLER_HPP

#include "EntryPoint.hpp"

namespace Controllers {
    class GLController {
    public:
        GLController() = default;

        virtual ~GLController() = default;

        virtual void processKeyboardInput(GLFWwindow *window) = 0;

        virtual void processMouseButton(GLFWwindow *window, int button, int action, int mods) = 0;

        virtual void processMouseCursor(GLFWwindow *window, double xPos, double yPos) = 0;

        virtual void processMouseScroll(double xOffset, double yOffset) = 0;
    };
}
#endif //ROLLANDPLAY_GLCONTROLLER_HPP
