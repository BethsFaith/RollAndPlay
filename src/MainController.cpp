//
// Created by VerOchka on 06.10.2023.
//

#include "MainController.hpp"

void MainController::processKeyboardInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void MainController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
    if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        for (auto &button: _buttons) {
            if (button->checkSelecting((int)xPos,int(height - yPos - 1))) {
                button->press();
                break;
            }
        }
    }
    if (_viewController != nullptr) {
        _viewController->processMouseButton(window, mouseButton, action, mods);
    }
}

void MainController::processMouseCursor(GLFWwindow* window, double x_pos, double y_pos) {
    if (_viewController != nullptr) {
        _viewController->processMouseCursor(window, x_pos, y_pos);
    }
}

void MainController::processMouseScroll(double x_offset, double y_offset) {
    if (_viewController != nullptr) {
        _viewController->processMouseScroll(x_offset, y_offset);
    }
}

void MainController::addButton(const Forms::Button::Ptr& button) {
    _buttons.push_back(button);
}

void MainController::setViewController(Controllers::PageController *viewController) {
    _viewController = viewController;
}

void MainController::free() {
    _buttons.clear();
}
