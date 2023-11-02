//
// Created by VerOchka on 26.10.2023.
//

#include "ImageButton.hpp"

namespace Forms {
    ImageButton::ImageButton(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive)
    : Button(graphicPrimitive, FormType::TEXTURE_BUTTON) {}

    void ImageButton::init(glm::vec3 scale, glm::vec2 position, const Text &text, const std::string& texturePath,
                           int textureIndex) {
        _texture = std::make_shared<GraphicLib::Textures::Texture>("", texturePath);
        GraphicLib::Textures::load2d(*_texture,  {
                                    {.name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST},
                                     {.name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST},
                                     {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                                     {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                                     {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE}});

        auto textureTechnique = std::make_shared<GraphicLib::Techniques::TextureTechnique>();
        textureTechnique->setTexture(_texture);
        textureTechnique->setTextureIndex(textureIndex);

        _object.addTechnique(GraphicLib::Techniques::COLOR, textureTechnique);

        auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
        transformTechnique->enableScale(scale);
        transformTechnique->enableTransform({position, -0.1f});

        _object.addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        auto picking = std::make_shared<GraphicLib::Techniques::PickTechnique>();
        picking->setObjectId(id);

        _object.addTechnique(GraphicLib::Techniques::PICK, picking);

        auto textTechnique = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        textTechnique->setText(text.content);
        textTechnique->setHeight(position.y + scale.y/1.45);
        textTechnique->setWidth(position.x - scale.x / 2 + 0.01f);
        textTechnique->setColor(getRGB(text.color));

        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechnique);

//        _attachButton->init({scale.x*0.5, scale.y*0.2, 0.0f}, {position.x, position.y-2}, {
//                .content = "Прикрепить изображение",
//                .x = text.x,
//                .y = text.y - scale.y*10,
//        }, Color::GRAY);
//        _attachButton->setPressCallback([]{
//            std::cout << "attach" << std::endl;
//        });
    }

    void ImageButton::setImage(const std::string &texturePath) {
        _texture->setPath(texturePath);
        GraphicLib::Textures::load2d(*_texture,  {
                {.name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST},
                {.name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST},
                {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE}});
    }

//    const Button::Ptr &ImageButton::getAttachButton() const {
//        return _attachButton;
//    }

    void ImageButton::renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) {}
}