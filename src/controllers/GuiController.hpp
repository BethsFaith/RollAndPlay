//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GUICONTROLLER_HPP
#define ROLLANDPLAY_GUICONTROLLER_HPP

#include <GraphicLib/PickableTexture.hpp>
#include <vector>

#include "GLController.hpp"
#include "WidgetController.hpp"
#include "WidgetControllerFactory.hpp"

namespace Controllers {
    class GuiController : public Controllers::GLController {
    public:
        using Ptr = std::shared_ptr<GuiController>;

        GuiController() = default;
        ~GuiController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processDrop(GLFWwindow* window, int count, const char** paths) override;

        void clear() override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;
        void addWidget(const Widgets::Widget::Ptr& widget);
        void removeWidget(const Widgets::Widget::Ptr& widget);

    private:
        std::map<Widgets::WidgetType, WidgetController::Ptr> _widgetsControllers;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_GUICONTROLLER_HPP
