//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_MAINCONTROLLER_HPP
#define ROLLANDPLAY_MAINCONTROLLER_HPP

#include "controllers/GLController.hpp"
#include "forms/Button.hpp"
#include "controllers/PageController.hpp"
#include "Picking.hpp"

class MainController : public Controllers::GLController {
public:
    void processKeyboardInput(GLFWwindow *window) override;

    void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

    void processMouseCursor(GLFWwindow* window, double x_pos, double y_pos) override;

    void processMouseScroll(double x_offset, double y_offset) override;

    void addButton(const Forms::Button::Ptr& button);

    void setViewController(Controllers::PageController *viewController);

    bool init(unsigned int windowWidth, unsigned int windowHeight);

    [[nodiscard]] const Picking &getPicking() const;

private:
    std::vector<Forms::Button::Ptr> _buttons;
    Controllers::PageController *_viewController;

    Picking _picking;
};

#endif //ROLLANDPLAY_MAINCONTROLLER_HPP
