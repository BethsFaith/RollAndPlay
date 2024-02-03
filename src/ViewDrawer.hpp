//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_VIEWDRAWER_HPP
#define ROLLANDPLAY_VIEWDRAWER_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "Gui.hpp"
#include "widgets/MenuBar.hpp"
#include "pages/APage.hpp"

class ViewDrawer {
public:
    ViewDrawer(GraphicLib::PickableTexture::Ptr canvas, GraphicLib::Shaders::ShaderProgram::Ptr shader);

    void init(int x, int y, Widgets::Styles::Color viewColor);

    void draw();

    void createHorizontalMenu(int menuId, std::vector<std::u16string> names,
                       std::vector<std::function<void()>> funcs);

    void createVerticalMenu(std::vector<std::u16string> names,
                                   std::vector<std::function<void()>> funcs);
    
    void showHorizontalMenu(int menuId);

    Controllers::GuiController::Ptr getController();

    //    void setPage(const Pages::APage::Ptr& page);
private:
    GraphicLib::Object _view;
    //    Pages::APage::Ptr _page;
    std::map<int, std::vector<Widgets::Button::Ptr>> _horizontalMenuButtons;

    Widgets::MenuBar::Ptr _horizontalMenu;
    Widgets::MenuBar::Ptr _verticalMenu;

    GraphicLib::Shaders::ShaderProgram::Ptr _shader;
    Gui _gui;
};

#endif    //ROLLANDPLAY_VIEWDRAWER_HPP
