//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_TEXTBOX_HPP
#define ROLLANDPLAY_TEXTBOX_HPP

#include <GraphicLib/Object.hpp>
#include <GraphicLib/Techniques/ColorTechnique.hpp>
#include <GraphicLib/Techniques/TransformTechnique.hpp>
#include <GraphicLib/Techniques/TextTechnique.hpp>

#include "Form.hpp"
#include "Text.hpp"

namespace Forms {
    class TextBox : public Form {
    public:
        using Ptr = std::shared_ptr<TextBox>;
        TextBox();

        void init(glm::vec3 scale, glm::vec2 position, const Text &text, Color color);

        void renderText(const GraphicLib::Shaders::ShaderProgram::Ptr& shader);
        void renderForm(const GraphicLib::Shaders::ShaderProgram::Ptr& shader);

    private:
        GraphicLib::Object _object{};

        Text _content;
    };
}


#endif //ROLLANDPLAY_TEXTBOX_HPP
