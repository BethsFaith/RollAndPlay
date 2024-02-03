//
// Created by BethsFaith on 01.02.2024.
//

#include "WidgetBuilder.hpp"

namespace Widgets {
    void WidgetBuilder::addWidgetStyle(WidgetType type, const Styles::WidgetStyle::Ptr& style) {
        styles[type] = style;
    }

    Widget::Ptr WidgetBuilder::createWidget(WidgetType type) {
        return WidgetFactory::create(type, styles[type]);
    }
}
