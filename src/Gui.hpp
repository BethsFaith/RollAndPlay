//
// Created by VerOchka on 10.10.2023.
//

#ifndef ROLLANDPLAY_GUI_HPP
#define ROLLANDPLAY_GUI_HPP

#include "forms/Button.hpp"
#include "graphic/AbstractPrimitive.hpp"
#include "graphic/shaders/ShaderProgram.hpp"

class Gui {
public:
    Gui();
    ~Gui();

    void draw();

    void addButton(const Forms::Button& button, Graphic::AbstractPrimitive* primitive);
private:
    void setTransform(float x, float y);
    void setColor(float r, float g, float b);
    void setColor(glm::vec3 rgb);

    Graphic::Shaders::ShaderProgram* _shader;

    std::vector<std::pair<Forms::Button, Graphic::AbstractPrimitive*>> _buttons;
};


#endif //ROLLANDPLAY_GUI_HPP
