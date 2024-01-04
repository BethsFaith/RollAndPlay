//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

#include <utility>

namespace Forms {
    InputField::InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams)
            : Button(graphicPrimitive, FormType::INPUT_FIELD), _buf(std::move(inputParams)) {
        _carriage = std::make_shared<GraphicLib::Object>();
        auto rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);
        _carriage->setPrimitive(rectangle);
    }

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
        picking->setObjectId(id);

        _object.addTechnique(GraphicLib::Techniques::PICK, picking);

        auto textTechnique = std::make_shared<GraphicLib::Techniques::TextTechnique>();
        textTechnique->setText(text.content);
        textTechnique->setHeight(position.y + scale.y);
        textTechnique->setWidth(position.x - scale.x/2 + 0.01f);
        textTechnique->setColor(getRGB(text.color));

        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechnique);

        // каретка
        colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
        colorTechnique->setColor(getRGB(BLACK));
        _carriage->addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);
        _carriage->enableTechnique(GraphicLib::Techniques::COLOR);

        transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
        transformTechnique->enableScale({scale.x * 0.005f, scale.y * 0.5f, 0});
        transformTechnique->enableTransform({position.x - scale.x/2 + 0.01f, position.y - scale.y/10, -0.2f});
        _carriage->addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        disableCarriage();
    }

    std::string InputField::getU8Buf() const {
        std::string str8(_buf.content.begin(), _buf.content.end());
        return str8;
    }

    void InputField::putToBuffer(char16_t character) {
        _buf.content.push_back(character);
        moveCarriage(1);
    }

    void InputField::putToBuffer(char16_t character, unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.insert(position, 1, character);
        }
        moveCarriage(1);
    }

    void InputField::putToBuffer(const std::string &string) {
        std::u16string str(string.begin(), string.end());
        _buf.content.append(str);
        moveCarriage(1);
    }

    void InputField::putToBuffer(const std::string &string, unsigned int position) {
        if (position < _buf.content.size()) {
            std::u16string str(string.begin(), string.end());
            _buf.content.insert(position, str);
        }
        moveCarriage(1);
    }

    void InputField::putToBuffer(const std::u16string &string) {
        _buf.content.append(string);
        moveCarriage(string.size());
    }

    void InputField::putToBuffer(const std::u16string &string, unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.insert(position, string);
        }
        moveCarriage(string.size());
    }

    void InputField::popFromBuffer() {
        if (!_buf.content.empty()) {
            _buf.content.erase(_buf.content.size()-1);
            moveCarriage(-1);
        }
    }

    void InputField::popFromBuffer(unsigned int position) {
        if (position < _buf.content.size()) {
            _buf.content.erase(position);
            moveCarriage(-1);
        }
    }

    void InputField::clear() {
        moveCarriage(-_buf.content.size());
        _buf.content.clear();
    }

    void InputField::moveCarriage(float xOffset) {
        auto technique = _carriage->getTechnique(GraphicLib::Techniques::TRANSFORM);
        auto transformTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TransformTechnique>(technique);
        auto transform = transformTechnique->getTransformValue();
        transformTechnique->setTransformValue({transform.x + 0.005 * xOffset, transform.y, transform.z});
    }

    void InputField::renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        Button::renderForm(shader);
        renderCarriage(shader);
    }

    void InputField::renderCarriage(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        _carriage->render(std::move(shader));
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
        enableCarriage();
        Button::press();
    }

    void InputField::release() {
        setUnderCursor(false);
        disableCarriage();
        Button::release();
    }

    void InputField::enableCarriage() {
        _carriage->enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _carriage->enableTechnique(GraphicLib::Techniques::COLOR);
    }

    void InputField::disableCarriage() {
        _carriage->disableTechnique(GraphicLib::Techniques::TRANSFORM);
        _carriage->disableTechnique(GraphicLib::Techniques::COLOR);
    }
}
