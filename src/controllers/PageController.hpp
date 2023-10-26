//
// Created by VerOchka on 07.10.2023.
//

#ifndef ROLLANDPLAY_PAGECONTROLLER_HPP
#define ROLLANDPLAY_PAGECONTROLLER_HPP

#include <GraphicLib/GlagGlfw.hpp>

#include "../forms/Button.hpp"
#include "GLController.hpp"

namespace Controllers {
    class PageController : public GLController {
    public:
        using Ptr = std::shared_ptr<PageController>;

        ~PageController() override = default;

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow *window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void addButton(const Forms::Button::Ptr &button);

        void clear();

        void addController(Controllers::GLController::Ptr controller);

        virtual void processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) override;

    private:
        std::vector<Forms::Button::Ptr> _buttons;
        std::vector<Controllers::GLController::Ptr> _controllers;
    };
}

#endif //ROLLANDPLAY_PAGECONTROLLER_HPP
