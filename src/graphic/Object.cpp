//
// Created by VerOchka on 23.10.2023.
//

#include "Object.hpp"

namespace Graphic {
    void Object::render(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        shader->use();

        for (const auto& pair : techniques) {
            auto technique = pair.second;
            if (technique->isEnabled()) {
                technique->setShader(shader);
                technique->execute();
            }
        }

        _primitive->draw();
    }

    void Object::addTechnique(Techniques::TechniqueName name, Techniques::Technique::Ptr technique) {
        techniques[name] = std::move(technique);
    }

    void Object::removeTechnique(Techniques::TechniqueName name) {
        techniques.erase(name);
    }

    void Object::enableTechnique(Techniques::TechniqueName name) {
        techniques[name]->enable();
    }

    void Object::disableTechnique(Techniques::TechniqueName name) {
        techniques[name]->disable();
    }

    Techniques::Technique::Ptr Object::getTechnique(Techniques::TechniqueName name) {
        return techniques[name];
    }

    void Object::setPrimitive(const GraphicLib::Primitives::AbstractPrimitive::Ptr &primitive) {
        _primitive = primitive;
    }
}