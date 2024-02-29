//
// Created by BethsFaith on 26.02.2024.
//

#include "NumericInputField.hpp"

namespace Widgets {
    NumericInputField::NumericInputField(const GraphicLib::Primitives::Rectangle::Ptr& graphicPrimitive,
                                         Styles::TextParams inputParams)
        : TextInputField(graphicPrimitive, inputParams, NUM_INPUT_FIELD) {}

    void NumericInputField::putToBuffer(char16_t character) {
        if (isdigit(character)) {
            TextInputField::putToBuffer(character);
        }
    }

    void NumericInputField::putToBuffer(const std::string& string) {
        if (valid(string)) {
            TextInputField::putToBuffer(string);
        }
    }

    void NumericInputField::putToBuffer(const std::u16string& string) {
        if (valid(string)) {
            TextInputField::putToBuffer(string);
        }
    }

    void NumericInputField::putToBuffer(int number) {
        putToBuffer(std::to_string(number));
    }

    bool NumericInputField::valid(const std::u16string& string) {
        return valid(std::string{string.begin(), string.end()});
    }

    bool NumericInputField::valid(const std::string& string) {
        auto pos = string.begin();
        do {
            if (isdigit(*pos)) {
                ++pos;
            } else if (*pos == '-') {
                if (isdigit(*(pos+1))) {
                    pos += 2;
                } else {
                   return false;
                }
            }
        }
        while (pos != string.end());

        return true;
    }

    int NumericInputField::getNumBuffer() {
        std::string buf{_buf.begin(), _buf.end()};

        return std::stoi(buf);
    }
}    //namespace Widgets
