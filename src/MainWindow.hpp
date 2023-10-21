//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_MAINWINDOW_HPP
#define ROLLANDPLAY_MAINWINDOW_HPP

#include "EntryPoint.hpp"
#include <wtypes.h>
#include <stdexcept>
#include <glm/glm.hpp>
#include <vector>

#include "forms/Page.hpp"
#include "forms/Button.hpp"
#include "MainController.hpp"
#include "Gui.hpp"
#include "graphic/Rectangle.hpp"

class MainWindow {
public:
    static void init(const char *title);

    static void free();

    void run();

    static MainWindow *getInstance();

    [[nodiscard]] float getDeltaTime() const;

    [[nodiscard]] GLFWwindow *getWindow() const;

    void setClearColor(const glm::vec4 &clearColor);

protected:
    static void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    static void mouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods);

    static void mouseInputCallback(GLFWwindow *window, double xPos, double yPos);

    static void mouseScrollCallback(GLFWwindow *window, double xOffset, double yOffset);

private:
    static MainWindow *instance;

    explicit MainWindow(const char *title);

    ~MainWindow();

    bool shouldClose();

    void updateDeltaTime();

    void clearColor() const;

    GLFWwindow *_window = nullptr;
    Forms::Page *_view = nullptr;
    MainController _controller{};

    std::vector<Forms::Button::Ptr> _buttons;
    Gui::Ptr _gui;

    glm::vec4 _clearColor{};

    float _delta_time = 0.0f;    // время между текущим и последним кадрами
    float _last_frame = 0.0f;   // время последнего кадра
};

#endif //ROLLANDPLAY_MAINWINDOW_HPP
