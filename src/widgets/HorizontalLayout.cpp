//
// Created by BethsFaith on 29.01.2024.
//

#include "HorizontalLayout.hpp"

namespace Widgets {
    HorizontalLayout::HorizontalLayout() : Layout(HORIZONTAL) {}

    void HorizontalLayout::putWidget(const Widget::Ptr& widget) {
        Layout::putWidget(widget);

        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = widget->getScale();
        } else {
            widgetScale = elemScale;
            widget->setScale(elemScale);
        }

        if (widgets.size() == 1) {
            position.y -= widgetScale.y/2;
        } else {
        }

        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        widget->setTransform({position.x + widgetScale.x/2, position.y});

        position.x += widgetScale.x + widgetOffset;
    }

    void HorizontalLayout::putLayout(Layout::Ptr layout) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = layout->getScale();
        } else {
            widgetScale = elemScale;
            layout->setScale(elemScale);
        }

        position.x += widgetScale.x + widgetOffset;
        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        layout->setTransform({position.x, position.y});

        for (const auto& widget : layout->getWidgets()) {
            Layout::putWidget(widget);
        }
    }

    void HorizontalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }

    void HorizontalLayout::clear() {
        position.x -= (scale.x*2 + widgetOffset * (float)widgets.size());

        widgets.clear();

        scale = {};
    }

    glm::vec2 HorizontalLayout::getScale() {
        return {0.0f, scale.y};
    }
}    //namespace Widgets
