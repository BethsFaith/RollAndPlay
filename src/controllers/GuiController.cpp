//
// Created by VerOchka on 06.10.2023.
//

#include "GuiController.hpp"

namespace Controllers {
    void GuiController::processKeyboardInput(GLFWwindow *window) {
        for (const auto &controller: _formControllers) {
            controller.second->processKeyboardInput(window);
        }
    }

    void GuiController::processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) {
        for (const auto &controller: _formControllers) {
            controller.second->processMouseButton(window, mouseButton, action, mods);
        }
    }

    void GuiController::processMouseCursor(GLFWwindow *window, double xPos, double yPos) {
        for (const auto &controller: _formControllers) {
            controller.second->processMouseCursor(window, xPos, yPos);
        }
    }

    void GuiController::processMouseScroll(double xOffset, double yOffset) {
        for (const auto &controller: _formControllers) {
            controller.second->processMouseScroll(xOffset, yOffset);
        }
    }

    void GuiController::processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) {
        for (const auto &controller: _formControllers) {
            controller.second->processCharMods(window, codepoint, mods);
        }
    }

    void GuiController::addForm(const Forms::Form::Ptr &form) {
        auto type = form->getType();

        if (!_formControllers.contains(type)) {
            _formControllers[type] = FormControllerFactory::create(type);
        }
        _formControllers[type]->addForm(form);
    }

    void GuiController::clear() {
        _formControllers.clear();
    }
}