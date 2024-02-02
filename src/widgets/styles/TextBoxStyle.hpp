//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_TEXTBOXSTYLE_HPP
#define ROLLANDPLAY_TEXTBOXSTYLE_HPP

#include "WidgetStyle.hpp"

#include "TextParams.hpp"

namespace Widgets::Styles {
    struct TextBoxStyle : public WidgetStyle {
        using Ptr = std::shared_ptr<TextBoxStyle>;

        TextBoxStyle() = default;
        ~TextBoxStyle() override = default;

        Color color{};
        TextParams textLabelParams;
    };
}

#endif    //ROLLANDPLAY_TEXTBOXSTYLE_HPP
