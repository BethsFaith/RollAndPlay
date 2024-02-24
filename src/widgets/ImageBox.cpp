//
// Created by BethsFaith on 08.02.2024.
//

#include "ImageBox.hpp"

namespace Widgets {
    ImageBox::ImageBox(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive) : Widget(IMAGE_BOX),
          _form(graphicPrimitive) {}

    bool ImageBox::checkSelecting(unsigned int x, unsigned int y) {
        return false;
    }

    void ImageBox::draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                        GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                        GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                        GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        _form.renderForm(textureShader);
        _form.renderText(textShader);
    }

    void ImageBox::setProjection(float minX, float maxX, float minY, float maxY) {
        _form.setProjection(minX, maxX, minY, maxY);
    }

    void ImageBox::setTransform(glm::vec2 position, glm::vec2 scale) {
        _form.setTransform(position, scale);
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y * 0.7});
    }

    void ImageBox::setTransform(glm::vec2 position) {
        auto scale = _form.getScale();

        _form.setTransform(position);
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y * 0.7});
    }

    void ImageBox::setScale(glm::vec2 scale) {
        _form.setScale(scale);
    }

    void ImageBox::setImage(const std::string& texturePath, int textureIndex) {
        _texture = std::make_shared<GraphicLib::Textures::Texture>("", texturePath);
        GraphicLib::Textures::load2d(*_texture,
                                     {{.name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST},
                                      {.name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST},
                                      {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                                      {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                                      {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE}});
        _texture->setPath(texturePath);

        _form.setTexture(_texture, textureIndex);
    }

    glm::vec2 ImageBox::getScale() {
        auto scale = _form.getScale();
        if (!_form.getText().empty()) {
            scale.y += 0.03;
        }
        return scale;
    }

    glm::vec2 ImageBox::getPosition() {
        return _form.getPosition();
    }

    const GraphicLib::Textures::Texture::Ptr& ImageBox::getTexture() const {
        return _texture;
    }

    void ImageBox::setLabelParams(const Styles::TextParams& text) {
        _form.setTextColor(getRGB(text.color));
        _form.setTextPosition(text.position);
        _form.setTextSize(text.size);
    }

    void ImageBox::setLabelText(const std::u16string& text) {\
        _form.setText(text);
    }

    void ImageBox::setLabelPosition(glm::vec2 position) {
        _form.setTextPosition(position);
    }

    void ImageBox::setLabelColor(Styles::Color color) {
        _form.setTextColor(getRGB(color));
    }

    void ImageBox::setLabelTextSize(float size) {
        _form.setTextSize(size);
    }
}    //namespace Widgets
