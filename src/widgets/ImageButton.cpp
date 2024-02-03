//
// Created by VerOchka on 26.10.2023.
//

#include "ImageButton.hpp"

namespace Widgets {
    ImageButton::ImageButton(GraphicLib::Primitives::AbstractPrimitive::Ptr graphicPrimitive)
        : Button(graphicPrimitive, WidgetType::IMAGE_BUTTON) {}

    void ImageButton::setImage(const std::string& texturePath, int textureIndex) {
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

    void ImageButton::draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                           GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                           GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        Button::draw(formShader, textShader, pickShader);
    }

    void ImageButton::updateTextPosition(glm::vec2 position, glm::vec2 scale) {
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y / 1.45});
    }

    void ImageButton::setColor(Styles::Color color) {}
}    //namespace Forms
