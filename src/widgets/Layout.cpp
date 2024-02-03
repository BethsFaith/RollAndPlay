//
// Created by BethsFaith on 29.01.2024.
//

#include "Layout.hpp"

namespace Widgets {
    Layout::Layout(WidgetType type) : Widget(type) {}

    void Layout::addWidget(const Widget::Ptr& widget) {
        widgets.push_back(widget);
    }

    void Layout::removeWidget(const Widget::Ptr& widget) {
        auto pos = std::find(widgets.begin(), widgets.end(), widget);
        if (pos != widgets.end()) {
            widgets.erase(pos);
        }
    }

    void Layout::draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                      GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                      GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        for (auto& widget : widgets) {
            widget->draw(formShader, textShader, pickShader);
        }
    }

    bool Layout::checkSelecting(unsigned int x, unsigned int y) {
        for (auto& widget : widgets) {
            if (widget->checkSelecting(x,y)) {
                return true;
            }
        }

        return false;
    }

    void Layout::setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) {
        Widget::setCanvas(canvas);

        for (auto& widget : widgets) {
            widget->setCanvas(canvas);
        }
    }

    void Layout::setWidgetOffset(float offset) {
        widgetOffset = offset;
    }

    void Layout::setTransform(glm::vec2 position_, glm::vec2 scale_) {
        scale = scale_;
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

    void Layout::setScale(glm::vec2 scale_) {
        scale = scale_;
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
}    //namespace Widgets
