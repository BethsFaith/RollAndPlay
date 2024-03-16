//
// Created by BethsFaith on 05.03.2024.
//

#ifndef INC_1_BIN_PAGESTYLEPARSER_HPP
#define INC_1_BIN_PAGESTYLEPARSER_HPP

#include <algorithm>
#include <unordered_map>

#include <GraphicLib/GuiObjects/WidgetType.hpp>
#include <GraphicLib/GuiObjects/LayoutType.hpp>
#include <GraphicLib/GuiObjects/WidgetBuilder.hpp>

#include "../config/Config.hpp"
#include "style/Color.hpp"

namespace Pages {
    class PageStyleParser {
    public:
        explicit PageStyleParser(Config::Config& config);

        bool parse(const std::string& filePath);

        GraphicLib::GuiObjects::WidgetBuilder::Ptr getWidgetBuilder(const std::string& page);
    protected:
        struct ResultType {
            GraphicLib::GuiObjects::WidgetType widgetType;
            GraphicLib::GuiObjects::LayoutType layoutType;
            bool error;
            bool isWidgetType;
        };

        ResultType getType(std::string type);
        Style::Color getColor(std::string color);

        void (PageStyleParser::*pullStyle)(Json::Value&, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullButtonStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullImageButtonStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullTextInputFieldStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullImageBoxStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullTextBoxStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullMenuBarStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);
        void pullScrollBoxStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::WidgetStyle::Ptr&);

        static void pullLayoutStyle(Json::Value& object, const GraphicLib::GuiObjects::Styles::LayoutStyle::Ptr&);

        std::unordered_map<std::string, GraphicLib::GuiObjects::WidgetType> widgetTypes = {
            {"button", GraphicLib::GuiObjects::BUTTON},
            {"image_button", GraphicLib::GuiObjects::IMAGE_BUTTON},
            {"text_input_field", GraphicLib::GuiObjects::TEXT_INPUT_FIELD},
            {"num_input_field", GraphicLib::GuiObjects::NUM_INPUT_FIELD},
            {"text_box", GraphicLib::GuiObjects::TEXT_BOX},
            {"image_box", GraphicLib::GuiObjects::IMAGE_BOX},
            {"scroll_box", GraphicLib::GuiObjects::SCROLL_BOX},
        };
        std::unordered_map<std::string, GraphicLib::GuiObjects::LayoutType> layoutTypes = {
            {"horizontal_layout", GraphicLib::GuiObjects::HORIZONTAL},
            {"vertical_layout", GraphicLib::GuiObjects::VERTICAL}
        };
        std::unordered_map<std::string, Style::Color> colors = {
            {"white",Style::Color::WHITE},
            {"gray", Style::Color::GRAY},
            {"black",Style::Color::BLACK},
            {"red", Style::Color::RED},
            {"green",Style::Color::GREEN},
            {"blue",Style::Color::BLUE},
            {"yellow",Style::Color::YELLOW},
            {"orange",Style::Color::ORANGE},
            {"violet", Style::Color::VIOLET},
            {"light_gray", Style::Color::LIGHT_GRAY},
            {"light_blue", Style::Color::LIGHT_BLUE},
            {"light_red", Style::Color::LIGHT_RED},
            {"light_violet", Style::Color::LIGHT_VIOLET},
            {"light_green", Style::Color::LIGHT_GREEN},
            {"light_orange", Style::Color::LIGHT_ORANGE},
            {"dark_gray", Style::Color::DARK_GRAY},
            {"dark_blue", Style::Color::DARK_BLUE},
            {"dark_green", Style::Color::DARK_GREEN},
            {"dark_red", Style::Color::DARK_RED},
            {"dark_orange", Style::Color::DARK_ORANGE},
        };

        GraphicLib::Objects::Primitives::Rectangle::Ptr _rectangle;
        GraphicLib::Objects::Primitives::Rectangle::Ptr _textureRectangle;

        Config::Config& _config;

        std::map<std::string, GraphicLib::GuiObjects::WidgetBuilder::Ptr> _pageWidgetBuilders;
    };
}    //namespace Pages

#endif    //INC_1_BIN_PAGESTYLEPARSER_HPP
