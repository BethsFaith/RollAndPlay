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

        _form = std::make_unique<Graphic::Form>(rectangle);
    }

    void TextBox::setTransform(glm::vec2 position, glm::vec2 scale) {
        _form->setTransform(position, scale);
    }

    void TextBox::setTransform(glm::vec2 position) {
        _form->setTransform(position);
    }

    void TextBox::setScale(glm::vec2 scale) {
        _form->setScale(scale);
    }

    void TextBox::setColor(Color color) {
        _form->setColor(getRGB(color));
    }

    void TextBox::setTextForm(const TextData& text) {
        _form->setText(text.content, getRGB(text.color));
    }

    void TextBox::setTextColor(Color color) {
        _form->setTextColor(getRGB(color));
    }

    void TextBox::setText(const std::u16string& content) {
        _form->setText(content);
    }

    void TextBox::setTextScale(float scale) {
        _form->setTextScale(scale);
    }

    void TextBox::draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                       GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                       GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        _form->renderForm(formShader);
        _form->renderText(textShader);
    }

    bool TextBox::checkSelecting(unsigned int x, unsigned int y) {
        return false;
    }

    void TextBox::clear() {
        setTextForm({.content = u""});
    }

    glm::vec2 TextBox::getScale() {
        return _form->getScale();
    }

    glm::vec2 TextBox::getPosition() {
        return _form->getPosition();
    }
}