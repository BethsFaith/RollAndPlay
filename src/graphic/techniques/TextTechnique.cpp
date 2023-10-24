//
// Created by VerOchka on 24.10.2023.
//

#include "TextTechnique.hpp"

namespace Graphic::Techniques {
    GraphicLib::Text::Ptr TextTechnique::TextRenderer = nullptr;
    glm::mat4 TextTechnique::Projection = {};
    unsigned int TextTechnique::ScreenWidth = 3440;
    unsigned int TextTechnique::ScreenHeight = 1440;

    void TextTechnique::initTextRendering(unsigned int width, unsigned int height, std::string font, int size) {
        TextRenderer = std::make_shared<GraphicLib::Text>(width, height);
        TextRenderer->load(font, size);

        Projection = glm::ortho(0.0f, static_cast<float>(width),
                                               static_cast<float>(height), 0.0f);
        ScreenWidth = width;
        ScreenHeight = height;
    }

    void TextTechnique::execute() {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        shader->set4FloatMat("Projection", glm::value_ptr(Projection));

        shader->setInt("Text", 0);
        shader->set3FloatVector("TextColor", _color);

        TextRenderer->render(_text, _width, _height, _scale, _color);

        glBlendFunc(GL_ONE, GL_ZERO);
        glDisable(GL_BLEND);
    }

    void TextTechnique::setText(const std::string &text) {
        _text = text;
    }

    void TextTechnique::setColor(const glm::vec3 &color) {
        _color = color;
    }

    void TextTechnique::setWidth(float width) {
        _width = ScreenWidth*width;
    }

    void TextTechnique::setHeight(float height) {
        _height = ScreenHeight * height;
    }

    void TextTechnique::setScale(float scale) {
        _scale = scale;
    }

    void TextTechnique::freeTextRendering() {
        TextRenderer.reset();
    }
}
