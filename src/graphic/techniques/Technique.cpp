//
// Created by VerOchka on 23.10.2023.
//

#include "Technique.hpp"

namespace Graphic::Techniques {
    void Technique::setShader(GraphicLib::Shaders::ShaderProgram::Ptr shaderProgram) {
        shader = std::move(shaderProgram);
    }

    void Technique::enable() {
        enabled = true;
    }

    void Technique::disable() {
        enabled = false;
    }

    bool Technique::isEnabled() const {
        return enabled;
    }
}