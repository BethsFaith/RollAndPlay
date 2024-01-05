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
        transformTechnique->enableScale(scale);
        transformTechnique->enableTransform({position.x,
                                             position.y, position.z});

        _object->addTechnique(GraphicLib::Techniques::TRANSFORM, transformTechnique);

        _textSize = textSize;
    }

    void Carriage::render(const GraphicLib::Shaders::ShaderProgram::Ptr& shader) {
        _object->render(shader);
    }

    void Carriage::show() {
        _object->enableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object->enableTechnique(GraphicLib::Techniques::COLOR);
    }

    void Carriage::hide() {
        _object->disableTechnique(GraphicLib::Techniques::TRANSFORM);
        _object->disableTechnique(GraphicLib::Techniques::COLOR);
    }

    void Carriage::move(int indexOffset) {
        auto technique = _object->getTechnique(GraphicLib::Techniques::TRANSFORM);
        auto transformTechnique = std::dynamic_pointer_cast<GraphicLib::Techniques::TransformTechnique>(technique);
        auto transform = transformTechnique->getTransformValue();

        int screenWidth, screenHeight;
        Config::pullDesktopResolution(screenWidth, screenHeight);
        float w = static_cast<float>(screenWidth) / 2;
        float x = w + transform.x * w;
        float xPos;
        if (indexOffset > 0) {
            for (int i = 0; i < indexOffset; ++i) {
                int pos = i+_position;
                if (_characterOffsets.size() <= pos) {
                    break;
                }
                x += static_cast<float>(_characterOffsets[pos].advance >> 6) * _textSize;
            }
            xPos = x + static_cast<float>(_characterOffsets[indexOffset - 1 + _position].bearing.x) * _textSize;
        } else {
            for (int i = 0; i < -indexOffset; ++i) {
                int pos = _position-i-1;
                if (_characterOffsets.size() <= pos) {
                    break;
                }
                x -= static_cast<float>(_characterOffsets[pos].advance >> 6) * _textSize;
            }
            xPos = x - static_cast<float>(_characterOffsets[indexOffset + _position].bearing.x) * _textSize;
        }
        xPos = (xPos - w) / w;
        transformTechnique->setTransformValue({xPos, transform.y, transform.z});

        _position += indexOffset;
    }

    void Carriage::addCharacterData(const CharacterOffset& character) {
        _characterOffsets.push_back(character);
    }

    void Carriage::releaseCharacterData(unsigned int index) {
        _characterOffsets.erase(_characterOffsets.cbegin() + index);
    }

    void Carriage::releaseBackCharacterData() {
        _characterOffsets.pop_back();
    }

    void Carriage::clearAllCharacterData() {
        _characterOffsets.clear();
    }

    uint8_t Carriage::getPosition() const {
        return _position;
    }
}