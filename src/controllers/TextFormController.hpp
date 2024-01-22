//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTFORMCONTROLLER_HPP
#define ROLLANDPLAY_TEXTFORMCONTROLLER_HPP

#include <chrono>
#include <thread>

#include "../widgets/TextForm.hpp"
#include "WidgetController.hpp"

namespace Controllers {
    class TextFormController : public WidgetController {
    public:
        ~TextFormController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void clear() override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void addWidget(Widgets::Widget::Ptr widget) override;

    private:
        Widgets::TextForm::Ptr _target = nullptr;
        std::vector<Widgets::TextForm::Ptr> _buttons;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_TEXTFORMCONTROLLER_HPP
