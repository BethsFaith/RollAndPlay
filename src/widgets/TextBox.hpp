//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_TEXTBOX_HPP
#define ROLLANDPLAY_TEXTBOX_HPP

#include <GraphicLib/Object.hpp>
#include <GraphicLib/Primitives/Rectangle.hpp>

#include "TextData.hpp"
#include "Widget.hpp"
#include "graphic/Form.hpp"

namespace Widgets {
    class TextBox : public Widget {
    public:
        using Ptr = std::shared_ptr<TextBox>;
        TextBox();
        ~TextBox() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        void clear();

        void setText(const std::u16string& content);
        void setTextForm(const TextData& text);
        void setTextColor(Color color);
        void setTextScale(float scale);
        void setColor(Color color);

    private:
        std::unique_ptr<Graphic::Form> _form;
    };
}


#endif //ROLLANDPLAY_TEXTBOX_HPP
