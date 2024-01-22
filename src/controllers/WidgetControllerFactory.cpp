//
// Created by VerOchka on 26.10.2023.
//

#include "WidgetControllerFactory.hpp"

namespace Controllers {
    WidgetController::Ptr WidgetControllerFactory::create(Widgets::WidgetType type) {
        switch (type) {
            case Widgets::BUTTON:
                return std::make_shared<Controllers::ButtonController>();
            case Widgets::TEXT_FORM:
                return std::make_shared<Controllers::TextFormController>();
            case Widgets::IMAGE_BUTTON:
                return std::make_shared<Controllers::ImageButtonController>();
            default:
                return nullptr;
        }
    }
}    //namespace Controllers
