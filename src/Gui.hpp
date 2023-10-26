//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_GUI_HPP
#define ROLLANDPLAY_GUI_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Shaders/ShaderProgram.hpp>

#include "forms/Button.hpp"
#include "controllers/GuiController.hpp"

class Gui {
public:
    using Ptr = std::shared_ptr<Gui>;

    explicit Gui(GraphicLib::PickableTexture::Ptr  canvas);

    ~Gui() = default;

    void draw();

    void addButton(const Forms::Button::Ptr& button);

    void clear();

    [[nodiscard]] const Controllers::GuiController::Ptr &getController() const;

private:
    GraphicLib::Shaders::ShaderProgram::Ptr _colorShader;
    GraphicLib::Shaders::ShaderProgram::Ptr _textureShader;
    GraphicLib::Shaders::ShaderProgram::Ptr _selectableShader;
    GraphicLib::Shaders::ShaderProgram::Ptr _textShader;

    std::vector<Forms::Button::Ptr> _buttons;
    GraphicLib::PickableTexture::Ptr _canvas;

    Controllers::GuiController::Ptr _controller;
};


#endif //ROLLANDPLAY_GUI_HPP
