//
// Created by VerOchka on 24.10.2023.
//

#ifndef ROLLANDPLAY_TEXTRENDER_HPP
#define ROLLANDPLAY_TEXTRENDER_HPP

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H "freetype2/freetype/freetype.h"
#include <map>
#include <glm/glm.hpp>

#include "GlagGlfw.hpp"
#include "Textures/Texture.hpp"
#include "Shaders/ShaderProgram.hpp"
#include "Buffers/Vao.hpp"
#include "Buffers/Vbo.hpp"

namespace GraphicLib {
    class TextRender {
    public:
        using Ptr = std::shared_ptr<TextRender>;

        struct Character {
            Textures::Texture::Ptr texture; // IdCounter текстуры глифа
            glm::ivec2 size;                // размер глифа
            glm::ivec2 bearing;             // смещение от линии шрифта до верхнего левого угла глифа
            unsigned int advance;           // горизонтальное смещение для перехода к следующему глифу
        };

        TextRender(unsigned int width, unsigned int height);

        void load(const std::string& font, unsigned int fontSize);

        void render(std::string text, float x, float y, float scale, glm::vec3 color);

        void render(std::u16string text, float x, float y, float scale, glm::vec3 color);

    private:
        // Список предварительно скомпилированных символов
        std::map<char16_t, Character> characters;

        // Состояние рендеринга
        Buffers::VAO::Ptr _vao;
        Buffers::VBO<glm::vec4>::Ptr _vbo;
    };
}

#endif //ROLLANDPLAY_TEXTRENDER_HPP
