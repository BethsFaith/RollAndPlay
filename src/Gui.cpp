//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

Gui::Gui(const GraphicLib::PickableTexture::Ptr canvas) : _canvas(canvas) {
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
        button->disableTechnique(GraphicLib::Techniques::PICK);
        button->enableTechnique(GraphicLib::Techniques::COLOR);
        button->enableTechnique(GraphicLib::Techniques::TRANSFORM);
        button->disableTechnique(GraphicLib::Techniques::TEXT);
        button->render(_shader);

        button->disableTechnique(GraphicLib::Techniques::PICK);
        button->disableTechnique(GraphicLib::Techniques::COLOR);
        button->disableTechnique(GraphicLib::Techniques::TRANSFORM);
        button->enableTechnique(GraphicLib::Techniques::TEXT);
        button->render(_textShader);

        _canvas->enableWriting();
        button->disableTechnique(GraphicLib::Techniques::COLOR);
        button->enableTechnique(GraphicLib::Techniques::PICK);
        button->enableTechnique(GraphicLib::Techniques::TRANSFORM);
        button->disableTechnique(GraphicLib::Techniques::TEXT);
        button->render(_selectableShader);
        _canvas->disableWriting();
    }
}

void Gui::addButton(const Forms::Button::Ptr button, GraphicLib::Primitives::AbstractPrimitive::Ptr primitive) {
    auto object = std::make_shared<GraphicLib::Object>();

    object->setPrimitive(primitive);

    auto colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
    colorTechnique->setColor(Forms::getRGB(button->color));
    object->addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
    transformTechnique->enableScale(button->scale);
    transformTechnique->enableTransform(glm::vec3(button->getXOffset(),
                                                  button->getYOffset(), -0.1f));
    transformTechnique->disableRotateValue();
    object->addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

    auto picking = std::make_shared<GraphicLib::Techniques::PickTechnique>();
    picking->setObjectId(button->getId());
    object->addTechnique(GraphicLib::Techniques::PICK, picking);
    button->setCanvas(_canvas);

    auto textTechnique = std::make_shared<GraphicLib::Techniques::TextTechnique>();
    textTechnique->setText(button->title);
    textTechnique->setWidth(_textW);
    textTechnique->setHeight(_textH);
    textTechnique->setColor(glm::vec3{1.0f});
    object->addTechnique(GraphicLib::Techniques::TEXT, textTechnique);

    _buttons.push_back(object);
}

void Gui::setTextSize(float textW, float textH) {
    _textW = textW;
    _textH = textH;
}

void Gui::clear() {
    _buttons.clear();
}
