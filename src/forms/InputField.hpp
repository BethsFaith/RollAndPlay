//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_INPUTFIELD_HPP
#define ROLLANDPLAY_INPUTFIELD_HPP

#include <iostream>
#include <utility>

#include "Button.hpp"

namespace Forms {
    class InputField : public Button {
    public:
        using Ptr = std::shared_ptr<InputField>;

        explicit InputField(float xOffset, float yOffset, std::string title);
        ~InputField() override = default;

        void putToBuffer(char character);
        void popFromBuffer();
        void clear();

        [[nodiscard]] const std::string& getBuf() const;
        [[nodiscard]] const std::string& getTitle() const;
    private:
        std::string _buf;
    };
}
#endif    //ROLLANDPLAY_INPUTFIELD_HPP
