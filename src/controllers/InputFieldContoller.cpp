//
// Created by VeraTag on 25.10.2023.
//

#include "InputFieldController.hpp"

namespace Controllers {
    void InputFieldController::processKeyboardInput(GLFWwindow *window) {
        if (_target != nullptr) {
            if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS) {
                _target->popFromBuffer();
            }
        }
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

                    if (_target != nullptr) {
                        _target->setSelected(false);
                    }
                    _target = button;
                    _target->setSelected(true);

                    break;
                }
            }
        }
    }

    void InputFieldController::processMouseCursor(GLFWwindow *window, double x_pos, double y_pos) {
    }

    void InputFieldController::processMouseScroll(double x_offset, double y_offset) {
    }

    void InputFieldController::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {
        std::cout << codepoint << std::endl;
        if (_target != nullptr) {
            std::cout << codepoint << std::endl;
            _target->putToBuffer((char) codepoint);
        }
    }

    void InputFieldController::clear() {
        _buttons.clear();
        _target.reset();
    }

    void InputFieldController::addForm(Forms::Form::Ptr form) {
        _buttons.push_back(std::dynamic_pointer_cast<Forms::InputField>(form));
    }
}