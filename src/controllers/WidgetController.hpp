//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_WIDGETCONTROLLER_HPP
#define ROLLANDPLAY_WIDGETCONTROLLER_HPP

#include "../widgets/Button.hpp"
#include "GLController.hpp"

namespace Controllers {
    class WidgetController : public GLController {
    public:
        struct Target {
            using Ptr = std::shared_ptr<Target>;

            std::weak_ptr<Widgets::Button> widget;
            Controllers::WidgetController* owner;
        };

        using Ptr = std::shared_ptr<WidgetController>;

        ~WidgetController() override = default;

        virtual void addWidget(Widgets::Widget::Ptr widget) = 0;
        virtual void removeWidget(const Widgets::Widget::Ptr& widget) = 0;

        Target::Ptr target;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_WIDGETCONTROLLER_HPP
