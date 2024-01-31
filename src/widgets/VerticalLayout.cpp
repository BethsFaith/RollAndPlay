//
// Created by BethsFaith on 29.01.2024.
//

#include "VerticalLayout.hpp"

namespace Widgets {
    VerticalLayout::VerticalLayout(glm::vec2 pos) : _position(pos){}

    void VerticalLayout::addWidget(const Widget::Ptr& widget) {
        Layout::addWidget(widget);

        widget->setTransform(_position);

        _position.y -= widget->getScale().y + 0.01f;
    }

    void VerticalLayout::removeWidget(const Widget::Ptr& widget) {
        Layout::removeWidget(widget);
    }
}