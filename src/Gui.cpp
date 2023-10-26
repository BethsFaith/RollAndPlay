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
        if (button->isSelected()) {
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

            glStencilFunc(GL_ALWAYS, 1, 0xFF); // все фрагменты должны пройти тест трафарета
            glStencilMask(0xFF); // включаем запись в буфер трафарета

            button->renderForm(_shader);

            glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
            glStencilMask(0x00);
            glDisable(GL_STENCIL_TEST);

            button->renderText(_textShader);

            button->renderPick(_selectableShader);

            glDisable(GL_DEPTH_TEST);
            glEnable(GL_STENCIL_TEST);

            button->renderTracing(_shader);

            glStencilMask(0xFF);
            glStencilFunc(GL_ALWAYS, 1, 0xFF);
            glEnable(GL_DEPTH_TEST);
            glDisable(GL_STENCIL_TEST);
        } else {

            button->renderForm(_shader);

            button->renderText(_textShader);

            button->renderPick(_selectableShader);
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
