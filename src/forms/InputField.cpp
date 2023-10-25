//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

namespace Forms {
    InputField::InputField(float xOffset, float yOffset, std::string title) :
          Button(xOffset, yOffset) {
        title = std::move(title);
    }

    const std::string& InputField::getBuf() const {
        return _buf;
    }

    const std::string& InputField::getTitle() const {
        return title;
    }

    void InputField::putToBuffer(char character) {
        _buf += character;
    }

    void InputField::popFromBuffer() {
        if (!_buf.empty()) {
            _buf.erase(_buf.back());
        }
    }

    void InputField::clear() {
        _buf.clear();
    }
}
