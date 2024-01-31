//
// Created by BethsFaith on 29.01.2024.
//

#include "HorizontalLayout.hpp"

namespace Widgets {
    HorizontalLayout::HorizontalLayout(glm::vec2 pos) : _position(pos) {}

    void HorizontalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        widget->setTransform(_position);

        _position.x += widget->getScale().x + 0.01f;
    }

    void HorizontalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }
}    //namespace Widgets
