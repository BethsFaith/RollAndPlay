//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

GraphicLib::Shaders::ShaderProgram::Ptr Gui::colorShader = nullptr;
GraphicLib::Shaders::ShaderProgram::Ptr Gui::textureShader = nullptr;
GraphicLib::Shaders::ShaderProgram::Ptr Gui::selectableShader = nullptr;
GraphicLib::Shaders::ShaderProgram::Ptr Gui::textShader = nullptr;

Gui::Gui(GraphicLib::PickableTexture::Ptr canvas) : _canvas(std::move(canvas)) {
    _controller = std::make_shared<Controllers::GuiController>();
}

void Gui::draw() {
    for (auto& form : _widgets) {
        if (form->getType() == Widgets::IMAGE_BUTTON) {
            form->draw(textureShader, textShader, selectableShader);
        } else {
            form->draw(colorShader, textShader, selectableShader);
        }
    }
}

void Gui::addWidget(const Widgets::Widget::Ptr& widget) {
    widget->setCanvas(_canvas);

    _controller->addWidget(widget);

    _widgets.push_back(widget);
}

void Gui::clear() {
    _widgets.clear();
//    _controller->clear();
}

const Controllers::GuiController::Ptr& Gui::getController() const {
    return _controller;
}

void Gui::setColorShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
    colorShader = std::move(shader);
}

void Gui::setTextureShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
    textureShader = std::move(shader);
}

void Gui::setSelectableShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
    selectableShader = std::move(shader);
}

void Gui::setTextShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
    textShader = std::move(shader);
}
