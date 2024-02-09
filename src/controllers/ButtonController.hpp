//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_BUTTONCONTROLLER_HPP
#define ROLLANDPLAY_BUTTONCONTROLLER_HPP

#include <memory>

#include "../widgets/Button.hpp"
#include "WidgetController.hpp"

namespace Controllers {
    class ButtonController : public WidgetController {
    public:
        ButtonController() = default;
        ~ButtonController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void processDrop(GLFWwindow* window, int count, const char** paths) override;

        void clear() override;
        void addWidget(Widgets::Widget::Ptr widget) override;

    private:
        std::vector<Widgets::Button::Ptr> _buttons;
        std::weak_ptr<Widgets::Button> _lastButton;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_BUTTONCONTROLLER_HPP
