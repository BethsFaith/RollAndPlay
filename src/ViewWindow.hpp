//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_VIEWWINDOW_HPP
#define ROLLANDPLAY_VIEWWINDOW_HPP

#include <GraphicLib/Shaders/ShaderProgram.hpp>
#include <utility>

#include "ViewDrawer.hpp"
#include "config/Config.hpp"
#include "controllers/CommonController.hpp"
#include "pages/APage.hpp"

class ViewWindow {
public:
    enum PageTag {
        NULL_PAGE,
        SYSTEM,
        SKILL,
        ACTION,
        RACE,
        CLASS,
        EXPORT,
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

    using Ptr = std::shared_ptr<ViewWindow>;

    ViewWindow(int x,
               int y,
               Widgets::Color viewColor,
               GraphicLib::PickableTexture::Ptr canvas,
               GraphicLib::Shaders::ShaderProgram::Ptr shader);

    ~ViewWindow();

    void display();

    void processKeyboardInput(GLFWwindow* window);

    void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods);

    void processMouseCursor(GLFWwindow* window, double x_pos, double y_pos);

    void processMouseScroll(GLFWwindow* window, double x_offset, double y_offset);

    void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods);

    void addPage(PageTag tag, Pages::APage::Ptr page);

private:
    void initView(int x, int y, Widgets::Color viewColor);
    void updateControllers();
    void updateGui();

    ViewDrawer _view;
    GraphicLib::Shaders::ShaderProgram::Ptr _shader;

    const GraphicLib::PickableTexture::Ptr _canvas;
    Controllers::CommonController _controller;

    std::map<PageTag, Pages::APage::Ptr> _pages;

    PageTag _currentPageTag = PageTag::NULL_PAGE;
    ViewTag _currentViewTag = ViewTag::NULL_VIEW;
};

#endif    //ROLLANDPLAY_VIEWWINDOW_HPP
