//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_BUTTONCONTROLLER_HPP
#define ROLLANDPLAY_BUTTONCONTROLLER_HPP

#include "../forms/Button.hpp"
#include "FormController.hpp"

namespace Controllers {
    class ButtonController : public FormController {
    public:
        ~ButtonController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void clear() override;

        void addForm(Forms::Form::Ptr form) override;

    private:
        std::vector<Forms::Button::Ptr> _buttons;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_BUTTONCONTROLLER_HPP
