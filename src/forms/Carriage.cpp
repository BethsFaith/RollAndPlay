//
// Created by VerOchka on 05.01.2024.
//

#include "Carriage.hpp"

namespace Forms {
    Carriage::Carriage() {
        _object = std::make_shared<GraphicLib::Object>();

        auto rectangle =
                std::make_shared<GraphicLib::Primitives::Rectangle>(
                        GraphicLib::Primitives::Primitive::Settings{.with_normals = false,
                                .with_texture_coords = false,
                                .with_tangent = false,
                                .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        _object->setPrimitive(rectangle);
    }

    void Carriage::init(Color color, const glm::vec3 &scale, const glm::vec3 &position, float textSize) {
        auto colorTechnique = std::make_shared<GraphicLib::Techniques::ColorTechnique>();
        colorTechnique->setColor(getRGB(color));
        _object->addTechnique(GraphicLib::Techniques::COLOR, colorTechnique);

        auto transformTechnique = std::make_shared<GraphicLib::Techniques::TransformTechnique>();
        transformTechnique->enableScale(scale); // scale.x * 0.005f, scale.y * 0.5f, 0}
        transformTechnique->enableTransform(position);
        _object->addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        _textSize = textSize;
    }

    void Carriage::render(const GraphicLib::Shaders::ShaderProgram::Ptr& shader) {
        _object->render(shader);
    }

    void Carriage::display() {
        _object->enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object->enableTechnique(GraphicLib::Techniques::COLOR);
    }

    void Carriage::hide() {
        _object->disableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object->disableTechnique(GraphicLib::Techniques::COLOR);
    }

    void Carriage::move(uint8_t offset) {
        auto technique = _object->getTechnique(GraphicLib::Techniques::TRANSFORM);
        auto transformTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TransformTechnique>(technique);
        auto transform = transformTechnique->getTransformValue();

        auto projection = glm::ortho(0.0f, static_cast<float>(3440), static_cast<float>(1440), 0.0f);
        float x = 0;
        if (offset > 0) {
            for (int i = 0; i < offset; ++i) {
                int pos = i+_position;
                if (_characterAdvances.size() > pos) {
                    x += std::abs(static_cast<float>(_characterAdvances[pos] >> 6) * _textSize);
                } else {
                    break;
                }
            }
        } else {
            for (int i = -offset; i >= 0; --i) {
                int pos = i+_position;
                if (_characterAdvances.size() > pos) {
                    x -= std::abs((float)((_characterAdvances[pos] >> 6) - 1700)/1700);
                } else {
                    break;
                }
            }
        }
        auto t = projection * glm::vec4(x, 0, 0, 1.0);
        transformTechnique->setTransformValue({t.x, t.y, t.z});

        _position += offset;
    }

    void Carriage::addCharacterAdvance(unsigned int advance) {
        _characterAdvances.push_back(advance);
    }

    void Carriage::eraseCharacterAdvance(unsigned int index) {
        _characterAdvances.erase(_characterAdvances.cbegin() + index);
    }

    void Carriage::eraseBackCharacterAdvance() {
        _characterAdvances.pop_back();
    }

    void Carriage::clearCharactersAdvance() {
        _characterAdvances.clear();
    }
}