//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_MAINCONTROLLER_HPP
#define ROLLANDPLAY_MAINCONTROLLER_HPP

#include "GLController.hpp"
#include "forms/Button.hpp"
#include "controllers/PageController.hpp"

class MainController : public GLController {
public:
    void processKeyboardInput(GLFWwindow *window) override;

    void processMouseInput(double x_pos, double y_pos) override;

    void processMouseScroll(double x_offset, double y_offset) override;

    void addButton(Forms::Button *button);

    void setViewController(Controllers::PageController *viewController);

private:
    std::vector<Forms::Button *> _buttons;
    Controllers::PageController *_viewController;
};

#endif //ROLLANDPLAY_MAINCONTROLLER_HPP
