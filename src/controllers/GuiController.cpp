//
// Created by VerOchka on 06.10.2023.
//

#include "GuiController.hpp"

namespace Controllers {
    void GuiController::processKeyboardInput(GLFWwindow* window) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processKeyboardInput(window);
        }
    }

    void GuiController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {
        for (const auto& pair : _widgetsControllers) {
            pair.second->processMouseButton(window, mouseButton, action, mods);
        }
    }

    void GuiController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processMouseCursor(window, xPos, yPos);
        }
    }

    void GuiController::processMouseScroll(double xOffset, double yOffset) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processMouseScroll(xOffset, yOffset);
        }
    }

    void GuiController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processCharMods(window, codepoint, mods);
        }
    }

    void GuiController::processDrop(GLFWwindow* window, int count, const char** paths) {
        for (const auto& controller : _widgetsControllers) {
            controller.second->processDrop(window, count, paths);
        }
    }

    void GuiController::addWidget(const Widgets::Widget::Ptr& widget){
        auto type = widget->getType();

        if (!_widgetsControllers.contains(type)) {
            auto controller = WidgetControllerFactory::create(type);
            if (controller == nullptr) {
                return;
            }
            _widgetsControllers[type] = controller;
        }
        _widgetsControllers[type]->addWidget(widget);
    }

    void GuiController::removeWidget(const Widgets::Widget::Ptr& widget) {
        auto type = widget->getType();

        if (_widgetsControllers.contains(type)) {
            _widgetsControllers[type]->removeWidget(widget);
        }
    }

    void GuiController::clear() {
        _widgetsControllers.clear();
    }
}    //namespace Controllers
