//
// Created by VerOchka on 02.11.2023.
//

#ifndef ROLLANDPLAY_TOOLBAR_HPP
#define ROLLANDPLAY_TOOLBAR_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "Gui.hpp"

class Toolbar {
public:
    using Ptr = std::shared_ptr<Toolbar>;

    Toolbar(std::vector<std::u16string> names,
            std::vector<std::function<void()>> funcs,
            Forms::Color color,
            const GraphicLib::PickableTexture::Ptr& canvas);

    void init(glm::vec2 transform, glm::vec2 scale, bool horizontal);

    void draw();

    [[nodiscard]] const Controllers::GuiController::Ptr& getController() const;

private:
    std::vector<std::u16string> _names{};
    std::vector<std::function<void()>> _funcs{};
    Forms::Color _color;

    Gui _gui;
};

#endif    //ROLLANDPLAY_TOOLBAR_HPP
