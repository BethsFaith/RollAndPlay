//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTFORM_HPP
#define ROLLANDPLAY_TEXTFORM_HPP

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
    class TextForm : public Button {
    public:
        using Ptr = std::shared_ptr<TextForm>;

        explicit TextForm(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, TextData inputParams);

        ~TextForm() override = default;

        void init(glm::vec2 scale, glm::vec2 position, const TextData& textForm, Color color) override;

        void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void press() override;
        void release() override;

        void putToBuffer(char16_t character);
        void putToBuffer(const std::string& string);
        void putToBuffer(const std::u16string& string);

        void popFromBuffer();
        void popFromBuffer(unsigned int position);

        void hideContent(bool needHide);

        void clear();

        [[nodiscard]] const std::u16string& getBuf() const;

        [[nodiscard]] std::string getU8Buf() const;

        void renderForm(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void moveCarriage(int offset);
        void moveCarriageToScreenPosition(float xPos);

    private:
        void putToBuffer(char16_t character, unsigned int position);
        void putToBuffer(const std::string& string, unsigned int position);
        void putToBuffer(const std::u16string& string, unsigned int position);

        glm::vec2 _position{};
        glm::vec2 _scale{};
        TextData _buf;
        bool _needHide = false;
        float _inputTextSize = 1.4f;

        Carriage _carriage{};
    };
}    //namespace Forms
#endif    //ROLLANDPLAY_TEXTFORM_HPP
