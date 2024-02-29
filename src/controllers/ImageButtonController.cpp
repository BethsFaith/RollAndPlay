//
// Created by VerOchka on 26.10.2023.
//

#include "ImageButtonController.hpp"

namespace Controllers {
    void ImageButtonController::processKeyboardInput(GLFWwindow* window) {
//        if (_target != nullptr) {
//            if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS
//                && glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
//                auto string = glfwGetClipboardString(window);
//                if (string != NULL) {
//                    _target->setImage(string, 0);
//                }
//            }
//        }
    }

    void ImageButtonController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        if (mouseButton == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);

            int width, height;
            glfwGetWindowSize(window, &width, &height);

            for (auto& button : _buttons) {
                if (button->checkSelecting((int)xPos, int(height - yPos - 1))) {
                    if (target->widget.lock() != button && target->widget.lock() != nullptr) {
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

    void ImageButtonController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        glfwGetCursorPos(window, &xPos, &yPos);

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

    void ImageButtonController::processMouseScroll(double xOffset, double yOffset) {}

    void ImageButtonController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {}

    void ImageButtonController::processDrop(GLFWwindow* window, int count, const char** paths) {
        if (count == 1) {
            if (target->owner == this && target->widget.lock() != nullptr) {
                auto targetImageButton = std::dynamic_pointer_cast<Widgets::ImageButton>(target->widget.lock());
                targetImageButton->setImage(paths[0], 0);
                targetImageButton->release();
            }
        }
    }

    void ImageButtonController::clear() {
        if (target->owner == this && target->widget.lock() != nullptr) {
            target->widget.lock()->release();
            target->widget.lock() = nullptr;
        }

        _buttons.clear();
    }

    void ImageButtonController::addWidget(Widgets::Widget::Ptr widget) {
        _buttons.push_back(std::dynamic_pointer_cast<Widgets::ImageButton>(widget));
    }

    void ImageButtonController::removeWidget(const Widgets::Widget::Ptr& widget) {
        auto end = std::remove(_buttons.begin(), _buttons.end(), widget);
        _buttons.erase(end, _buttons.end());
    }
}    //namespace Controllers
