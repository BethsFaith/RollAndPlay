//
// Created by BethsFaith on 29.01.2024.
//

#include "VerticalLayout.hpp"

namespace Widgets {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL_LAYOUT) {}

    void VerticalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = widget->getScale();
            widget->setTransform({position.x + widgetScale.x/2, position.y});
        } else {
            widgetScale = elemScale;
            widget->setTransform({position.x + widgetScale.x/2, position.y}, elemScale);
        }

        position.y -= widgetScale.y + widgetOffset;
        scale.y += widgetScale.y/2;
        if (scale.x < widgetScale.x) {
            scale.x = widgetScale.x;
        }
    }

    void VerticalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }

    void VerticalLayout::clear() {
        position.y += (scale.y*2 + widgetOffset * (float)widgets.size());

        widgets.clear();

        scale = {};
    }
}