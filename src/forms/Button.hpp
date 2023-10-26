//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <iostream>
#include <functional>

#include <GraphicLib/GlagGlfw.hpp>

#include "SelectableForm.hpp"
#include "Color.hpp"

namespace Forms {
    class Button : public SelectableForm {
    public:
        using Ptr = std::shared_ptr<Button>;

        Button(float xOffset, float yOffset);
        virtual ~Button() = default;

        void press();

        void setPressCallback(const std::function<void()> &function);

        [[nodiscard]] float getXOffset() const;
        [[nodiscard]] float getYOffset() const;
        [[nodiscard]] float getId() const;
        [[nodiscard]] bool isSelected() const;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setSelected(bool isSelected);

        Color color = Color::GRAY;
        std::string title;
        glm::vec3 scale;

    protected:
        float _xOffset;
        float _yOffset;

        int id;
        static int IdCounter;

        bool _isSelected;

        std::function<void()> _pressCallback{[]() {}};
    };
}

#endif //ROLLANDPLAY_BUTTON_HPP
