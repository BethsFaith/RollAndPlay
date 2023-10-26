//
// Created by VerOchka on 26.10.2023.
//

#include "ButtonController.hpp"

namespace Controllers {

    void ButtonController::processKeyboardInput(GLFWwindow *window) {
    }

    void ButtonController::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
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

    void ButtonController::processMouseCursor(GLFWwindow *window, double xPos, double yPos) {
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        for (auto &button: _buttons) {
            if (button->checkSelecting((int) xPos, int(height - yPos - 1))) {
                button->setSelected(true);
            } else {
                button->setSelected(false);
            }
        }
    }

    void ButtonController::processMouseScroll(double xOffset, double yOffset) {}

    void ButtonController::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {}

    void ButtonController::addForm(Forms::Form::Ptr form) {
        _buttons.push_back(std::dynamic_pointer_cast<Forms::Button>(form));
    }

    void ButtonController::clear() {
        _buttons.clear();
    }
}