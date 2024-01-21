//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP
#define ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP

#include "../forms/FormType.hpp"
#include "ButtonController.hpp"
#include "ImageButtonController.hpp"
#include "InputFieldController.hpp"

namespace Controllers {
    class FormControllerFactory {
    public:
        static FormController::Ptr create(Forms::FormType type);

    private:
        FormControllerFactory() = default;
        ~FormControllerFactory() = default;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_FORMCONTROLLERFACTORY_HPP
