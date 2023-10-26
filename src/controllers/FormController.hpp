//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_FORMCONTROLLER_HPP
#define ROLLANDPLAY_FORMCONTROLLER_HPP

#include "GLController.hpp"
#include "../forms/Form.hpp"

namespace Controllers {
    class FormController : public GLController {
    public:
        using Ptr = std::shared_ptr<FormController>;

        ~FormController() override = default;

        virtual void addForm(Forms::Form::Ptr form) = 0;
    };
}


#endif //ROLLANDPLAY_FORMCONTROLLER_HPP
