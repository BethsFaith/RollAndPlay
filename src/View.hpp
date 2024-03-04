//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_VIEW_HPP
#define ROLLANDPLAY_VIEW_HPP

#include <GraphicLib/Shaders/ShaderProgram.hpp>
#include <GraphicLib/Controllers/CommonController.hpp>
#include <utility>

#include "ViewDrawer.hpp"
#include "config/Config.hpp"
#include "pages/APage.hpp"

class View {
public:
    enum PageTag {
        NULL_PAGE,
        SYSTEM,
        CHARACTERISTIC,
        SKILL,
        ACTION,
        RACE,
        CLASS,
        AUTHORIZATION,
        REGISTRATION
    };

    enum ViewTag {
        NULL_VIEW = -1,
        LOGIN = 0,
        SYSTEMS = 1,
        GAME = 2,
        LOBBY = 3
    };

    using Ptr = std::shared_ptr<View>;

    View(glm::vec2 minPos, glm::vec2 maxPos, GraphicLib::Widgets::Styles::Color viewColor, GraphicLib::Objects::PickableTexture::Ptr canvas);

    ~View();

    void display(int windowWidth, int windowHeight);

    void processKeyboardInput(GLFWwindow* window);

    void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods);

    void processMouseCursor(GLFWwindow* window, double x_pos, double y_pos);

    void processMouseScroll(GLFWwindow* window, double x_offset, double y_offset);

    void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods);

    void processDrop(GLFWwindow* window, int count, const char** paths);

    void addPage(PageTag tag, Pages::APage::Ptr page);

    bool needToClose() const;
private:
    void initView(glm::vec2 minPos, glm::vec2 maxPos, GraphicLib::Widgets::Styles::Color viewColor);
    void update();

    void switchPage(PageTag tag);

    ViewDrawer _view;
    const GraphicLib::Objects::PickableTexture::Ptr _canvas;

    GraphicLib::Controllers::CommonController _controller;

    std::map<PageTag, Pages::APage::Ptr> _pages;

    std::unique_ptr<std::thread> _stopPageThread;

    bool _needClose{false};
};

#endif    //ROLLANDPLAY_VIEW_HPP
