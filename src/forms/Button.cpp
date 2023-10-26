//
// Created by VerOchka on 06.10.2023.
//

#include "Button.hpp"
#include "Text.hpp"

namespace Forms {
    int Button::IdCounter = 0;

    Button::Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive)
    : Button(graphicPrimitive, FormType::BUTTON){}

    Button::Button(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, FormType type)
    : Form(type) {
        id = ++IdCounter;

        _object.setPrimitive(graphicPrimitive);
    }

    void Button::init(glm::vec3 scale, glm::vec2 position, const Text &text, Color color) {
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
        textTechnique->setWidth(text.x);
        textTechnique->setHeight(text.y);
        textTechnique->setColor(getRGB(text.color));

        _object.addTechnique(GraphicLib::Techniques::TEXT, textTechnique);
    }

    void Button::renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        _object.disableTechnique(GraphicLib::Techniques::PICK);
        _object.enableTechnique(GraphicLib::Techniques::COLOR);
        _object.enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object.disableTechnique(GraphicLib::Techniques::TEXT);

        _object.render(std::move(shader));
    }

    void Button::renderPick(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        canvas->enableWriting();

        _object.disableTechnique(GraphicLib::Techniques::COLOR);
        _object.enableTechnique(GraphicLib::Techniques::PICK);
        _object.enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object.disableTechnique(GraphicLib::Techniques::TEXT);

        _object.render(std::move(shader));

        canvas->disableWriting();
    }

    void Button::renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        _object.disableTechnique(GraphicLib::Techniques::PICK);
        _object.disableTechnique(GraphicLib::Techniques::COLOR);
        _object.disableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object.enableTechnique(GraphicLib::Techniques::TEXT);

        _object.render(std::move(shader));
    }

    void Button::renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        // нарисовать обводку;
        auto techn = _object.getTechnique(GraphicLib::Techniques::COLOR);
        auto trace = std::dynamic_pointer_cast<GraphicLib::Techniques::ColorTechnique>(techn);
        auto baseColor = trace->getRgb();
        trace->setColor(getRGB(_traceColor));

        techn = _object.getTechnique(GraphicLib::Techniques::TRANSFORM);
        auto trans = std::dynamic_pointer_cast<GraphicLib::Techniques::TransformTechnique>(techn);
        auto scale = trans->getScaleValue();
        auto offset = trans->getTransformValue();
        trans->enableScale({scale.x*1.1, scale.y*1.1, scale.z});
        trans->enableTransform({offset.x*0.909, offset.y*0.909, offset.z});

        renderForm(shader);

        trace->setColor(baseColor);
        trans->enableScale(scale);
        trans->enableTransform(offset);
    }

    void Button::press() {
        _pressCallback();
    }

    bool Button::isSelected() const {
        return _isSelected;
    }

    bool Button::checkSelecting(unsigned int x, unsigned int y) {
        if (canvas == nullptr) {
            return false;
        }

        auto info = canvas->readPixel(x, y);

        return id == (int) info.ObjectID;
    }

    void Button::setSelected(bool isSelected) {
        _isSelected = isSelected;
    }

    void Button::setPressCallback(const std::function<void()> &function) {
        _pressCallback = function;
    }

    void Button::setTraceColor(Color traceColor) {
        _traceColor = traceColor;
    }
}