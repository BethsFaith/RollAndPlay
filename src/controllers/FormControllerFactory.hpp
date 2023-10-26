//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP
#define ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP

#include "ButtonController.hpp"
#include "InputFieldController.hpp"
#include "../forms/FormType.hpp"

namespace Controllers {
    class FormControllerFactory {
    public:
        static FormController::Ptr create(Forms::FormType type);

    private:
        FormControllerFactory() = default;
        ~FormControllerFactory() = default;
    };
}

#endif //ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP
