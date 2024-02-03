//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_TEXTINPUTFIELDSTYLE_HPP
#define ROLLANDPLAY_TEXTINPUTFIELDSTYLE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "ButtonStyle.hpp"

namespace Widgets::Styles {
    struct TextInputFieldStyle : public ButtonStyle {
        using Ptr = std::shared_ptr<TextInputFieldStyle>;

        TextInputFieldStyle() = default;
        ~TextInputFieldStyle() override = default;

        TextParams inputParams;
    };
}

#endif    //ROLLANDPLAY_TEXTINPUTFIELDSTYLE_HPP
