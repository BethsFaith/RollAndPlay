//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP
#define ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP

#include <chrono>
#include <thread>

#include "../widgets/TextInputField.hpp"
#include "WidgetController.hpp"

namespace Controllers {
    class TextInputFieldController : public WidgetController {
    public:
        ~TextInputFieldController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void clear() override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void addWidget(Widgets::Widget::Ptr widget) override;
        void processDrop(GLFWwindow* window, int count, const char** paths) override;
        void removeWidget(const Widgets::Widget::Ptr& widget) override;

    private:
        Widgets::TextInputField::Ptr _target = nullptr;
        std::vector<Widgets::TextInputField::Ptr> _buttons;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP
