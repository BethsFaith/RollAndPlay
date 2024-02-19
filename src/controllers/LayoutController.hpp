//
// Created by BethsFaith on 02.02.2024.
//

#ifndef ROLLANDPLAY_LAYOUTCONTROLLER_HPP
#define ROLLANDPLAY_LAYOUTCONTROLLER_HPP

#include <map>

#include "WidgetController.hpp"
#include "WidgetControllerFactory.hpp"
#include "../widgets/Layout.hpp"

namespace Controllers {
    class LayoutController : public WidgetController {
    public:
        using Ptr = std::shared_ptr<LayoutController>;

        ~LayoutController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processDrop(GLFWwindow* window, int count, const char** paths) override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void clear() override;
        void addWidget(Widgets::Widget::Ptr widget) override;
        void removeWidget(const Widgets::Widget::Ptr& widget) override;

    private:
        std::map<Widgets::WidgetType, WidgetController::Ptr> _widgetsControllers;
    };
}

#endif    //ROLLANDPLAY_LAYOUTCONTROLLER_HPP
