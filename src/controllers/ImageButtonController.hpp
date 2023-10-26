//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP
#define ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP

#include "FormController.hpp"
#include "../forms/ImageButton.hpp"

namespace Controllers {
    class ImageButtonController : public FormController {
    public:
        ~ImageButtonController() override = default;

        void addForm(Forms::Form::Ptr form) override;

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow *window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) override;

        void clear() override;

    private:
        Forms::ImageButton::Ptr _target = nullptr;
        std::vector<Forms::ImageButton::Ptr> _buttons;
    };
}


#endif //ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP
