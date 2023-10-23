//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <iostream>
#include <functional>

#include "Color.hpp"
#include "../EntryPoint.hpp"

namespace Forms {
    class Button {
    public:
        using Ptr = std::shared_ptr<Button>;

        Button(float xOffset, float yOffset);
        ~Button() = default;

        void press();

        void setPressCallback(const std::function<void()> &function);

        [[nodiscard]] float getXOffset() const;

        [[nodiscard]] float getYOffset() const;

        float getId() const;

        Color color = Color::GREY;

    private:
        float _xOffset;
        float _yOffset;

        int _id;
        static int id;

        std::function<void()> _pressCallback{[]() {}};
    };
}

#endif //ROLLANDPLAY_BUTTON_HPP
