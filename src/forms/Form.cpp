//
// Created by VerOchka on 23.10.2023.
//
#include "Form.hpp"

namespace Forms {
    Form::Form(FormType type) : _type(type) {}

    void Form::setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) {
        Form::canvas = canvas;
    }

    FormType Form::getType() const {
        return _type;
    }
}    //namespace Forms
