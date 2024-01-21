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
    for (auto& form : _forms) {
        if (form->getType() == Forms::TEXT_BOX) {
            auto box = std::dynamic_pointer_cast<Forms::TextBox>(form);
            box->renderForm(colorShader);
            box->renderText(textShader);
        } else {
            auto button = std::dynamic_pointer_cast<Forms::Button>(form);
            if (button->isUnderCursor()) {
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
                glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

                glStencilFunc(GL_ALWAYS, 1, 0xFF);    // все фрагменты должны пройти тест трафарета
                glStencilMask(0xFF);    // включаем запись в буфер трафарета

                if (button->getType() != Forms::FormType::TEXTURE_BUTTON) {
                    button->renderForm(colorShader);
                } else {
                    button->renderForm(textureShader);
                }
                glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
                glStencilMask(0x00);
                glDisable(GL_STENCIL_TEST);

                button->renderText(textShader);

                button->renderPick(selectableShader);

                glDisable(GL_DEPTH_TEST);
                glEnable(GL_STENCIL_TEST);

                button->renderTracing(colorShader);

                glStencilMask(0xFF);
                glStencilFunc(GL_ALWAYS, 1, 0xFF);
                glEnable(GL_DEPTH_TEST);
                glDisable(GL_STENCIL_TEST);
            } else {
                if (button->getType() != Forms::FormType::TEXTURE_BUTTON) {
                    button->renderForm(colorShader);
                } else {
                    button->renderForm(textureShader);
                }

                button->renderText(textShader);

                button->renderPick(selectableShader);
            }
        }
    }
}

void Gui::addForm(const Forms::Form::Ptr& form) {
    form->setCanvas(_canvas);

    _controller->addForm(form);

    _forms.push_back(form);
}

void Gui::clear() {
    _forms.clear();
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
