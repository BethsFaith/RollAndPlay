//
// Created by VerOchka on 23.10.2023.
//

#include "../../headers/GraphicLib/Techniques/ColorTechnique.hpp"

namespace GraphicLib::Techniques {
    void ColorTechnique::execute() {
        shader->set3FloatVector("Color", _rgb);
    }

    void ColorTechnique::setColor(float r, float g, float b) {
        _rgb = glm::vec3(r,g,b);
    }

    void ColorTechnique::setColor(glm::vec3 rgb) {
        _rgb = rgb;
    }

    const glm::vec3 &ColorTechnique::getRgb() const {
        return _rgb;
    }
} // Techniques