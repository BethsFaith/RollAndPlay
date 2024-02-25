//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_MAINWINDOW_HPP
#define ROLLANDPLAY_MAINWINDOW_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Primitives/Rectangle.hpp>
#include <GraphicLib/Shaders/ShaderProgram.hpp>
#include <glm/glm.hpp>
#include <stdexcept>
#include <vector>

#include "pages/LoginPage.hpp"
#include "pages/RacePage.hpp"
#include "pages/RegistrationPage.hpp"
#include "pages/SkillPage.hpp"
#include "pages/SystemPage.hpp"
#include "widgets/Button.hpp"
#include "Gui.hpp"
#include "View.hpp"
#include "config/Config.hpp"
#include "controllers/GuiController.hpp"

class MainWindow {
public:
    static void init(const char* title, const std::string& configFilePath);

    static void free();

    void run();

    static MainWindow* getInstance();

    [[nodiscard]] float getDeltaTime() const;

    [[nodiscard]] GLFWwindow* getWindow() const;

    void setClearColor(const glm::vec4& clearColor);

protected:
    static void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

    static void mouseButtonCallback(GLFWwindow* window, int mouseButton, int action, int mods);

    static void mouseInputCallback(GLFWwindow* window, double xPos, double yPos);

    static void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);

    static void charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods);

    static void dropCallback(GLFWwindow* window, int count, const char** paths);

private:
    static MainWindow* instance;

    explicit MainWindow(const char* title, const std::string& configFilePath);

    ~MainWindow();

    bool shouldClose();

    void updateDeltaTime();

    void clearColor() const;

    GLFWwindow* _window = nullptr;

    View::Ptr _view;

    glm::vec4 _clearColor{};

    float _delta_time = 0.0f;    // время между текущим и последним кадрами
    float _last_frame = 0.0f;    // время последнего кадра

    GraphicLib::PickableTexture::Ptr _canvas;
};

#endif    //ROLLANDPLAY_MAINWINDOW_HPP
