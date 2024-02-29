//
// Created by VerOchka on 26.10.2023.
//

#include "ButtonController.hpp"

namespace Controllers {
    void ButtonController::processKeyboardInput(GLFWwindow* window) {}

    void ButtonController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (auto& button : _buttons) {
                if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                    if (target->widget.lock() != nullptr) {
                        target->widget.lock()->release();
                    }
                    target->widget = button;
                    target->owner = this;

                    button->press();

                    break;
                }
            }
        }
    }

    void ButtonController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        for (auto& button : _buttons) {
            if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                button->setUnderCursor(true);
            } else {
                button->setUnderCursor(false);
            }
        }
    }

    void ButtonController::processMouseScroll(double xOffset, double yOffset) {}

    void ButtonController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {}

    void ButtonController::processDrop(GLFWwindow* window, int count, const char** paths) {}

    void ButtonController::addWidget(Widgets::Widget::Ptr widget) {
        _buttons.push_back(std::dynamic_pointer_cast<Widgets::Button>(widget));
    }

    void ButtonController::removeWidget(const Widgets::Widget::Ptr& widget) {
        auto end = std::remove(_buttons.begin(), _buttons.end(), widget);
        _buttons.erase(end, _buttons.end());
    }

    void ButtonController::clear() {
        if (target->owner == this && target->widget.lock() != nullptr) {
            target->widget.lock()->release();
            target->widget.lock() = nullptr;
        }

        _buttons.clear();
    }
}    //namespace Controllers
