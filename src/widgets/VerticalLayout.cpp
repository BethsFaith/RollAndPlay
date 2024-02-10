//
// Created by BethsFaith on 29.01.2024.
//

#include "VerticalLayout.hpp"

namespace Widgets {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL_LAYOUT) {}

    void VerticalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        if (widget->getType() == IMAGE_BUTTON || widget->getType() == IMAGE_BOX) {
            widget->setTransform(position);
        } else {
            widget->setTransform(position, scale);
        }
        position.y -= widget->getScale().y + widgetOffset;
    }

    void VerticalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }
}