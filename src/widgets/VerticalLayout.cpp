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
        } else {
            widgetScale = elemScale;
            widget->setScale(elemScale);
        }
//
//        if ((int)widgets.size() == 1) {
//            position.y -= widgetScale.y/2;
//        }
        scale.y += widgetScale.y/2;
        if (scale.x < widgetScale.x) {
            scale.x = widgetScale.x;
        }

        widget->setTransform({position.x + widgetScale.x/2, position.y - widgetScale.y/2});

        position.y -= widgetScale.y + widgetOffset;
    }

    void VerticalLayout::addLayout(Layout::Ptr layout) {
        glm::vec2 layoutScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            layoutScale = layout->getScale();
        } else {
            layoutScale = elemScale;
            layout->setScale(elemScale);
        }

        if ((int)widgets.size() != 0) {
            position.y -= layoutScale.y/2;
        }

        scale.y += layoutScale.y;
        if (scale.x < layoutScale.x) {
            scale.x = layoutScale.x;
        }

        layout->setTransform({position.x + layoutScale.x/2, position.y});

        for (const auto& widget : layout->getWidgets()) {
            Layout::addWidget(widget);
        }

        position.y -= widgetOffset + layoutScale.y;
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