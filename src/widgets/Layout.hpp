//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_LAYOUT_HPP
#define ROLLANDPLAY_LAYOUT_HPP

#include "Widget.hpp"
#include "LayoutType.hpp"

namespace Widgets {
    class Layout {
    public:
        using Ptr = std::shared_ptr<Layout>;

        explicit Layout(LayoutType type);
        ~Layout() = default;

        virtual void clear() = 0;
        virtual void putLayout(Layout::Ptr layout) = 0;

        virtual void putWidget(const Widget::Ptr& widget);
        virtual void removeWidget(const Widget::Ptr& widget);

        virtual glm::vec2 getScale();
        virtual glm::vec2 getPosition();

        void setProjection(float minX, float maxX, float minY, float maxY);
        void setTransform(glm::vec2 position, glm::vec2 scale);
        void setTransform(glm::vec2 position);
        void setWidgetOffset(float offset);
        void setScale(glm::vec2 elemScale);

        [[nodiscard]] LayoutType getType() const;
        [[nodiscard]] const std::vector<Widget::Ptr>& getWidgets() const;
    protected:
        std::vector<Widget::Ptr> widgets;

        float widgetOffset = 0.1f;

        glm::vec2 position{};
        glm::vec2 elemScale{};
        glm::vec2 scale{};

    private:
        LayoutType _type;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_LAYOUT_HPP
