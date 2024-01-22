//
// Created by VerOchka on 02.11.2023.
//

#ifndef ROLLANDPLAY_MENUBAR_HPP
#define ROLLANDPLAY_MENUBAR_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "Gui.hpp"

class MenuBar {
public:
    using Ptr = std::shared_ptr<MenuBar>;

    MenuBar(std::vector<std::u16string> names,
            std::vector<std::function<void()>> funcs,
            Widgets::Color buttonColor,
            const GraphicLib::PickableTexture::Ptr& canvas);

    void init(glm::vec2 transform, glm::vec2 scale, bool horizontal);

    void draw();

    [[nodiscard]] const Controllers::GuiController::Ptr& getController() const;

private:
    std::vector<std::u16string> _names{};
    std::vector<std::function<void()>> _funcs{};
    Widgets::Color _buttonColor;

    Gui _gui;
};

#endif    //ROLLANDPLAY_MENUBAR_HPP
