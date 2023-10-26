//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_GUI_HPP
#define ROLLANDPLAY_GUI_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Primitives/AbstractPrimitive.hpp>
#include <GraphicLib/Shaders/ShaderProgram.hpp>
#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/PickTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <GraphicLib/Techniques/TextTechnique.hpp>

#include "forms/Button.hpp"

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

    std::vector<GraphicLib::Object::Ptr> _buttons;
    GraphicLib::PickableTexture::Ptr _canvas;

    float _textW;
    float _textH;
};


#endif //ROLLANDPLAY_GUI_HPP
