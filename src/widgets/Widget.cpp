//
// Created by VerOchka on 23.10.2023.
//
#include "Widget.hpp"

namespace Widgets {
    Widget::Widget(WidgetType type) : _type(type) {}

    void Widget::setCanvas(const GraphicLib::PickableTexture::Ptr& pickableTexture) {
        Widget::canvas = pickableTexture;
    }

    WidgetType Widget::getType() const {
        return _type;
    }
}    //namespace Forms
