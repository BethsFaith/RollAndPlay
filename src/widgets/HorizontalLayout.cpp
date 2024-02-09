//
// Created by BethsFaith on 29.01.2024.
//

#include "HorizontalLayout.hpp"

namespace Widgets {
    HorizontalLayout::HorizontalLayout() : Layout(HORIZONTAL_LAYOUT) {}

    void HorizontalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        widget->setTransform(position, scale);

        position.x += scale.x + widgetOffset;
    }

    void HorizontalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }
}    //namespace Widgets
