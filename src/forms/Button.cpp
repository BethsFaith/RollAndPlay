//
// Created by VerOchka on 06.10.2023.
//

#include "Button.hpp"

namespace Forms {
    int Button::id = 0;

    Button::Button(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {
        _id = ++id;
    }

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

    float Button::getId() const {
        return _id;
    }

    bool Button::checkSelecting(unsigned int x, unsigned int y) {
        if (canvas == nullptr) {
            return false;
        }

        auto info = canvas->readPixel(x, y);

        return _id == (int)info.ObjectID;
    }
}