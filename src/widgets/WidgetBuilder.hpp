//
// Created by BethsFaith on 01.02.2024.
//

#ifndef ROLLANDPLAY_WIDGETBUILDER_HPP
#define ROLLANDPLAY_WIDGETBUILDER_HPP

#include "WidgetFactory.hpp"
#include "styles/WidgetStyle.hpp"

namespace Widgets {
    class WidgetBuilder {
    public:
        using Ptr = std::shared_ptr<WidgetBuilder>;
 
        void addWidgetStyle(WidgetType type, const Styles::WidgetStyle::Ptr& style);
        void addLayoutStyle(LayoutType type, const Styles::LayoutStyle::Ptr& style);
        
        Widget::Ptr createWidget(WidgetType type);
        Layout::Ptr createLayout(LayoutType type);
    private:
        std::map<WidgetType, Styles::WidgetStyle::Ptr> styles;
        std::map<LayoutType, Styles::LayoutStyle::Ptr> layoutStyles;
    };
}

#endif    //ROLLANDPLAY_WIDGETBUILDER_HPP
