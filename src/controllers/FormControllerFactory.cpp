//
// Created by VerOchka on 26.10.2023.
//

#include "FormControllerFactory.hpp"

namespace Controllers {
    FormController::Ptr FormControllerFactory::create(Forms::FormType type) {
        switch (type) {
            case Forms::COLOR_BUTTON:
                return std::make_shared<Controllers::ButtonController>();
            case Forms::INPUT_FIELD:
                return std::make_shared<Controllers::InputFieldController>();
            case Forms::TEXTURE_BUTTON:
                return std::make_shared<Controllers::ImageButtonController>();
            default:
                return nullptr;
        }
    }
}    //namespace Controllers
