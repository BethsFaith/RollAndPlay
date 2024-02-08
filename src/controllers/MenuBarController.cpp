//
// Created by VerOchka on 22.01.2024.
//

#include "MenuBarController.hpp"

namespace Controllers {
    void MenuBarController::processKeyboardInput(GLFWwindow* window) {
    }

    void MenuBarController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (const auto& widget : _widgets) {
                auto elems = widget->getElements();
                for (const auto& button : elems) {
                    if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                        if (_lastButton.lock() != nullptr) {
                            _lastButton.lock()->release();
                        }
                        _lastButton = button;

                        button->press();

                        break;
                    }
                }

                widget->update();
            }
        }
    }

    void MenuBarController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        for (const auto& widget : _widgets) {
            auto elems = widget->getElements();

            for (const auto& button : elems) {
                if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                    button->setUnderCursor(true);
                } else {
                    button->setUnderCursor(false);
                }
            }
        }
    }

    void MenuBarController::processMouseScroll(double xOffset, double yOffset) {

    }

    void MenuBarController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {

    }

    void MenuBarController::clear() {
        _widgets.clear();
    }

    void MenuBarController::addWidget(Widgets::Widget::Ptr widget) {
        if (widget->getType() != Widgets::MENU_BAR) {
            return ;
        }

        auto menuBar = std::dynamic_pointer_cast<Widgets::MenuBar>(widget);
        if (menuBar != nullptr) {
            _widgets.push_back(menuBar);
        }
    }
}