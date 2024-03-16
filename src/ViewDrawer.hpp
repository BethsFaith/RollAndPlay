//
// Created by VerOchka on 22.01.2024.
//

#ifndef ROLLANDPLAY_VIEWDRAWER_HPP
#define ROLLANDPLAY_VIEWDRAWER_HPP

#include <GraphicLib/Objects/Primitives/Rectangle.hpp>
#include <GraphicLib/GuiObjects/Gui.hpp>

#include "pages/APage.hpp"
#include "pages/style/Color.hpp"

class ViewDrawer {
public:
    explicit ViewDrawer(GraphicLib::Objects::PickableTexture::Ptr canvas);

    void draw(int windowWidth, int windowHeight);

    void createHorizontalMenu(int menuId, std::vector<std::u16string> names,
                       std::vector<std::function<void()>> funcs);

    void createVerticalMenu(std::vector<std::u16string> names,
                                   std::vector<std::function<void()>> funcs);
    
    void showHorizontalMenu(int menuId);

    void setPage(const Pages::APage::Ptr& page);
    void setPosition(glm::vec2 xLine, glm::vec2 yLine);
    void setViewBackgroundColor(const glm::vec3& viewBackgroundColor);

    [[nodiscard]] const Pages::APage::Ptr& getPage() const;
    GraphicLib::Controllers::GuiController::Ptr getController();
private:
    Pages::APage::Ptr _page;
    std::map<int, std::vector<GraphicLib::GuiObjects::Button::Ptr>> _horizontalMenuButtons;

    GraphicLib::GuiObjects::MenuBar::Ptr _horizontalMenu;
    GraphicLib::GuiObjects::MenuBar::Ptr _verticalMenu;

    GraphicLib::GuiObjects::Gui _gui;

    glm::vec2 _start{-0.9f, -0.9f};
    glm::vec2 _end{1.0f, 1.0f};

    glm::vec3 _viewBackgroundColor;
};

#endif    //ROLLANDPLAY_VIEWDRAWER_HPP
