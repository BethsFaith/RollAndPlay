//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_VIEWWINDOW_HPP
#define ROLLANDPLAY_VIEWWINDOW_HPP

#include <utility>

#include <primitives/Rectangle.hpp>
#include <shaders/ShaderProgram.hpp>

#include "controllers/GuiController.hpp"
#include "pages/Page.hpp"
#include "Gui.hpp"

class ViewWindow {
public:
    enum PageTag {
        SYSTEM_START
    };

    using Ptr = std::shared_ptr<ViewWindow>;

    ViewWindow(int x, int y, Forms::Color viewColor, const GraphicLib::PickableTexture::Ptr& canvas);
    ~ViewWindow();

    void display();

    void processKeyboardInput(GLFWwindow *window);

    void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods);

    void processMouseCursor(GLFWwindow* window, double x_pos, double y_pos);

    void processMouseScroll(GLFWwindow *window, double x_offset, double y_offset);

    void addPage(PageTag tag, Pages::Page::Ptr page);
private:
    Graphic::Object _view;

    GraphicLib::Shaders::ShaderProgram::Ptr _shader;

    Gui _gui;
    Controllers::GuiController _controller;

    std::map<PageTag, Pages::Page::Ptr> _pages;
    PageTag _currentPageTag = PageTag::SYSTEM_START;
};

#endif //ROLLANDPLAY_VIEWWINDOW_HPP
