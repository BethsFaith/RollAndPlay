//
// Created by VerOchka on 24.10.2023.
//

#ifndef ROLLANDPLAY_TEXTTECHNIQUE_HPP
#define ROLLANDPLAY_TEXTTECHNIQUE_HPP

#include "../TextRender.hpp"

#include "Technique.hpp"

namespace GraphicLib::Techniques {
    class TextTechnique : public Technique {
    public:
        using Ptr = std::shared_ptr<TextTechnique>;

        TextTechnique() = default;
        ~TextTechnique() override = default;

        static void initTextRendering(unsigned int width, unsigned int height, std::string font, int size);
        static void freeTextRendering();

        void execute() override;

        void setText(const std::string &text);

        void setColor(const glm::vec3 &color);

        void setWidth(float width);

        void setHeight(float height);

        void setScale(float scale);

        const std::string &getText() const;

        const glm::vec3 &getColor() const;

        float getScale() const;

        float getWidth() const;

        float getHeight() const;

    protected:
        static GraphicLib::TextRender::Ptr TextRenderer;
        static glm::mat4 Projection;

        static unsigned int ScreenWidth;
        static unsigned int ScreenHeight;
    private:
        std::string _text;
        glm::vec3 _color = glm::vec3{1.0f};
        float _scale = 1.0f;
        float _width = 5.0f;
        float _height = 5.0f;
    };
}

#endif //ROLLANDPLAY_TEXTTECHNIQUE_HPP
