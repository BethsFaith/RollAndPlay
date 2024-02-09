//
// Created by BethsFaith on 29.01.2024.
//

#include "VerticalLayout.hpp"

namespace Widgets {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL_LAYOUT) {}

    void VerticalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        widget->setTransform(position, scale);

        position.y -= scale.y + widgetOffset;
    }

    void VerticalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }
}