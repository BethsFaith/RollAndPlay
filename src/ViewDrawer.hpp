//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_VIEWDRAWER_HPP
#define ROLLANDPLAY_VIEWDRAWER_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "Gui.hpp"
#include "pages/APage.hpp"

class ViewDrawer {
public:
    ViewDrawer(GraphicLib::PickableTexture::Ptr canvas, GraphicLib::Shaders::ShaderProgram::Ptr shader);

    void init(int x, int y, Widgets::Color viewColor);

    void draw();

    //    void setPage(const Pages::APage::Ptr& page);
private:
    GraphicLib::Object _view;
    //    Pages::APage::Ptr _page;

    GraphicLib::Shaders::ShaderProgram::Ptr _shader;
    Gui _gui;
};

#endif    //ROLLANDPLAY_VIEWDRAWER_HPP
