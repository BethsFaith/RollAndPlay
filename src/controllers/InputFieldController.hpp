//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_INPUTFIELDCONTROLLER_HPP
#define ROLLANDPLAY_INPUTFIELDCONTROLLER_HPP

#include <chrono>
#include <thread>

#include "FormController.hpp"
#include "../forms/InputField.hpp"

namespace Controllers {
    class InputFieldController : public FormController {
    public:
        ~InputFieldController() override = default;

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow *window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void clear() override;

        void processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) override;

        void addForm(Forms::Form::Ptr form) override;

    private:
        Forms::InputField::Ptr _target = nullptr;
        std::vector<Forms::InputField::Ptr> _buttons;
    };
}

#endif    //ROLLANDPLAY_INPUTFIELDCONTROLLER_HPP
