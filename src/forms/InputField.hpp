//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_INPUTFIELD_HPP
#define ROLLANDPLAY_INPUTFIELD_HPP

#include <iostream>
#include <utility>
//#ifdef _WIN32
//#include <windows.h>
//#else
//#include <clocale>
//#endif
#ifdef   WIN32
#include <codecvt>
#else
#include <uchar.h>
#endif


#include "Button.hpp"

namespace Forms {
    class InputField : public Button {
    public:
        using Ptr = std::shared_ptr<InputField>;

        explicit InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr &graphicPrimitive, Text inputParams);

        ~InputField() override = default;

        void putToBuffer(char16_t character);

        void putToBuffer(const std::string &string);

        void popFromBuffer();

        void clear();

        [[nodiscard]] std::string getBuf() const;

        void renderText(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

        void renderTracing(GraphicLib::Shaders::ShaderProgram::Ptr shader) override;

    private:
        Text _buf;
    };
}
#endif    //ROLLANDPLAY_INPUTFIELD_HPP
