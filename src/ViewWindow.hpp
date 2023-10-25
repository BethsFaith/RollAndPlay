//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_VIEWWINDOW_HPP
#define ROLLANDPLAY_VIEWWINDOW_HPP

#include <primitives/Rectangle.hpp>
#include <shaders/ShaderProgram.hpp>

#include "forms/Page.hpp"
#include "forms/Color.hpp"
#include "graphic/Object.hpp"
#include "graphic/techniques/ColorTechnique.hpp"
#include "graphic/techniques/PickTechnique.hpp"
#include "graphic/techniques/TransformTechnique.hpp"
#include "graphic/techniques/TextTechnique.hpp"

class ViewWindow {
public:
    using Ptr = std::shared_ptr<ViewWindow>;

    ViewWindow(int x, int y, Forms::Color viewColor);
    ~ViewWindow() = default;

    void display();
private:
    Graphic::Object _view;
    GraphicLib::Shaders::ShaderProgram::Ptr _shader;
    // pages
};

#endif //ROLLANDPLAY_VIEWWINDOW_HPP
