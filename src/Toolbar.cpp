//
// Created by VerOchka on 02.11.2023.
//

#include "Toolbar.hpp"

Toolbar::Toolbar(std::vector<std::u16string> names,
                 std::vector<std::function<void()>> funcs,
                 Forms::Color color,
                 const GraphicLib::PickableTexture::Ptr& canvas)
    : _names(std::move(names)),
      _funcs(std::move(funcs)),
      _color(color),
      _gui(canvas) {}

void Toolbar::init(glm::vec2 transform, glm::vec2 scale, bool horizontal) {
    using namespace GraphicLib;
    Primitives::AbstractPrimitive::Ptr rectangle = std::make_shared<Primitives::Rectangle>(
        Primitives::Primitive::Settings{.with_normals = false,
                                        .with_texture_coords = false,
                                        .with_tangent = false,
                                        .with_bitangent = false});
    rectangle->bindData(GL_STATIC_DRAW);

    float xOffset = transform.x;
    float yOffset = transform.y;

    for (int i{}; i < _names.size(); ++i) {
        auto button = std::make_shared<Forms::Button>(rectangle);

        button->init({scale}, {xOffset, yOffset},
                     {.content = _names.at(i)}, _color);

        button->setPressCallback(_funcs[i]);

        _gui.addForm(button);

        if (horizontal) {
            xOffset += (scale.x + 0.01f);
        } else {
            yOffset -= (scale.y + 0.01f);
        }
    }
}

const Controllers::GuiController::Ptr& Toolbar::getController() const {
    return _gui.getController();
}

void Toolbar::draw() {
    _gui.draw();
}
