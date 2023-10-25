//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_GUICONTROLLER_HPP
#define ROLLANDPLAY_GUICONTROLLER_HPP

#include "GLController.hpp"
#include "../forms/Button.hpp"
#include "PageController.hpp"
#include "PickableTexture.hpp"

namespace Controllers {
    class GuiController : public Controllers::GLController {
    public:
        using Ptr = std::shared_ptr<GuiController>;

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double x_pos, double y_pos) override;

        void processMouseScroll(double x_offset, double y_offset) override;

        void addButton(const Forms::Button::Ptr& button);

        void setViewController(Controllers::GLController::Ptr viewController);

        void clear() override;
        virtual ~GuiController() override = default;
        virtual void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

    private:
        std::vector<Forms::Button::Ptr> _buttons;
        Controllers::GLController::Ptr _viewController;
    };
}

#endif //ROLLANDPLAY_GUICONTROLLER_HPP
