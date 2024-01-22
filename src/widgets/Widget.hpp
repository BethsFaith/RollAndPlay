//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_WIDGET_HPP
#define ROLLANDPLAY_WIDGET_HPP

#include <GraphicLib/PickableTexture.hpp>

#include "WidgetType.hpp"

namespace Widgets {
    class Widget {
    public:
        using Ptr = std::shared_ptr<Widget>;

        explicit Widget(WidgetType type);
        virtual ~Widget() = default;

        virtual bool checkSelecting(unsigned int x, unsigned int y) = 0;

        void setCanvas(const GraphicLib::PickableTexture::Ptr& canvas);

        [[nodiscard]] WidgetType getType() const;

    protected:
        GraphicLib::PickableTexture::Ptr canvas;

    private:
        WidgetType _type;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_WIDGET_HPP
