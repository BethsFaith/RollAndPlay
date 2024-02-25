//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GLCONTROLLER_HPP
#define ROLLANDPLAY_GLCONTROLLER_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <iostream>

namespace Controllers {
    class GLController {
    public:
        using Ptr = std::shared_ptr<GLController>;

        GLController() = default;

        virtual ~GLController() = default;

        virtual void processKeyboardInput(GLFWwindow* window) = 0;

        virtual void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) = 0;

        virtual void processMouseCursor(GLFWwindow* window, double xPos, double yPos) = 0;

        virtual void processMouseScroll(double xOffset, double yOffset) = 0;

        virtual void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) = 0;

        virtual void processDrop(GLFWwindow* window, int count, const char** paths) = 0;

        virtual void clear() = 0;
    };
}    //namespace Controllers
#endif    //ROLLANDPLAY_GLCONTROLLER_HPP
