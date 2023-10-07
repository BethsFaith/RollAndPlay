//
// Created by VerOchka on 06.10.2023.
//

#include "MainController.hpp"

void MainController::processKeyboardInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void MainController::processMouseInput(double x_pos, double y_pos) {
    for (auto& button : _buttons) {
        if (x_pos >= button->getX() && y_pos == button->getY()) {
            button->press();
        }
    }
    if (_viewController != nullptr) {
        _viewController->processMouseInput(x_pos, y_pos);
    }
}

void MainController::processMouseScroll(double x_offset, double y_offset) {
    if (_viewController != nullptr) {
        _viewController->processMouseScroll(x_offset, y_offset);
    }
}

void MainController::addButton(Forms::Button *button) {
    _buttons.push_back(button);
}

void MainController::setViewController(Controllers::PageController *viewController) {
    _viewController = viewController;
}