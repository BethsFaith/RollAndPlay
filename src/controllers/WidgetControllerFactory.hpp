//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_WIDGETCONTROLLERFACTORY_HPP
#define ROLLANDPLAY_WIDGETCONTROLLERFACTORY_HPP

#include "../widgets/WidgetType.hpp"
#include "ButtonController.hpp"
#include "ImageButtonController.hpp"
#include "MenuBarController.hpp"
#include "TextInputFieldController.hpp"

namespace Controllers {
    class WidgetControllerFactory {
    public:
        static WidgetController::Ptr create(Widgets::WidgetType type);

    private:
        WidgetControllerFactory() = default;
        ~WidgetControllerFactory() = default;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_WIDGETCONTROLLERFACTORY_HPP
