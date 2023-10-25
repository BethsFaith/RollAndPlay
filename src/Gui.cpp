//
// Created by VerOchka on 10.10.2023.
//

#include "Gui.hpp"

Gui::Gui(unsigned int windowWidth, unsigned int windowHeight) {
    Graphic::Techniques::TextTechnique::initTextRendering(windowWidth, windowHeight,
                                                          R"(..\..\rsrc\fonts\a_AlternaSw.TTF)", 24);

    _shader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
        (R"(..\..\rsrc\shaders\gui.vert)",
         R"(..\..\rsrc\shaders\gui.frag)");
    _selectableShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\gui.vert)",
             R"(..\..\rsrc\shaders\select.frag)");
    _textShader = std::make_shared<GraphicLib::Shaders::ShaderProgram>
            (R"(..\..\rsrc\shaders\text2d.vert)",
             R"(..\..\rsrc\shaders\text2d.frag)");

    _canvas = std::make_shared<GraphicLib::PickableTexture>();
    _canvas->init(windowWidth, windowHeight);
}

Gui::~Gui() {
    Graphic::Techniques::TextTechnique::freeTextRendering();
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
                                                  button->getYOffset(), 0.0f));
    transformTechnique->disableRotateValue();
    object->addTechnique(Graphic::Techniques::TRANSFORM, transformTechnique);

    auto picking = std::make_shared<Graphic::Techniques::PickTechnique>();
    picking->setObjectId(button->getId());
    object->addTechnique(Graphic::Techniques::PICK, picking);
    button->setCanvas(_canvas);

    auto textTechnique = std::make_shared<Graphic::Techniques::TextTechnique>();
    textTechnique->setText(button->text);
    textTechnique->setWidth(0.05 + 0.065*(_buttons.size()));
    textTechnique->setHeight(0.05);
    textTechnique->setColor(glm::vec3{1.0f});
    object->addTechnique(Graphic::Techniques::TEXT, textTechnique);

    _buttons.push_back(object);
}
