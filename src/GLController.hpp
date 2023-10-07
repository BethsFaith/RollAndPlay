//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GLCONTROLLER_HPP
#define ROLLANDPLAY_GLCONTROLLER_HPP

#include <GLFW/glfw3.h>

class GLController {
public:
    GLController() = default;
    virtual ~GLController() = default;

    virtual void processKeyboardInput(GLFWwindow* window) = 0;
    virtual void processMouseInput(double xPos, double yPos) = 0;
    virtual void processMouseScroll(double xOffset, double yOffset) = 0;
};

#endif //ROLLANDPLAY_GLCONTROLLER_HPP
