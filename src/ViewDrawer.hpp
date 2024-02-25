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
    explicit ViewDrawer(GraphicLib::PickableTexture::Ptr canvas);

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
    Controllers::GuiController::Ptr getController();
private:
    Pages::APage::Ptr _page;
    std::map<int, std::vector<Widgets::Button::Ptr>> _horizontalMenuButtons;

    Widgets::MenuBar::Ptr _horizontalMenu;
    Widgets::MenuBar::Ptr _verticalMenu;

    Gui _gui;

    glm::vec2 _xLine{-0.9f, 1.0f};
    glm::vec2 _yLine{-0.9f, 1.0f};

    glm::vec3 _viewBackgroundColor;
};

#endif    //ROLLANDPLAY_VIEWDRAWER_HPP
