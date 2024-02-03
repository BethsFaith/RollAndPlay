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
        
        Widget::Ptr createWidget(WidgetType type);
    private:
        std::map<WidgetType, Styles::WidgetStyle::Ptr> styles;
    };
}

#endif    //ROLLANDPLAY_WIDGETBUILDER_HPP
