//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

namespace Forms {
    InputField::InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams)
    : Button(graphicPrimitive, FormType::INPUT_FIELD), _buf(std::move(inputParams)) {}

    const std::string &InputField::getBuf() const {
        return _buf.content;
    }

    void InputField::putToBuffer(char character) {
        _buf.content += character;
    }

    void InputField::popFromBuffer() {
        if (!_buf.content.empty()) {
//            _buf.content.erase(_buf.content.back());
        }
    }

    void InputField::clear() {
        _buf.content.clear();
    }

    void InputField::renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        // рисуем (тайтл)
        Button::renderText(shader);

        // меняем параметры
        auto techn = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechn = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(techn);

        // сохраняем прошлые (параметры тайтла)
        Text text = {textTechn->getText(), textTechn->getWidth(), textTechn->getHeight()};
        auto color = textTechn->getColor();

        // ставим новые (параметры буффера)
        textTechn->setColor(getRGB(_buf.color));
        textTechn->setWidth(_buf.x);
        textTechn->setHeight(_buf.y);
        textTechn->setText(_buf.content);

        // рисуем буффер
        Button::renderText(shader);

        // возвращаем прошлые
        textTechn->setColor(color);
        textTechn->setWidth(text.x);
        textTechn->setHeight(text.y);
        textTechn->setText(text.content);
    }
}
