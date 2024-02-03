//
// Created by BethsFaith on 02.02.2024.
//

#include "LayoutController.hpp"

namespace Controllers {
    void LayoutController::processKeyboardInput(GLFWwindow* window) {
        for (const auto &controller : _widgetsControllers) {
            controller.second->processKeyboardInput(window);
        }
    }

    void LayoutController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processMouseButton(window, mouseButton, action, mods);
        }
    }

    void LayoutController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processMouseCursor(window, xPos, yPos);
        }
    }

    void LayoutController::processMouseScroll(double xOffset, double yOffset) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processMouseScroll(xOffset, yOffset);
        }
    }

    void LayoutController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processCharMods(window, codepoint, mods);
        }
    }

    void LayoutController::clear() {
        _widgetsControllers.clear();
    }

    void LayoutController::addWidget(Widgets::Widget::Ptr widget) {
        auto layout = std::dynamic_pointer_cast<Widgets::Layout>(widget);
        auto elems = layout->getWidgets();
        for (const auto& elem : elems) {
            auto type = elem->getType();

            if (!_widgetsControllers.contains(type)) {
                auto controller = WidgetControllerFactory::create(type);
                if (controller == nullptr) {
                    return;
                }
                _widgetsControllers[type] = controller;
            }
            _widgetsControllers[type]->addWidget(elem);
        }
    }

}