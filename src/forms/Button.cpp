//
// Created by VerOchka on 06.10.2023.
//

#include "Button.hpp"

namespace Forms {
    Button::Button(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {}

    void Button::press() {
        _pressCallback();
    }

    void Button::setPressCallback(const std::function<void()> &function) {
        _pressCallback = function;
    }

    float Button::getXOffset() const {
        return _xOffset;
    }

    float Button::getYOffset() const {
        return _yOffset;
    }
}