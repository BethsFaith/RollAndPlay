//
// Created by VerOchka on 06.10.2023.
//

#include "Button.hpp"

namespace Forms {
    int Button::IdCounter = 0;

    Button::Button(float xOffset, float yOffset) : _xOffset(xOffset), _yOffset(yOffset) {
        id = ++IdCounter;
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
        return id;
    }

    bool Button::checkSelecting(unsigned int x, unsigned int y) {
        if (canvas == nullptr) {
            return false;
        }

        auto info = canvas->readPixel(x, y);

        return id == (int)info.ObjectID;
    }
}