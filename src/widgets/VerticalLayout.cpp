//
// Created by BethsFaith on 29.01.2024.
//

#include "VerticalLayout.hpp"

namespace Widgets {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL) {}

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

    void VerticalLayout::addLayout(Layout::Ptr layout) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = layout->getScale();
            layout->setTransform({position.x + widgetScale.x/2, position.y});
        } else {
            widgetScale = elemScale;
            layout->setTransform({position.x + widgetScale.x/2, position.y}, elemScale);
        }

        for (const auto& widget : layout->getWidgets()) {
            Layout::addWidget(widget);
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