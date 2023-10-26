//
// Created by VerOchka on 26.10.2023.
//

#include "FormControllerFactory.hpp"

namespace Controllers {
    FormController::Ptr FormControllerFactory::create(Forms::FormType type) {
        switch (type) {
            case Forms::BUTTON:
                return std::make_shared<Controllers::ButtonController>();
            case Forms::INPUT_FIELD:
                return std::make_shared<Controllers::InputFieldController>();
        }
    }
}