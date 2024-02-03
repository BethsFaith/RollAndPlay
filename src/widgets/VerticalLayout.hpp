//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_VERTICALLAYOUT_HPP
#define ROLLANDPLAY_VERTICALLAYOUT_HPP

#include "Layout.hpp"

namespace Widgets {
    class VerticalLayout : public Layout {
    public:
        using Ptr = std::shared_ptr<VerticalLayout>;

        explicit VerticalLayout();
        ~VerticalLayout() override = default;

        void addWidget(const Widget::Ptr& widget) override;
        void removeWidget(const Widget::Ptr& widget) override;
    };
}
#endif    //ROLLANDPLAY_VERTICALLAYOUT_HPP
