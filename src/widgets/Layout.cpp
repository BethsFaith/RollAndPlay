//
// Created by BethsFaith on 29.01.2024.
//

#include "Layout.hpp"

namespace Widgets {
    Layout::Layout() : Widget(LAYOUT) {}

    void Layout::addWidget(const Widget::Ptr& widget) {
        _widgets.push_back(widget);
    }

    void Layout::removeWidget(const Widget::Ptr& widget) {
        auto pos = std::find(_widgets.begin(), _widgets.end(), widget);
        if (pos != _widgets.end()) {
            _widgets.erase(pos);
        }
    }

    void Layout::draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                      GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                      GraphicLib::Shaders::ShaderProgram::Ptr pickShader) {
        for (auto& widget : _widgets) {
            widget->draw(formShader, textShader, pickShader);
        }
    }

    void Layout::setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) {
        Widget::setCanvas(canvas);

        for (auto& widget : _widgets) {
            widget->setCanvas(canvas);
        }
    }
}    //namespace Widgets
