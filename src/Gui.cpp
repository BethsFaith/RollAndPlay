//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

Gui::Gui(const GraphicLib::PickableTexture::Ptr canvas) : _canvas(canvas){
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
    for (auto& button : _buttons) {
        button->disableTechnique(Graphic::Techniques::PICK);
        button->enableTechnique(Graphic::Techniques::COLOR);
        button->enableTechnique(Graphic::Techniques::TRANSFORM);
        button->disableTechnique(Graphic::Techniques::TEXT);
        button->render(_shader);

        button->disableTechnique(Graphic::Techniques::PICK);
        button->disableTechnique(Graphic::Techniques::COLOR);
        button->disableTechnique(Graphic::Techniques::TRANSFORM);
        button->enableTechnique(Graphic::Techniques::TEXT);
        button->render(_textShader);

        _canvas->enableWriting();
        button->disableTechnique(Graphic::Techniques::COLOR);
        button->enableTechnique(Graphic::Techniques::PICK);
        button->enableTechnique(Graphic::Techniques::TRANSFORM);
        button->disableTechnique(Graphic::Techniques::TEXT);
        button->render(_selectableShader);
        _canvas->disableWriting();
    }
}

void Gui::addButton(const Forms::Button::Ptr button, GraphicLib::Primitives::AbstractPrimitive::Ptr primitive) {
    auto object = std::make_shared<Graphic::Object>();

    object->setPrimitive(primitive);

    auto colorTechnique = std::make_shared<Graphic::Techniques::ColorTechnique>();
    colorTechnique->setColor(Forms::getRGB(button->color));
    object->addTechnique(Graphic::Techniques::COLOR, colorTechnique);

    auto transformTechnique = std::make_shared<Graphic::Techniques::TransformTechnique>();
    transformTechnique->enableScale(glm::vec3(0.1, 0.1, 0.0f));
    transformTechnique->enableTransform(glm::vec3(button->getXOffset(),
                                                  button->getYOffset(), -0.1f));
    transformTechnique->disableRotateValue();
    object->addTechnique(Graphic::Techniques::TRANSFORM, transformTechnique);

    auto picking = std::make_shared<Graphic::Techniques::PickTechnique>();
    picking->setObjectId(button->getId());
    object->addTechnique(Graphic::Techniques::PICK, picking);
    button->setCanvas(_canvas);

    auto textTechnique = std::make_shared<Graphic::Techniques::TextTechnique>();
    textTechnique->setText(button->title);
    textTechnique->setWidth(_textW + 0.065*(_buttons.size()));
    textTechnique->setHeight(_textH);
    textTechnique->setColor(glm::vec3{1.0f});
    object->addTechnique(Graphic::Techniques::TEXT, textTechnique);

    _buttons.push_back(object);
}

void Gui::setTextSize(float textW, float textH) {
    _textW = textW;
    _textH = textH;
}

void Gui::clear() {
    _buttons.clear();
}
