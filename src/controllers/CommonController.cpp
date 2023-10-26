//
// Created by VerOchka on 26.10.2023.
//

#include "CommonController.hpp"

namespace Controllers {
    void CommonController::processKeyboardInput(GLFWwindow *window) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        for (const auto& controller : _subControllers) {
            controller->processKeyboardInput(window);
        }
    }

    void CommonController::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
        for (const auto& controller : _subControllers) {
            controller->processMouseButton(window, mouseButton, action, mods);
        }
    }

    void CommonController::processMouseCursor(GLFWwindow *window, double xPos, double yPos) {
        for (const auto& controller : _subControllers) {
            controller->processMouseCursor(window, xPos, yPos);
        }
    }

    void CommonController::processMouseScroll(double xOffset, double yOffset) {
        for (const auto& controller : _subControllers) {
            controller->processMouseScroll(xOffset, yOffset);
        }
    }

    void CommonController::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {
        for (const auto& controller : _subControllers) {
            controller->processCharMods(window, codepoint, mods);
        }
    }

    void CommonController::clear() {
        _subControllers.clear();
    }

    void CommonController::addSubController(GLController::Ptr controller) {
        _subControllers.push_back(controller);
    }
}