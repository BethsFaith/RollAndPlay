//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

#include <utility>

namespace Forms {
    InputField::InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams)
            : Button(graphicPrimitive, FormType::INPUT_FIELD), _buf(std::move(inputParams)) {}

    const std::u16string & InputField::getBuf() const {
        return _buf.content;
    }

    void InputField::init(glm::vec3 scale, glm::vec2 position, const Text &text, Color color) {
        _position = position;
        _scale = scale;

        auto colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
        colorTechnique->setColor(getRGB(color));

        _object.addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);

        auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
        transformTechnique->enableScale(scale);
        transformTechnique->enableTransform({position, -0.1f});

        _object.addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        auto picking = std::make_shared<GraphicLib::Techniques::PickTechnique>();
        picking->setObjectId((float)id);

        _object.addTechnique(GraphicLib::Techniques::PICK, picking);

        auto textTechnique = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        textTechnique->setText(text.content);
        textTechnique->setHeight(position.y + scale.y);
        textTechnique->setWidth(position.x - scale.x/2 + 0.01f);
        textTechnique->setColor(getRGB(text.color));

        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechnique);

        // каретка
        _carriage.init(Color::BLACK, {scale.x * 0.005f, scale.y * 0.5f, 0},
                       {position.x - scale.x/2 + 0.01f, position.y - scale.y/10, -0.2f},
                       _inputTextSize);
        _carriage.hide();
    }

    std::string InputField::getU8Buf() const {
        std::string str8(_buf.content.begin(), _buf.content.end());
        return str8;
    }

    void InputField::putToBuffer(char16_t character) {
        _buf.content.push_back(character);

        auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
        if (textRender != nullptr) {
            auto ch = textRender->getCharacter(character);
            _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
        }
        _carriage.move(1);
    }

    void InputField::putToBuffer(char16_t character, unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.insert(position, 1, character);

            auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
            if (textRender != nullptr) {
                auto ch = textRender->getCharacter(character);
                _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
            }
        }
        _carriage.move(1);
    }

    void InputField::putToBuffer(const std::string &string) {
        std::u16string str(string.begin(), string.end());
        _buf.content.append(str);

        auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
        if (textRender != nullptr) {
            for (const auto& code : string) {
                auto ch = textRender->getCharacter(code);
                _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
            }
        }
        _carriage.move(1);
    }

    void InputField::putToBuffer(const std::string &string, unsigned int position) {
        if (position < _buf.content.size()) {
            std::u16string str(string.begin(), string.end());

            _buf.content.insert(position, str);

            auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
            if (textRender != nullptr) {
                for (const auto& code : string) {
                    auto ch = textRender->getCharacter(code);
                    _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
                }
            }
        }
        _carriage.move(1);
    }

    void InputField::putToBuffer(const std::u16string &string) {
        _buf.content.append(string);

        auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
        if (textRender != nullptr) {
            for (const auto& code : string) {
                auto ch = textRender->getCharacter(code);
                _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
            }
        }
        _carriage.move((int)string.size()-1);
    }

    void InputField::putToBuffer(const std::u16string &string, unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.insert(position, string);

            auto textRender = GraphicLib::Techniques::TextTechnique::getTextRenderer();
            if (textRender != nullptr) {
                for (const auto& code : string) {
                    auto ch = textRender->getCharacter(code);
                    _carriage.addCharacterData({.bearing = ch.bearing, .advance = ch.advance});
                }
            }
        }
        _carriage.move((int)string.size()-1);
    }

    void InputField::popFromBuffer() {
        if (!_buf.content.empty()) {
            _buf.content.erase(_buf.content.size()-1);

            _carriage.move(-1);

            _carriage.releaseBackCharacterData();
        }
    }

    void InputField::popFromBuffer(unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.erase(position);

            _carriage.move(-1);

            _carriage.releaseBackCharacterData();
        }
    }

    void InputField::clear() {
        _carriage.move(-(int)_buf.content.size()+1);

        _carriage.clearAllCharacterData();

        _buf.content.clear();
    }

    void InputField::renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        Button::renderForm(shader);
        _carriage.render(shader);
    }

    void InputField::renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        // рисуем (тайтл)
        Button::renderText(shader);

        // меняем текст описания кнопки на текст инпута
        auto techn = _object.getTechnique(GraphicLib::Techniques::TEXT);
        auto textTechn = std::dynamic_pointer_cast<GraphicLib::Techniques::TextTechnique>(techn);

        auto newTextTechn = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        newTextTechn->setText(_buf.content);
        newTextTechn->setWidth(_position.x - _scale.x/2 + 0.01f);
        newTextTechn->setHeight(_position.y);
        newTextTechn->setColor(getRGB(_buf.color));
        newTextTechn->setScale(1.4);

        _object.addTechnique(GraphicLib::Techniques::TEXT, newTextTechn);

        // рисуем буффер
        _object.render(shader);

        // возвращаем прошлое
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
        trans->enableScale({scale.x * 1.02f, scale.y * 1.1f, scale.z});
        trans->enableTransform(offset);

        renderForm(shader);

        trace->setColor(baseColor);
        trans->enableScale(scale);
        trans->enableTransform(offset);
    }

    void InputField::press() {
        setUnderCursor(true);

        _carriage.show();

        Button::press();
    }

    void InputField::release() {
        setUnderCursor(false);

        _carriage.hide();

        Button::release();
    }
}
