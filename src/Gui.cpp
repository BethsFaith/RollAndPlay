//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

Gui::Gui(GraphicLib::PickableTexture::Ptr canvas) : _canvas(std::move(canvas)) {
    _controller = std::make_shared<Controllers::GuiController>();

    auto guiPaths = Config::getPaths(Config::Resource::SHADERS, "gui",
                                     {"vertex", "fragment"});
    auto selectablePaths = Config::getPaths(Config::Resource::SHADERS, "selectable",
                                     {"vertex", "fragment"});
    auto textPaths = Config::getPaths(Config::Resource::SHADERS, "text",
                                      {"vertex", "fragment"});
    auto texturePaths = Config::getPaths(Config::Resource::SHADERS, "texture_gui",
                                      {"vertex", "fragment"});

    _colorShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (guiPaths.front(),
            guiPaths.back());

    _selectableShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (selectablePaths.front(),
             selectablePaths.back());

    _textShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (textPaths.front(),
             textPaths.back());

    _textureShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (texturePaths.front(),
             texturePaths.back());
}

void Gui::draw() {
    for (auto &form: _forms) {
        if (form->getType() == Forms::TEXT_BOX) {
            auto box = std::dynamic_pointer_cast<Forms::TextBox>(form);
            box->renderForm(_colorShader);
            box->renderText(_textShader);
        } else {
            auto button = std::dynamic_pointer_cast<Forms::Button>(form);
            if (button->isUnderCursor()) {
                glEnable(GL_STENCIL_TEST);
                glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
                glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

                glStencilFunc(GL_ALWAYS, 1, 0xFF); // все фрагменты должны пройти тест трафарета
                glStencilMask(0xFF); // включаем запись в буфер трафарета

                if (button->getType() != Forms::FormType::TEXTURE_BUTTON) {
                    button->renderForm(_colorShader);
                } else {
                    button->renderForm(_textureShader);
                }
                glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
                glStencilMask(0x00);
                glDisable(GL_STENCIL_TEST);

                button->renderText(_textShader);

                button->renderPick(_selectableShader);

                glDisable(GL_DEPTH_TEST);
                glEnable(GL_STENCIL_TEST);

                button->renderTracing(_colorShader);

                glStencilMask(0xFF);
                glStencilFunc(GL_ALWAYS, 1, 0xFF);
                glEnable(GL_DEPTH_TEST);
                glDisable(GL_STENCIL_TEST);
            } else {
                if (button->getType() != Forms::FormType::TEXTURE_BUTTON) {
                    button->renderForm(_colorShader);
                } else {
                    button->renderForm(_textureShader);
                }

                button->renderText(_textShader);

                button->renderPick(_selectableShader);
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

const Controllers::GuiController::Ptr &Gui::getController() const {
    return _controller;
}
