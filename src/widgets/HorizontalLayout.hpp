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

        HorizontalLayout();
        ~HorizontalLayout() = default;

        void addWidget(const Widget::Ptr& widget) override;
        void removeWidget(const Widget::Ptr& widget) override;
        void clear() override;
        glm::vec2 getScale() override;
        void addLayout(Layout::Ptr layout) override;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_HORIZONTALLAYOUT_HPP
