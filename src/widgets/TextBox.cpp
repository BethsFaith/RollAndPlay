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
        _form->setTextPosition({position.x - scale.x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setProjection(float minX, float maxX, float minY, float maxY) {
        _form->setProjection(minX, maxX, minY, maxY);
    }

    void TextBox::setTransform(glm::vec2 position) {
        _form->setTransform(position);
        _form->setTextPosition({position.x - _form->getScale().x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setScale(glm::vec2 scale) {
        _form->setScale(scale);

        auto position = _form->getPosition();
        _form->setTextPosition({position.x - _form->getScale().x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setColor(Styles::Color color) {
        _form->setColor(getRGB(color));
    }

    void TextBox::setTextParams(const Styles::TextParams& text) {
        _form->setTextColor(getRGB(text.color));
        _form->setTextSize(text.size);
    }

    void TextBox::setTextColor(Styles::Color color) {
        _form->setTextColor(getRGB(color));
    }

    void TextBox::setText(const std::u16string& content) {
        _form->setText(content);
    }

    void TextBox::setTextSize(float size) {
        _form->setTextSize(size);
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
        setText(u"");
    }

    glm::vec2 TextBox::getScale() {
        return _form->getScale();
    }

    glm::vec2 TextBox::getPosition() {
        return _form->getPosition();
    }
}