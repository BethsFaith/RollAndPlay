//
// Created by VeraTag on 25.10.2023.
//

#include "InputFieldController.hpp"

namespace Controllers {
    void InputFieldController::processKeyboardInput(GLFWwindow *window) {

    }

    void InputFieldController::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (auto &button: _buttons) {
                if (button->checkSelecting((int) xPos, int(height - yPos - 1))) {
                    button->press();

                    _target = button;

                    break;
                }
            }
        }
    }

    void InputFieldController::processMouseCursor(GLFWwindow *window, double x_pos, double y_pos) {
    }

    void InputFieldController::processMouseScroll(double x_offset, double y_offset) {
    }

    void InputFieldController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {
        char x = (char)codepoint;
        std::cout << codepoint << std::endl;
        if (_target != nullptr) {
            std::cout << codepoint << std::endl;
        }
    }

    void InputFieldController::addButton(const Forms::InputField::Ptr &button) {
        _buttons.push_back(button);
    }

    void InputFieldController::clear() {
        _buttons.clear();
    }
}