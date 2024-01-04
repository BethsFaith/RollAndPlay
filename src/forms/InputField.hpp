//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_INPUTFIELD_HPP
#define ROLLANDPLAY_INPUTFIELD_HPP

#include <iostream>
#include <utility>
#ifdef   WIN32
#include <codecvt>
#else
#include <uchar.h>
#endif

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "Button.hpp"

namespace Forms {
    class InputField : public Button {
    public:
        using Ptr = std::shared_ptr<InputField>;

        explicit InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams);

        ~InputField() override = default;

        void init(glm::vec3 scale, glm::vec2 position, const Text &text, Color color) override;

        void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void press() override;
        void release() override;

        void putToBuffer(char16_t character);
        void putToBuffer(char16_t character, unsigned int position);

        void putToBuffer(const std::string &string);
        void putToBuffer(const std::string &string, unsigned int position);

        void putToBuffer(const std::u16string &string);
        void putToBuffer(const std::u16string &string, unsigned int position);

        void popFromBuffer();
        void popFromBuffer(unsigned int position);

        void clear();

        [[nodiscard]] const std::u16string &getBuf() const;

        [[nodiscard]] std::string getU8Buf() const;

        void renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

    private:
        void renderCarriage(GraphicLib::Shaders::ShaderProgram::Ptr shader);
        void moveCarriage(float xOffset);
        void enableCarriage();
        void disableCarriage();

        glm::vec2 _position;
        glm::vec2 _scale;
        Text _buf;
        float _inputTextSize = 1.4f;
        GraphicLib::Object::Ptr _carriage;
    };
}
#endif    //ROLLANDPLAY_INPUTFIELD_HPP
