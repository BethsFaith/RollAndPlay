//
// Created by BethsFaith on 05.03.2024.
//

#ifndef INC_1_BIN_PAGESTYLEPARSER_HPP
#define INC_1_BIN_PAGESTYLEPARSER_HPP

#include <algorithm>
#include <unordered_map>

#include <GraphicLib/Widgets/WidgetType.hpp>
#include <GraphicLib/Widgets/LayoutType.hpp>
#include <GraphicLib/Widgets/Styles/Color.hpp>
#include <GraphicLib/Widgets/WidgetBuilder.hpp>

#include "../config/Config.hpp"
#include "style/Color.hpp"

namespace Pages {
    class PageStyleParser {
    public:
        explicit PageStyleParser(Config::Config& config);

        bool parse(const std::string& filePath);

        GraphicLib::Widgets::WidgetBuilder::Ptr getWidgetBuilder(const std::string& page);
    protected:
        struct ResultType {
            GraphicLib::Widgets::WidgetType widgetType;
            GraphicLib::Widgets::LayoutType layoutType;
            bool error;
            bool isWidgetType;
        };

        ResultType getType(std::string type);
        Style::Color getColor(std::string color);

        void (PageStyleParser::*pullStyle)(Json::Value&, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullButtonStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullImageButtonStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullTextInputFieldStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullImageBoxStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullTextBoxStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);
        void pullMenuBarStyle(Json::Value& object, const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&);

        static void pullLayoutStyle(Json::Value& object, const GraphicLib::Widgets::Styles::LayoutStyle::Ptr&);

        std::unordered_map<std::string, GraphicLib::Widgets::WidgetType> widgetTypes = {
            {"button", GraphicLib::Widgets::BUTTON},
            {"image_button", GraphicLib::Widgets::IMAGE_BUTTON},
            {"text_input_field", GraphicLib::Widgets::TEXT_INPUT_FIELD},
            {"num_input_field", GraphicLib::Widgets::NUM_INPUT_FIELD},
            {"text_box", GraphicLib::Widgets::TEXT_BOX},
            {"image_box", GraphicLib::Widgets::IMAGE_BOX},
        };
        std::unordered_map<std::string, GraphicLib::Widgets::LayoutType> layoutTypes = {
            {"horizontal_layout", GraphicLib::Widgets::HORIZONTAL},
            {"vertical_layout", GraphicLib::Widgets::VERTICAL}
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

        std::map<std::string, GraphicLib::Widgets::WidgetBuilder::Ptr> _pageWidgetBuilders;
    };
}    //namespace Pages

#endif    //INC_1_BIN_PAGESTYLEPARSER_HPP
