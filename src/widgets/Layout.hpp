//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_LAYOUT_HPP
#define ROLLANDPLAY_LAYOUT_HPP

#include "Widget.hpp"

namespace Widgets {
    class Layout : public Widget{
    public:
        using Ptr = std::shared_ptr<Layout>;

        explicit Layout(WidgetType type);
        ~Layout() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr colorShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textureShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        void setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) override;

        void setProjection(float minX, float maxX, float minY, float maxY) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        virtual void clear() = 0;

        virtual void addWidget(const Widget::Ptr& widget);
        virtual void removeWidget(const Widget::Ptr& widget);

        void setWidgetOffset(float offset);

        [[nodiscard]] const std::vector<Widget::Ptr>& getWidgets() const;
    protected:
        std::vector<Widget::Ptr> widgets;

        float widgetOffset = 0.1f;

        glm::vec2 position{};
        glm::vec2 scale{};
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_LAYOUT_HPP
