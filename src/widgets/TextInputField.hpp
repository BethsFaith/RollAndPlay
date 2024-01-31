//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTINPUTFIELD_HPP
#define ROLLANDPLAY_TEXTINPUTFIELD_HPP

#include <iostream>
#include <utility>
#ifdef WIN32
#include <codecvt>
#else
#include <uchar.h>
#endif

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "Button.hpp"
#include "Carriage.hpp"

namespace Widgets {
    class TextInputField : public Button {
    public:
        using Ptr = std::shared_ptr<TextInputField>;

        explicit TextInputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, TextData inputParams);

        ~TextInputField() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;

        void press() override;
        void release() override;

        void putToBuffer(char16_t character);
        void putToBuffer(const std::string& string);
        void putToBuffer(const std::u16string& string);

        void popFromBuffer();
        void popFromBuffer(unsigned int position);

        void hideContent(bool needHide);

        void clear();

        void moveCarriage(int offset);
        void moveCarriageToScreenPosition(float xPos);

        [[nodiscard]] std::string getU8Buf() const;
        [[nodiscard]] const std::u16string& getBuf() const;

    protected:
        void updateTextField();

        void putToBuffer(char16_t character, unsigned int position);
        void putToBuffer(const std::string& string, unsigned int position);
        void putToBuffer(const std::u16string& string, unsigned int position);

        Graphic::Form _textField;
    private:
        TextData _buf;
        bool _needHide = false;

        Carriage _carriage{};
    };
}    //namespace Forms
#endif    //ROLLANDPLAY_TEXTINPUTFIELD_HPP
