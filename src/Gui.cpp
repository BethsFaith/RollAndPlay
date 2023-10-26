//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

Gui::Gui(GraphicLib::PickableTexture::Ptr canvas) : _canvas(std::move(canvas)) {
    _controller = std::make_shared<Controllers::GuiController>();

    _shader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\gui.vert)",
             R"(..\..\rsrc\shaders\gui.frag)");
    _selectableShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\gui.vert)",
             R"(..\..\rsrc\shaders\select.frag)");
    _textShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\text2d.vert)",
             R"(..\..\rsrc\shaders\text2d.frag)");
}

void Gui::draw() {
    for (auto &button: _buttons) {
        button->renderForm(_shader);

        button->renderText(_textShader);

        button->renderPick(_selectableShader);

        if (button->isSelected()) {
            // нарисовать обводку;
        }
    }
}

void Gui::addButton(const Forms::Button::Ptr& button) {
    button->setCanvas(_canvas);

    _controller->addForm(button);

    _buttons.push_back(button);
}

void Gui::clear() {
    _buttons.clear();
}

const Controllers::GuiController::Ptr &Gui::getController() const {
    return _controller;
}
