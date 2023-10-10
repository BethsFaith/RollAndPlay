//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <iostream>
#include <functional>

#include "Color.hpp"

namespace Forms {
    class Button {
    public:
        Button(float x, float y);

        virtual ~Button() = default;

        void press();

        void setPressCallback(const std::function<void()> &function);

        [[nodiscard]] float getX() const;

        [[nodiscard]] float getY() const;

        Color color = Color::GREY;
    private:
        float _x;
        float _y;

        std::function<void()> _pressCallback{[]() {}};
    };
}

#endif //ROLLANDPLAY_BUTTON_HPP
