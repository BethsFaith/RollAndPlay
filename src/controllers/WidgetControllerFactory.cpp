//
// Created by VerOchka on 26.10.2023.
//

#include "WidgetControllerFactory.hpp"

namespace Controllers {
    WidgetController::Ptr WidgetControllerFactory::create(Widgets::WidgetType type) {
        switch (type) {
            case Widgets::BUTTON:
                return std::make_shared<Controllers::ButtonController>();
            case Widgets::TEXT_INPUT_FIELD:
                return std::make_shared<Controllers::TextInputFieldController>();
            case Widgets::IMAGE_BUTTON:
                return std::make_shared<Controllers::ImageButtonController>();
            case Widgets::MENU_BAR:
                return std::make_shared<Controllers::MenuBarController>();
            case Widgets::VERTICAL_LAYOUT:
            case Widgets::HORIZONTAL_LAYOUT:
                return std::make_shared<Controllers::LayoutController>();
            default:
                return nullptr;
        }
    }
}    //namespace Controllers
