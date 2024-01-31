//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_VERTICALLAYOUT_HPP
#define ROLLANDPLAY_VERTICALLAYOUT_HPP

#include "Layout.hpp"

namespace Widgets {
    class VerticalLayout : public Layout {
    public:
        explicit VerticalLayout(glm::vec2 pos);
        ~VerticalLayout() override = default;
        void addWidget(const Ptr& widget) override;
        void removeWidget(const Ptr& widget) override;

    private:
        glm::vec2 _position;
    };
}
#endif    //ROLLANDPLAY_VERTICALLAYOUT_HPP
