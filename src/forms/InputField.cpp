//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

namespace Forms {
    InputField::InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams)
            : Button(graphicPrimitive, FormType::INPUT_FIELD), _buf(std::move(inputParams)) {}

    std::string InputField::getBuf() const {
        std::string str8(_buf.content.begin(), _buf.content.end());
        return str8;
    }

    void InputField::putToBuffer(char16_t character) {
        _buf.content.push_back(character);
    }

    void InputField::putToBuffer(const std::string &string) {
        std::u16string str(string.begin(), string.end());
        _buf.content.append(str);
    }

    void InputField::popFromBuffer() {
        if (!_buf.content.empty()) {
            _buf.content.erase(_buf.content.size()-1);
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

        auto newTextTechn = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        newTextTechn->setText(_buf.content);
        newTextTechn->setWidth(_buf.x);
        newTextTechn->setHeight(_buf.y);
        newTextTechn->setColor(getRGB(_buf.color));
        newTextTechn->setScale(1.4);

        _object.addTechnique(GraphicLib::Techniques::TEXT, newTextTechn);

        // рисуем буффер
        _object.render(shader);

        // возвращаем прошлые
        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechn);
    }

    void InputField::renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        // нарисовать обводку;
        auto techn = _object.getTechnique(GraphicLib::Techniques::COLOR);
        auto trace = std::dynamic_pointer_cast<GraphicLib::Techniques::ColorTechnique>(techn);
        auto baseColor = trace->getRgb();
        trace->setColor(getRGB(_traceColor));

        techn = _object.getTechnique(GraphicLib::Techniques::TRANSFORM);
        auto trans = std::dynamic_pointer_cast<GraphicLib::Techniques::TransformTechnique>(techn);
        auto scale = trans->getScaleValue();
        auto offset = trans->getTransformValue();
        trans->enableScale({scale.x * 1.02, scale.y * 1.1, scale.z});
        trans->enableTransform({offset.x * 0.98, offset.y * 0.909, offset.z});

        renderForm(shader);

        trace->setColor(baseColor);
        trans->enableScale(scale);
        trans->enableTransform(offset);
    }
}
