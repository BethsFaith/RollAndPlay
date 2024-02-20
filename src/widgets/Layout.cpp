//
// Created by BethsFaith on 29.01.2024.
//

#include "Layout.hpp"

namespace Widgets {
    Layout::Layout(LayoutType type) : _type(type) {}

    void Layout::addWidget(const Widget::Ptr& widget) {
        widgets.push_back(widget);
    }

    void Layout::removeWidget(const Widget::Ptr& widget) {
        auto pos = std::find(widgets.begin(), widgets.end(), widget);
        if (pos != widgets.end()) {
            scale -= widget->getScale();

            widgets.erase(pos);
        }
    }

    void Layout::setWidgetOffset(float offset) {
        widgetOffset = offset;
    }

    void Layout::setTransform(glm::vec2 position_, glm::vec2 scale_) {
        elemScale = scale_;
        setTransform(position_);
    }

    void Layout::setTransform(glm::vec2 position_) {
        position = position_;

        auto elements = widgets;
        widgets.clear();
        for (auto& elem : elements) {
            addWidget(elem);
        }
    }

    void Layout::setScale(glm::vec2 elemScale_) {
        elemScale = elemScale_;

        auto elements = widgets;
        widgets.clear();
        for (auto& elem : elements) {
            addWidget(elem);
        }
    }

    void Layout::setProjection(float minX, float maxX, float minY, float maxY) {
    }

    glm::vec2 Layout::getScale() {
        return scale;
    }

    glm::vec2 Layout::getPosition() {
        return position;
    }

    const std::vector<Widget::Ptr>& Layout::getWidgets() const {
        return widgets;
    }

    LayoutType Layout::getType() const {
        return _type;
    }
}    //namespace Widgets
