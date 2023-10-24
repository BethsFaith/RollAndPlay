//
// Created by VerOchka on 24.10.2023.
//

#ifndef ROLLANDPLAY_TEXT_HPP
#define ROLLANDPLAY_TEXT_HPP

#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <glm/glm.hpp>

#include "EntryPoint.hpp"
#include "textures/Texture.hpp"
#include "shaders/ShaderProgram.hpp"
#include "buffers/Vao.hpp"
#include "buffers/Vbo.hpp"

namespace GraphicLib {
    class Text {
    public:
        using Ptr = std::shared_ptr<Text>;

        struct Character {
            Textures::Texture::Ptr texture; // ID текстуры глифа
            glm::ivec2 size;                // размер глифа
            glm::ivec2 bearing;             // смещение от линии шрифта до верхнего левого угла глифа
            unsigned int advance;           // горизонтальное смещение для перехода к следующему глифу
        };

        Text(unsigned int width, unsigned int height);

        void load(const std::string& font, unsigned int fontSize);

        void render(std::string text, float x, float y, float scale, glm::vec3 color);

    private:
        // Список предварительно скомпилированных символов
        std::map<char, Character> characters;

        // Состояние рендеринга
        Buffers::VAO::Ptr _vao;
        Buffers::VBO<glm::vec4>::Ptr _vbo;
    };
}

#endif //ROLLANDPLAY_TEXT_HPP
