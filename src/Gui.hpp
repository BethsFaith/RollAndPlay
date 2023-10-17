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
    using Ptr = std::shared_ptr<Gui>;

    Gui();
    ~Gui() = default;

    void draw();

    void addButton(const Forms::Button::Ptr button, Graphic::AbstractPrimitive::Ptr primitive);
private:
    void setTransform(float x, float y);
    void setColor(float r, float g, float b);
    void setColor(glm::vec3 rgb);

    Graphic::Shaders::ShaderProgram::Ptr _shader;

    std::vector<std::pair<Forms::Button::Ptr, Graphic::AbstractPrimitive::Ptr>> _buttons;
};


#endif //ROLLANDPLAY_GUI_HPP
