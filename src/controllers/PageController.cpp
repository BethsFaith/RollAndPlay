//
// Created by VerOchka on 07.10.2023.
//

#include "PageController.hpp"

namespace Controllers {
    void PageController::processKeyboardInput(GLFWwindow *window) {
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
    }

    void PageController::processMouseCursor(GLFWwindow *window, double xPos, double yPos) {

    }

    void PageController::processMouseScroll(double xOffset, double yOffset) {

    }

    void PageController::addButton(const Forms::Button::Ptr &button) {
        _buttons.push_back(button);
    }

    void PageController::clear() {
        _buttons.clear();
    }
}