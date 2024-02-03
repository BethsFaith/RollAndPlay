//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_WIDGETFACTORY_HPP
#define ROLLANDPLAY_WIDGETFACTORY_HPP

#include "ImageButton.hpp"
#include "HorizontalLayout.hpp"
#include "VerticalLayout.hpp"
#include "MenuBar.hpp"
#include "TextBox.hpp"
#include "TextInputField.hpp"
#include "WidgetType.hpp"
#include "styles/ButtonStyle.hpp"
#include "styles/WidgetStyle.hpp"
#include "styles/ImageButtonStyle.hpp"
#include "styles/TextBoxStyle.hpp"
#include "styles/TextInputFieldStyle.hpp"
#include "styles/MenuBarStyle.hpp"
#include "styles/LayoutStyle.hpp"

namespace Widgets {
    class WidgetFactory {
    public:
        static Widget::Ptr create(WidgetType type, const Styles::WidgetStyle::Ptr&);

    private:
        WidgetFactory() = default;
        ~WidgetFactory() = default;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_WIDGETFACTORY_HPP
