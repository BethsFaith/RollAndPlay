//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_MENUBARCONTROLLER_HPP
#define ROLLANDPLAY_MENUBARCONTROLLER_HPP

#include <map>

#include "../widgets/MenuBar.hpp"

#include "WidgetController.hpp"
#include "ButtonController.hpp"

namespace Controllers {
    class MenuBarController : public WidgetController {
    public:
        MenuBarController() = default;
        ~MenuBarController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;
        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;
        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;
        void processMouseScroll(double xOffset, double yOffset) override;
        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;
        void processDrop(GLFWwindow* window, int count, const char** paths) override;

        void addWidget(Widgets::Widget::Ptr widget) override;
        void removeWidget(const Widgets::Widget::Ptr& widget) override;
        void clear() override;

    private:
        std::vector<Widgets::MenuBar::Ptr> _widgets;
    };
}
#endif    //ROLLANDPLAY_MENUBARCONTROLLER_HPP
