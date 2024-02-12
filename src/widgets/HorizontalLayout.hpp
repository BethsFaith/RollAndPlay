//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_HORIZONTALLAYOUT_HPP
#define ROLLANDPLAY_HORIZONTALLAYOUT_HPP

#include "Layout.hpp"

namespace Widgets {
    class HorizontalLayout : public Layout {
    public:
        using Ptr = std::shared_ptr<HorizontalLayout>;

        explicit HorizontalLayout();
        ~HorizontalLayout() override = default;

        void addWidget(const Widget::Ptr& widget) override;
        void removeWidget(const Widget::Ptr& widget) override;
        void clear() override;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_HORIZONTALLAYOUT_HPP
