//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_COMMONCONTROLLER_HPP
#define ROLLANDPLAY_COMMONCONTROLLER_HPP

#include <vector>

#include "GLController.hpp"

namespace Controllers {
    class CommonController : public GLController {
    public:
        using Ptr = std::shared_ptr<CommonController>;

        CommonController() = default;
        ~CommonController() override = default;

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseButton(GLFWwindow *window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow *window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow *window, unsigned int codepoint, int mods) override;

        void clear() override;

        void addSubController(GLController::Ptr controller);
    private:
        std::vector<GLController::Ptr> _subControllers;
    };
}


#endif //ROLLANDPLAY_COMMONCONTROLLER_HPP
