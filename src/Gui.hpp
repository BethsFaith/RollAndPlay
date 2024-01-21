//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_GUI_HPP
#define ROLLANDPLAY_GUI_HPP

#include <GraphicLib/GlagGlfw.hpp>
#include <GraphicLib/Shaders/ShaderProgram.hpp>

#include "config/Config.hpp"
#include "controllers/GuiController.hpp"
#include "forms/Button.hpp"
#include "forms/TextBox.hpp"

class Gui {
public:
    using Ptr = std::shared_ptr<Gui>;

    explicit Gui(GraphicLib::PickableTexture::Ptr canvas);

    ~Gui() = default;

    void draw();

    void addForm(const Forms::Form::Ptr& form);

    void clear();

    [[nodiscard]] const Controllers::GuiController::Ptr& getController() const;

    static void setColorShader(GraphicLib::Shaders::ShaderProgram::Ptr shader);
    static void setTextureShader(GraphicLib::Shaders::ShaderProgram::Ptr shader);
    static void setSelectableShader(GraphicLib::Shaders::ShaderProgram::Ptr shader);
    static void setTextShader(GraphicLib::Shaders::ShaderProgram::Ptr shader);

private:
    static GraphicLib::Shaders::ShaderProgram::Ptr colorShader;
    static GraphicLib::Shaders::ShaderProgram::Ptr textureShader;
    static GraphicLib::Shaders::ShaderProgram::Ptr selectableShader;
    static GraphicLib::Shaders::ShaderProgram::Ptr textShader;

    std::vector<Forms::Form::Ptr> _forms;
    GraphicLib::PickableTexture::Ptr _canvas;

    Controllers::GuiController::Ptr _controller;
};

#endif    //ROLLANDPLAY_GUI_HPP
