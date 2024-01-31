//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_HORIZONTALLAYOUT_HPP
#define ROLLANDPLAY_HORIZONTALLAYOUT_HPP

#include "Layout.hpp"

namespace Widgets {
    class HorizontalLayout : public Layout {
    public:
        explicit HorizontalLayout(glm::vec2 pos);
        ~HorizontalLayout() override = default;

        void addWidget(const Ptr& widget) override;
        void removeWidget(const Ptr& widget) override;
    private:
        glm::vec2 _position;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_HORIZONTALLAYOUT_HPP
