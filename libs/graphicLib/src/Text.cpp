//
// Created by VerOchka on 24.10.2023.
//

#include "Text.hpp"

namespace GraphicLib {
    Text::Text(unsigned int width, unsigned int height) {
        // Загрузка VAO/VBO для текстурных прямоугольников
        _vao = std::make_shared<Buffers::VAO>();
        _vao->bind();

        std::vector<glm::vec4> vertices;
        vertices.reserve(6);

        _vbo = std::make_shared<Buffers::VBO<glm::vec4>>(vertices);
        _vbo->bind();
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, nullptr, GL_DYNAMIC_DRAW);
//        _vbo->bindData(GL_DYNAMIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

        _vbo->unbind();
        _vao->unbind();
    }

    void Text::load(const std::string& font, unsigned int fontSize) {
        // Сначала очищаем ранее загруженные символы
        this->characters.clear();

        // Затем инициализируем и загружаем библиотеку FreeType
        FT_Library ft;
        if (FT_Init_FreeType(&ft)) // все функции в случае ошибки возвращают значение, отличное от 0
            std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

        // Загрузка шрифта в качестве face
        FT_Face face;
        if (FT_New_Face(ft, font.c_str(), 0, &face))
            std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

        // Устанавливаем размер загруженных глифов
        FT_Set_Pixel_Sizes(face, 0, fontSize);

        // Отключаем ограничение на выравнивание байтов
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        // Предварительно загружаем/компилируем символы шрифта и сохраняем их
        for (GLubyte c = 0; c < 255; c++)
        {
            // Загрузка символа глифа
            if (FT_Load_Char(face, c, FT_LOAD_RENDER))
            {
                std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
                continue;
            }

            // Генерация текстуры
            auto texture = std::make_shared<Textures::Texture>("", "");
            texture->bind();
            texture->setImage(GL_RED, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows,
                              GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);

            // Установка параметров текстур
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            // Теперь сохраняем символы для их дальнейшего использования
            Character character = {
                    .texture = texture,
                    .size = glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
                    .bearing = glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
                    .advance = static_cast<unsigned int>(face->glyph->advance.x)
            };
            characters.insert(std::pair<char, Character>(c, character));
        }
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

        // Когда закончили, освобождаем ресурсы FreeType
        FT_Done_Face(face);
        FT_Done_FreeType(ft);
    }

    void Text::render(std::string text, float x, float y, float scale, glm::vec3 color) {
        // активировать соответствующий шейдер перед этим

        glActiveTexture(GL_TEXTURE0);
        _vao->bind();

        std::string::const_iterator c;
        for (c = text.begin(); c != text.end(); c++)
        {
            Character ch = characters[*c];

            float xpos = x + ch.bearing.x * scale;
            float ypos = y + (this->characters['H'].bearing.y - ch.bearing.y) * scale;

            float w = ch.size.x * scale;
            float h = ch.size.y * scale;

            // Обновляем VBO для каждого символа
//            std::vector<glm::vec4> vertices = {
//                    { xpos,     ypos + h,   0.0f, 1.0f },
//                    { xpos + w, ypos,       1.0f, 0.0f },
//                    { xpos,     ypos,       0.0f, 0.0f },
//
//                    { xpos,     ypos + h,   0.0f, 1.0f },
//                    { xpos + w, ypos + h,   1.0f, 1.0f },
//                    { xpos + w, ypos,       1.0f, 0.0f }
//            };

            // Обновляем VBO для каждого символа
            float vertices[6][4] = {
                    { xpos,     ypos + h,   0.0f, 1.0f },
                    { xpos + w, ypos,       1.0f, 0.0f },
                    { xpos,     ypos,       0.0f, 0.0f },

                    { xpos,     ypos + h,   0.0f, 1.0f },
                    { xpos + w, ypos + h,   1.0f, 1.0f },
                    { xpos + w, ypos,       1.0f, 0.0f }
            };


            // Рендерим на прямоугольник текстуру глифа
            ch.texture->bind();

            // Обновляем содержимое памяти VBO
            _vbo->bind();
            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
//            _vbo->bindSubData(vertices, 0);
            _vbo->unbind();

            // Рендерим прямоугольник
            glDrawArrays(GL_TRIANGLES, 0, 6);

            // Теперь смещаем курсор к следующему глифу
            x += (ch.advance >> 6) * scale; // битовый сдвиг на 6, чтобы получить значение в пикселях (2^6 = 64)
        }
        _vao->unbind();
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}