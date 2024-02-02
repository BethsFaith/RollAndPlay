//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_HORIZONTALLAYOUT_HPP
#define ROLLANDPLAY_HORIZONTALLAYOUT_HPP

#include "Layout.hpp"

namespace Widgets {
    class HorizontalLayout : public Layout {
    public:
        explicit HorizontalLayout();
        ~HorizontalLayout() override = default;

        void addWidget(const Ptr& widget) override;
        void removeWidget(const Ptr& widget) override;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_HORIZONTALLAYOUT_HPP
