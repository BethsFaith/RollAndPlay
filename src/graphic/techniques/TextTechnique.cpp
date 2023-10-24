//
// Created by VerOchka on 24.10.2023.
//

#include "TextTechnique.hpp"

namespace Graphic::Techniques {
    GraphicLib::Text::Ptr TextTechnique::TextRenderer = nullptr;
    glm::mat4 TextTechnique::Projection = {};

    void TextTechnique::initTextRendering(unsigned int width, unsigned int height, std::string font, int size) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        TextRenderer = std::make_shared<GraphicLib::Text>(width, height);
        TextRenderer->load(font, size);

        Projection = glm::ortho(0.0f, static_cast<float>(width),
                                               static_cast<float>(height), 0.0f);
    }

    void TextTechnique::execute() {
        shader->set4FloatMat("Projection", glm::value_ptr(Projection));
        shader->setInt("Text", 0);
        shader->set3FloatVector("TextColor", _color);

        TextRenderer->render(_text, _width, _height, _scale, _color);
    }

    void TextTechnique::setText(const std::string &text) {
        _text = text;
    }

    void TextTechnique::setColor(const glm::vec3 &color) {
        _color = color;
    }

    void TextTechnique::setWidth(float width) {
        _width = width;
    }

    void TextTechnique::setHeight(float height) {
        _height = height;
    }

    void TextTechnique::setScale(float scale) {
        _scale = scale;
    }

    void TextTechnique::freeTextRendering() {
        TextRenderer.reset();
    }
}
