//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_LAYOUTSTYLE_HPP
#define ROLLANDPLAY_LAYOUTSTYLE_HPP

#include "WidgetStyle.hpp"

namespace Widgets::Styles {
    struct LayoutStyle {
        using Ptr = std::shared_ptr<LayoutStyle>;

        LayoutStyle() = default;
        ~LayoutStyle() = default;

        float widgetOffset{0.1f};
    };
}
#endif    //ROLLANDPLAY_LAYOUTSTYLE_HPP
