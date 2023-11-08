//
// Created by VerOchka on 24.10.2023.
//

#include "../../headers/GraphicLib/Techniques/TextTechnique.hpp"

namespace GraphicLib::Techniques {
    GraphicLib::TextRender::Ptr TextTechnique::TextRenderer = nullptr;
    glm::mat4 TextTechnique::Projection = {};
    unsigned int TextTechnique::ScreenWidth = 1440;
    unsigned int TextTechnique::ScreenHeight = 720;

    void TextTechnique::initTextRendering(unsigned int width, unsigned int height, std::string font, int size) {
        TextRenderer = std::make_shared<GraphicLib::TextRender>(width, height);
        TextRenderer->load(font, size);

        Projection = glm::ortho(0.0f, static_cast<float>(width),
                                               static_cast<float>(height), 0.0f);
        ScreenWidth = width;
        ScreenHeight = height;
    }

    void TextTechnique::execute() {
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        shader->set4FloatMat("Projection", glm::value_ptr(Projection));

        shader->setInt("Text", 0);
        shader->set3FloatVector("TextColor", _color);

        TextRenderer->render(_text, _width, _height, _scale, _color);

        glBlendFunc(GL_ONE, GL_ZERO);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
    }

    void TextTechnique::setText(const std::u16string &text) {
        _text = text;
    }

    void TextTechnique::setColor(const glm::vec3 &color) {
        _color = color;
    }

    void TextTechnique::setWidth(float width) {
        auto screen = ScreenWidth/2;
        _width = screen + width * screen;
    }

    void TextTechnique::setHeight(float height) {
        auto screen = ScreenHeight/2;
        _height = screen - height * screen;
    }

    void TextTechnique::setScale(float scale) {
        _scale = scale;
    }

    void TextTechnique::freeTextRendering() {
        TextRenderer.reset();
    }

    const std::u16string &TextTechnique::getText() const {
        return _text;
    }

    const glm::vec3 &TextTechnique::getColor() const {
        return _color;
    }

    float TextTechnique::getScale() const {
        return _scale;
    }

    float TextTechnique::getWidth() const {
        return (_width - ScreenWidth/2);
    }

    float TextTechnique::getHeight() const {
        return (_height + ScreenHeight/2);
    }
}
