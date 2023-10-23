//
// Created by VerOchka on 23.10.2023.
//
#include "SelectableForm.hpp"

namespace Forms {
    void SelectableForm::setCanvas(const GraphicLib::PickableTexture::Ptr &canvas) {
        SelectableForm::canvas = canvas;
    }
}

