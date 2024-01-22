//
// Created by VerOchka on 06.01.2024.
//

#include "TextBox.hpp"

namespace Widgets {
    TextBox::TextBox() : Widget(WidgetType::TEXT_BOX) {
        GraphicLib::Primitives::AbstractPrimitive::Ptr rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);
        _object.setPrimitive(rectangle);
    }

    void TextBox::init(glm::vec3 scale, glm::vec2 position, const TextData&text, Color color) {
        auto colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
        colorTechnique->setColor(getRGB(color));

        _object.addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);

        auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
        transformTechnique->enableScale(scale);
        transformTechnique->enableTransform({position, -0.1f});

        _object.addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        auto textTechnique = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        textTechnique->setText(text.content);
        textTechnique->setWidth(position.x - scale.x / 2 + 0.01f);
        textTechnique->setHeight(position.y);
        textTechnique->setColor(getRGB(text.color));
//        textTechnique->setScale(scale.x * 1.5);

        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechnique);
    }

    void TextBox::renderText(const GraphicLib::Shaders::ShaderProgram::Ptr& shader) {
        _object.disableTechnique(GraphicLib::Techniques::COLOR);
        _object.disableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object.enableTechnique(GraphicLib::Techniques::TEXT);

        _object.render(shader);
    }

    void TextBox::renderForm(const GraphicLib::Shaders::ShaderProgram::Ptr& shader) {
        _object.enableTechnique(GraphicLib::Techniques::COLOR);
        _object.enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object.disableTechnique(GraphicLib::Techniques::TEXT);

        _object.render(shader);
    }

    bool TextBox::checkSelecting(unsigned int x, unsigned int y) {
        return false;
    }

    void TextBox::setTextForm(const TextData& text) {
        auto technique = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(technique);

        textTechnique->setText(text.content);
        textTechnique->setColor(getRGB(text.color));
    }

    void TextBox::setTextColor(Color color) {
        auto technique = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(technique);

        textTechnique->setColor(getRGB(color));
    }

    void TextBox::setText(const std::u16string& content) {
        auto technique = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(technique);

        textTechnique->setText(content);
    }


    void TextBox::setTextScale(float scale) {
        auto technique = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(technique);

        textTechnique->setScale(scale);
    }


    void TextBox::clear() {
        setTextForm({.content = u""});
    }
}