//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_MENUBARSTYLE_HPP
#define ROLLANDPLAY_MENUBARSTYLE_HPP

#include "ButtonStyle.hpp"

namespace Widgets::Styles {
    struct MenuBarStyle : public WidgetStyle {
        MenuBarStyle() = default;
        ~MenuBarStyle() override = default;

        float elementOffset{0.1f};

        glm::vec2 defaultPosition{};
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_MENUBARSTYLE_HPP
