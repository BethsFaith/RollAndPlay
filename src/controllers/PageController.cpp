//
// Created by VerOchka on 07.10.2023.
//

#include "PageController.hpp"

namespace Controllers {
    void PageController::processKeyboardInput(GLFWwindow *window) {
        for (const auto &controller: _controllers) {
            controller->processKeyboardInput(window);
        }
    }

    void PageController::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (auto &button: _buttons) {
                if (button->checkSelecting((int) xPos, int(height - yPos - 1))) {
                    button->press();
                    break;
                }
            }
        }

        for (const auto &controller: _controllers) {
            controller->processMouseButton(window, mouseButton, action, mods);
        }
    }

    void PageController::processMouseCursor(GLFWwindow *window, double xPos, double yPos) {
        for (const auto &controller: _controllers) {
            controller->processKeyboardInput(window);
        }
    }

    void PageController::processMouseScroll(double xOffset, double yOffset) {
        for (const auto &controller: _controllers) {
            controller->processMouseScroll(xOffset, yOffset);
        }
    }

    void PageController::clear() {
        _buttons.clear();
        _controllers.clear();
    }

    void PageController::addButton(const Forms::Button::Ptr &button) {
        _buttons.push_back(button);
    }

    void PageController::addController(Controllers::GLController::Ptr controller) {
        _controllers.push_back(controller);
    }

    void PageController::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {
        for (const auto &controller: _controllers) {
            controller->processCharMods(window, codepoint, mods);
        }
    }
}