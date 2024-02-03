//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_WIDGETCONTROLLER_HPP
#define ROLLANDPLAY_WIDGETCONTROLLER_HPP

#include "../widgets/Widget.hpp"
#include "GLController.hpp"

namespace Controllers {
    class WidgetController : public GLController {
    public:
        using Ptr = std::shared_ptr<WidgetController>;

        ~WidgetController() override = default;

        virtual void addWidget(Widgets::Widget::Ptr widget) = 0;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_WIDGETCONTROLLER_HPP
