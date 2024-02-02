//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_WIDGETSTYLE_HPP
#define ROLLANDPLAY_WIDGETSTYLE_HPP

#include <iostream>

#include "Color.hpp"

namespace Widgets::Styles {
    struct WidgetStyle {
        using Ptr = std::shared_ptr<WidgetStyle>;

        WidgetStyle() = default;
        virtual ~WidgetStyle() = default;

        glm::vec2 scale{};
    };
}    //namespace widgets

#endif    //ROLLANDPLAY_WIDGETSTYLE_HPP
