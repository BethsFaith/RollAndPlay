//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <iostream>
#include <functional>

#include <EntryPoint.hpp>

#include "SelectableForm.hpp"
#include "Color.hpp"

namespace Forms {
    class Button : public SelectableForm {
    public:
        using Ptr = std::shared_ptr<Button>;

        Button(float xOffset, float yOffset);
        ~Button() = default;

        void press();

        void setPressCallback(const std::function<void()> &function);

        [[nodiscard]] float getXOffset() const;
        [[nodiscard]] float getYOffset() const;
        [[nodiscard]] float getId() const;

        bool checkSelecting(unsigned int x, unsigned int y) override;

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
