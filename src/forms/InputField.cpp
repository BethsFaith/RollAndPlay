//
// Created by VeraTag on 25.10.2023.
//

#include "InputField.hpp"

namespace Forms {
    InputField::InputField(const GraphicLib::Primitives::AbstractPrimitive::Ptr& graphicPrimitive)
    : Button(graphicPrimitive, FormType::INPUT_FIELD) {}

    const std::string &InputField::getBuf() const {
        return _buf;
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
