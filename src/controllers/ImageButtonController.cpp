//
// Created by VerOchka on 26.10.2023.
//

#include "ImageButtonController.hpp"

namespace Controllers {
    void ImageButtonController::processKeyboardInput(GLFWwindow* window) {
        if (_target != nullptr) {
            if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS
                && glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
                auto string = glfwGetClipboardString(window);
                if (string != NULL) {
                    _target->setImage(string, 0);
                }
            }
        }
    }

    void ImageButtonController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (auto& button : _buttons) {
                if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                    if (_target != button) {
                        button->press();

                        if (_target != nullptr) {
                            _target->setUnderCursor(false);
                        }
                        _target = button;
                        _target->setUnderCursor(true);
                    }
                    break;
                }
            }
        }
    }

    void ImageButtonController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {}

    void ImageButtonController::processMouseScroll(double xOffset, double yOffset) {}

    void ImageButtonController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {}

    void ImageButtonController::clear() {}

    void ImageButtonController::addWidget(Widgets::Widget::Ptr widget) {
        _buttons.push_back(std::dynamic_pointer_cast<Widgets::ImageButton>(widget));
    }
}    //namespace Controllers
