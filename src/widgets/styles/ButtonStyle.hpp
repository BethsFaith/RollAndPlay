//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_BUTTONSTYLE_HPP
#define ROLLANDPLAY_BUTTONSTYLE_HPP

#include <GraphicLib/Primitives/AbstractPrimitive.hpp>

#include "WidgetStyle.hpp"
#include "TextParams.hpp"

namespace Widgets::Styles {
    struct ButtonStyle : public WidgetStyle {
        using Ptr = std::shared_ptr<ButtonStyle>;

        ButtonStyle() = default;
        ~ButtonStyle() override = default;

        GraphicLib::Primitives::AbstractPrimitive::Ptr figure;

        TextParams labelParams;

        Color color{};
        Color traceColor{};
        Color pressColor{};
    };
}    //namespace widgets

#endif    //ROLLANDPLAY_BUTTONSTYLE_HPP
