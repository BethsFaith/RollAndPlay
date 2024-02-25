//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_TEXTBOX_HPP
#define ROLLANDPLAY_TEXTBOX_HPP

#include <GraphicLib/Object.hpp>
#include <GraphicLib/Primitives/Rectangle.hpp>

#include "Widget.hpp"
#include "graphic/Form.hpp"
#include "styles/TextParams.hpp"

namespace Widgets {
    class TextBox : public Widget {
    public:
        using Ptr = std::shared_ptr<TextBox>;
        TextBox();
        ~TextBox() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        void clear();

        void setTextParams(const Styles::TextParams& text);
        void setTextColor(Styles::Color color);
        void setTextSize(float size);
        void setText(const std::u16string& content);
        void setColor(Styles::Color color);
        void setProjection(float minX, float maxX, float minY, float maxY) override;

    private:
        std::unique_ptr<Graphic::Form> _form;
    };
}


#endif //ROLLANDPLAY_TEXTBOX_HPP
