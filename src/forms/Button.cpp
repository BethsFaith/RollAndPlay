//
// Created by VerOchka on 06.10.2023.
//

#include "Button.hpp"

#include <utility>

namespace Forms {
    Button::Button(float x, float y) : _x(x), _y(y) {
    }

    void Button::press() {
        _pressCallback();
    }

    void Button::setPressCallback(const std::function<void()> &function) {
        _pressCallback = function;
    }

    float Button::getX() const {
        return _x;
    }

    float Button::getY() const {
        return _y;
    }
}