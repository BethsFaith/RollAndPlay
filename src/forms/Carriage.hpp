//
// Created by VerOchka on 05.01.2024.
//

#ifndef ROLLANDPLAY_CARRIAGE_HPP
#define ROLLANDPLAY_CARRIAGE_HPP

#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <GraphicLib/Primitives/Rectangle.hpp>
#include <GraphicLib/TextRender.hpp>

#include "../config/Config.hpp"
#include "Color.hpp"

namespace Forms {
    class Carriage {
    public:
        struct CharacterOffset {
            glm::ivec2 bearing;
            unsigned int advance;
        };

        Carriage();

        void init(Color color, const glm::vec3 &scale, const glm::vec3 &position, float textSize);

        void render(const GraphicLib::Shaders::ShaderProgram::Ptr& shader);

        void show();
        void hide();

        void move(int indexOffset);
        void moveToIndex(unsigned int index);
        void moveToScreenPosition(float xPos);

        void addCharacterData(const CharacterOffset& character);
        void releaseCharacterData(unsigned int index);
        void releaseBackCharacterData();
        void clearAllCharacterData();

        [[nodiscard]] uint8_t getPosition() const;
    private:
        GraphicLib::Object::Ptr _object;
        uint8_t _position = 0;
        float _initXPosition{};
        std::vector<CharacterOffset> _characterOffsets{};
        float _textSize = 1.0f;
    };
}

#endif //ROLLANDPLAY_CARRIAGE_HPP
