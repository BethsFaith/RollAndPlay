//
// Created by VerOchka on 22.01.2024.
//

#include "MenuBarController.hpp"

namespace Controllers {
    void MenuBarController::processKeyboardInput(GLFWwindow* window) {
        _controller.processKeyboardInput(window);
    }

    void MenuBarController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        _controller.processMouseButton(window, mouseButton, action, mods);
    }

    void MenuBarController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        _controller.processMouseCursor(window, xPos, yPos);
    }

    void MenuBarController::processMouseScroll(double xOffset, double yOffset) {
        _controller.processMouseScroll(xOffset, yOffset);
    }

    void MenuBarController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {
        _controller.processMouseScroll(codepoint, mods);
    }

    void MenuBarController::clear() {
        _controller.clear();
    }

    void MenuBarController::addWidget(Widgets::Widget::Ptr widget) {
        auto menuBar = std::dynamic_pointer_cast<Widgets::MenuBar>(widget);
        auto menuBarElems = menuBar->getElements();

        for (const auto& elem : menuBarElems) {
            _controller.addWidget(elem);
        }
    }
}