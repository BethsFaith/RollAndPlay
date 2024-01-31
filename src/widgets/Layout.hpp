//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_LAYOUT_HPP
#define ROLLANDPLAY_LAYOUT_HPP

#include "Widget.hpp"

namespace Widgets {
    class Layout : public Widget{
    public:
        Layout();
        ~Layout() override = default;

        void draw(GraphicLib::Shaders::ShaderProgram::Ptr formShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr textShader,
                  GraphicLib::Shaders::ShaderProgram::Ptr pickShader) override;

        void setCanvas(const GraphicLib::PickableTexture::Ptr& canvas) override;

        virtual void addWidget(const Widget::Ptr& widget);
        virtual void removeWidget(const Widget::Ptr& widget);

    protected:
        std::vector<Widget::Ptr> _widgets;
    private:
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_LAYOUT_HPP
