//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_GUI_HPP
#define ROLLANDPLAY_GUI_HPP

#include <primitives/AbstractPrimitive.hpp>
#include <shaders/ShaderProgram.hpp>

#include "forms/Button.hpp"
#include "graphic/Object.hpp"
#include "graphic/techniques/ColorTechnique.hpp"
#include "graphic/techniques/PickTechnique.hpp"
#include "graphic/techniques/TransformTechnique.hpp"
#include "graphic/techniques/TextTechnique.hpp"

class Gui {
public:
    using Ptr = std::shared_ptr<Gui>;

    Gui(const GraphicLib::PickableTexture::Ptr canvas);
    ~Gui() = default;

    void draw();

    void addButton(const Forms::Button::Ptr button, GraphicLib::Primitives::AbstractPrimitive::Ptr primitive);

    void setTextSize(float textW, float textH);

    void clear();

private:
    GraphicLib::Shaders::ShaderProgram::Ptr _shader;
    GraphicLib::Shaders::ShaderProgram::Ptr _selectableShader;
    GraphicLib::Shaders::ShaderProgram::Ptr _textShader;

    std::vector<Graphic::Object::Ptr> _buttons;
    GraphicLib::PickableTexture::Ptr _canvas;

    float _textW;
    float _textH;
};


#endif //ROLLANDPLAY_GUI_HPP
