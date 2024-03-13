//
// Created by BethsFaith on 05.03.2024.
//

#include "PageStyleParser.hpp"

namespace Pages {
    PageStyleParser::PageStyleParser(Config::Config& config) : _config(config) {
        _rectangle = std::make_shared<GraphicLib::Objects::Primitives::Rectangle>(
            GraphicLib::Objects::Primitives::Primitive::Settings{.with_normals = false,
                                                                 .with_texture_coords = false,
                                                                 .with_tangent = false,
                                                                 .with_bitangent = false});
        _textureRectangle = std::make_shared<GraphicLib::Objects::Primitives::Rectangle>(
            GraphicLib::Objects::Primitives::Primitive::Settings{.with_normals = false,
                                                                 .with_texture_coords = true,
                                                                 .with_tangent = false,
                                                                 .with_bitangent = false});
        _rectangle->bindData(GL_STATIC_DRAW);
        _textureRectangle->bindData(GL_STATIC_DRAW);
    }

    bool PageStyleParser::parse(const std::string& filePath) {
        GraphicLib::Widgets::WidgetBuilder::Ptr defaultWidgetBuilder =
            std::make_shared<GraphicLib::Widgets::WidgetBuilder>();

        std::ifstream ifstream(filePath, std::ifstream::binary);

        if (!ifstream.is_open()) {
            return false;
        }

        Json::Reader reader;
        Json::Value obj;
        reader.parse(ifstream, obj);

        ifstream.close();

        auto theme = "default";
        if (obj.isMember(theme)) {
            if (!obj[theme].isArray()) {
                return false;
            }
            auto defaultTheme = obj[theme];
            auto size = defaultTheme.size();
            for (int styleIndex{}; styleIndex < size; ++styleIndex) {
                auto style = defaultTheme[styleIndex];
                auto type = getType(style["type"].asString());

                std::function<void(GraphicLib::Widgets::Styles::WidgetStyle::Ptr&,
                                   const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&)>
                    styleInitialization;
                pullStyle = &PageStyleParser::pullTextInputFieldStyle;

                if (!type.error) {
                    if (type.isWidgetType) {
                        switch (type.widgetType) {
                            case GraphicLib::Widgets::NUM_INPUT_FIELD:
                            case GraphicLib::Widgets::TEXT_INPUT_FIELD: {
                                styleInitialization =
                                    [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                       const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::TextInputFieldStyle>();
                                        } else {
                                            widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::TextInputFieldStyle>(
                                                    *std::dynamic_pointer_cast<
                                                        GraphicLib::Widgets::Styles::TextInputFieldStyle>(copyStyle));
                                        }
                                    };

                                pullStyle = &PageStyleParser::pullTextInputFieldStyle;

                                break;
                            }
                            case GraphicLib::Widgets::IMAGE_BUTTON: {
                                styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                         const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                             copyStyle) {
                                    if (copyStyle == nullptr) {
                                        widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ImageButtonStyle>();
                                    } else {
                                        widgetStyle = widgetStyle = std::make_shared<
                                            GraphicLib::Widgets::Styles::ImageButtonStyle>(
                                            *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageButtonStyle>(
                                                copyStyle));
                                    }
                                };

                                pullStyle = &PageStyleParser::pullImageButtonStyle;

                                break;
                            }
                            case GraphicLib::Widgets::TEXT_BOX: {
                                styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                         const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                             copyStyle) {
                                    if (copyStyle == nullptr) {
                                        widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::TextBoxStyle>();
                                    } else {
                                        widgetStyle = widgetStyle =
                                            std::make_shared<GraphicLib::Widgets::Styles::TextBoxStyle>(
                                                *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::TextBoxStyle>(
                                                    copyStyle));
                                    }
                                };

                                pullStyle = &PageStyleParser::pullTextBoxStyle;

                                break;
                            }
                            case GraphicLib::Widgets::IMAGE_BOX: {
                                styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                         const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                             copyStyle) {
                                    if (copyStyle == nullptr) {
                                        widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ImageBoxStyle>();
                                    } else {
                                        widgetStyle = widgetStyle =
                                            std::make_shared<GraphicLib::Widgets::Styles::ImageBoxStyle>(
                                                *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageBoxStyle>(
                                                    copyStyle));
                                    }
                                };

                                pullStyle = &PageStyleParser::pullImageBoxStyle;

                                break;
                            }
                            case GraphicLib::Widgets::MENU_BAR: {
                                styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                         const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                             copyStyle) {
                                    if (copyStyle == nullptr) {
                                        widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::MenuBarStyle>();
                                    } else {
                                        widgetStyle = widgetStyle =
                                            std::make_shared<GraphicLib::Widgets::Styles::MenuBarStyle>(
                                                *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::MenuBarStyle>(
                                                    copyStyle));
                                    }
                                };
                                pullStyle = &PageStyleParser::pullMenuBarStyle;

                                break;
                            }
                            case GraphicLib::Widgets::BUTTON: {
                                styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                         const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                             copyStyle) {
                                    if (copyStyle == nullptr) {
                                        widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ButtonStyle>();
                                    } else {
                                        widgetStyle = widgetStyle =
                                            std::make_shared<GraphicLib::Widgets::Styles::ButtonStyle>(
                                                *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ButtonStyle>(
                                                    copyStyle));
                                    }
                                };

                                pullStyle = &PageStyleParser::pullButtonStyle;

                                break;
                            }
                        }
                        GraphicLib::Widgets::Styles::WidgetStyle::Ptr widgetStyle;

                        styleInitialization(widgetStyle, nullptr);

                        (this->*pullStyle)(style, widgetStyle);

                        defaultWidgetBuilder->addWidgetStyle(type.widgetType, theme, widgetStyle);

                        auto classes = style["classes"];
                        if (classes.isArray()) {
                            for (int classIndex{}; classIndex < classes.size(); ++classIndex) {
                                auto classElem = classes[classIndex];

                                GraphicLib::Widgets::Styles::WidgetStyle::Ptr subStyle;

                                styleInitialization(subStyle, widgetStyle);

                                (this->*pullStyle)(classElem, subStyle);

                                defaultWidgetBuilder->addWidgetStyle(type.widgetType,
                                                                     classElem["class"].asString(),
                                                                     subStyle);
                            }
                        }
                    } else {
                        switch (type.layoutType) {
                            case GraphicLib::Widgets::HORIZONTAL:
                            case GraphicLib::Widgets::VERTICAL: {
                                auto layoutStyle = std::make_shared<GraphicLib::Widgets::Styles::LayoutStyle>();

                                pullLayoutStyle(style, layoutStyle);

                                defaultWidgetBuilder->addLayoutStyle(type.layoutType, layoutStyle);

                                break;
                            }
                        }
                    }
                }
            }
            _pageWidgetBuilders["skill"] = defaultWidgetBuilder;
            _pageWidgetBuilders["login"] = defaultWidgetBuilder;
            _pageWidgetBuilders["registration"] = defaultWidgetBuilder;
            _pageWidgetBuilders["action"] = defaultWidgetBuilder;
            _pageWidgetBuilders["system"] = defaultWidgetBuilder;
            _pageWidgetBuilders["race"] = defaultWidgetBuilder;
            _pageWidgetBuilders["characteristic"] = defaultWidgetBuilder;
            _pageWidgetBuilders["characterClass"] = defaultWidgetBuilder;
            _pageWidgetBuilders["item"] = defaultWidgetBuilder;
        }

        if (obj.isMember("pages")) {
            if (!obj["pages"].isArray()) {
                return false;
            }
            auto pages = obj["pages"];
            for (int pageIndex{}; pageIndex < pages.size(); ++pageIndex) {
                auto page = pages[pageIndex]["page"].asString();
                auto pageTheme = pages[pageIndex]["theme"];

                auto pageWidgetBuilder = std::make_shared<GraphicLib::Widgets::WidgetBuilder>(
                    *defaultWidgetBuilder);

                for (int styleIndex{}; styleIndex < pageTheme.size(); ++styleIndex) {
                    auto style = pageTheme[styleIndex];
                    auto type = getType(style["type"].asString());

                    if (!type.error) {
                        if (type.isWidgetType) {

                            std::function<void(GraphicLib::Widgets::Styles::WidgetStyle::Ptr&,
                                               const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&)>
                                styleInitialization;
                            pullStyle = &PageStyleParser::pullTextInputFieldStyle;

                            switch (type.widgetType) {
                                case GraphicLib::Widgets::NUM_INPUT_FIELD:
                                case GraphicLib::Widgets::TEXT_INPUT_FIELD: {
                                    styleInitialization =
                                        [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                           const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& copyStyle) {
                                            if (copyStyle == nullptr) {
                                                widgetStyle =
                                                    std::make_shared<GraphicLib::Widgets::Styles::TextInputFieldStyle>();
                                            } else {
                                                widgetStyle =
                                                    std::make_shared<GraphicLib::Widgets::Styles::TextInputFieldStyle>(
                                                        *std::dynamic_pointer_cast<
                                                            GraphicLib::Widgets::Styles::TextInputFieldStyle>(copyStyle));
                                            }
                                        };

                                    pullStyle = &PageStyleParser::pullTextInputFieldStyle;

                                    break;
                                }
                                case GraphicLib::Widgets::IMAGE_BUTTON: {
                                    styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                             const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                                 copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ImageButtonStyle>();
                                        } else {
                                            widgetStyle = widgetStyle = std::make_shared<
                                                GraphicLib::Widgets::Styles::ImageButtonStyle>(
                                                *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageButtonStyle>(
                                                    copyStyle));
                                        }
                                    };

                                    pullStyle = &PageStyleParser::pullImageButtonStyle;

                                    break;
                                }
                                case GraphicLib::Widgets::TEXT_BOX: {
                                    styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                             const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                                 copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::TextBoxStyle>();
                                        } else {
                                            widgetStyle = widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::TextBoxStyle>(
                                                    *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::TextBoxStyle>(
                                                        copyStyle));
                                        }
                                    };

                                    pullStyle = &PageStyleParser::pullTextBoxStyle;

                                    break;
                                }
                                case GraphicLib::Widgets::IMAGE_BOX: {
                                    styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                             const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                                 copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ImageBoxStyle>();
                                        } else {
                                            widgetStyle = widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::ImageBoxStyle>(
                                                    *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageBoxStyle>(
                                                        copyStyle));
                                        }
                                    };

                                    pullStyle = &PageStyleParser::pullImageBoxStyle;

                                    break;
                                }
                                case GraphicLib::Widgets::MENU_BAR: {
                                    styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                             const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                                 copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::MenuBarStyle>();
                                        } else {
                                            widgetStyle = widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::MenuBarStyle>(
                                                    *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::MenuBarStyle>(
                                                        copyStyle));
                                        }
                                    };
                                    pullStyle = &PageStyleParser::pullMenuBarStyle;

                                    break;
                                }
                                case GraphicLib::Widgets::BUTTON: {
                                    styleInitialization = [](GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle,
                                                             const GraphicLib::Widgets::Styles::WidgetStyle::Ptr&
                                                                 copyStyle) {
                                        if (copyStyle == nullptr) {
                                            widgetStyle = std::make_shared<GraphicLib::Widgets::Styles::ButtonStyle>();
                                        } else {
                                            widgetStyle = widgetStyle =
                                                std::make_shared<GraphicLib::Widgets::Styles::ButtonStyle>(
                                                    *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ButtonStyle>(
                                                        copyStyle));
                                        }
                                    };

                                    pullStyle = &PageStyleParser::pullButtonStyle;

                                    break;
                                }
                            }
                            GraphicLib::Widgets::Styles::WidgetStyle::Ptr widgetStyle;

                            styleInitialization(widgetStyle, defaultWidgetBuilder->getWidgetStyle(type.widgetType));

                            (this->*pullStyle)(style, widgetStyle);

                            pageWidgetBuilder->addWidgetStyle(type.widgetType, theme, widgetStyle);

                            auto classes = style["classes"];
                            for (int classIndex{}; classIndex < classes.size(); ++classIndex) {
                                auto classElem = classes[classIndex];

                                GraphicLib::Widgets::Styles::WidgetStyle::Ptr subStyle;
                                styleInitialization(subStyle, widgetStyle);

                                (this->*pullStyle)(classElem, subStyle);

                                pageWidgetBuilder->addWidgetStyle(type.widgetType,
                                                                  classElem["class"].asString(),
                                                                  subStyle);
                            }
                        } else {
                            switch (type.layoutType) {
                                case GraphicLib::Widgets::HORIZONTAL:
                                case GraphicLib::Widgets::VERTICAL: {
                                    auto layoutStyle = std::make_shared<GraphicLib::Widgets::Styles::LayoutStyle>(
                                        *std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::LayoutStyle>(
                                            defaultWidgetBuilder->getLayoutStyle(type.layoutType)));

                                    pullLayoutStyle(style, layoutStyle);

                                    pageWidgetBuilder->addLayoutStyle(type.layoutType, layoutStyle);
                                }
                            }
                        }
                    }
                }
                _pageWidgetBuilders[page] = pageWidgetBuilder;
            }
        }
    }

    PageStyleParser::ResultType PageStyleParser::getType(std::string type) {
        ResultType res{};

        std::transform(type.begin(), type.end(), type.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        auto wIt = widgetTypes.find(type);
        if (wIt != widgetTypes.end()) {
            res.isWidgetType = true;
            res.widgetType = wIt->second;
        } else {
            res.isWidgetType = false;

            auto lIt = layoutTypes.find(type);
            if (lIt != layoutTypes.end()) {
                res.layoutType = lIt->second;
            } else {
                res.error = true;
            }
        }

        return res;
    }

    GraphicLib::Widgets::Styles::Color PageStyleParser::getColor(std::string color) {
        std::transform(color.begin(), color.end(), color.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        auto it = colors.find(color);
        if (it != colors.end()) {
            return it->second;
        } else {
            return GraphicLib::Widgets::Styles::WHITE;
        }
    }

    void PageStyleParser::pullButtonStyle(Json::Value& object,
                                          const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle) {
        auto style = std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ButtonStyle>(widgetStyle);
        if (object.isMember("color")) {
            style->color = getColor(object["color"].asString());
        }
        if (object.isMember("trace_color")) {
            style->traceColor = getColor(object["trace_color"].asString());
        }
        if (object.isMember("press_color")) {
            style->pressColor = getColor(object["press_color"].asString());
        }
        if (object.isMember("label")) {
            auto label = object["label"];
            style->labelParams = {.color = getColor(label["color"].asString()), .size = label["size"].asFloat()};
        }
        if (object.isMember("scale")) {
            auto scale = object["scale"];
            style->scale = {scale["x"].asFloat(), scale["y"].asFloat()};
        }
        if (object.isMember("figure")) {
            auto type = object["figure"]["type"].asString();
            if (type == "rectangle") {
                style->figure = _rectangle;
            } else if (type == "texture_rectangle") {
                style->figure = _textureRectangle;
            }
        }
    }

    void PageStyleParser::pullImageButtonStyle(Json::Value& object,
                                               const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle) {
        pullButtonStyle(object, widgetStyle);

        auto style = std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageButtonStyle>(widgetStyle);

        if (object.isMember("figure")) {
            auto type = object["figure"]["type"].asString();
            if (type == "rectangle") {
                style->figure = _rectangle;
            } else if (type == "texture_rectangle") {
                auto defaultTexture = object["figure"]["default_texture"];
                auto path = defaultTexture["config_path"].asString();

                style->defaultTexturePath = _config.getTexturePath(path);
                style->defaultTextureIndex = defaultTexture["index"].asInt();
                style->figure = _textureRectangle;
            }
        }
    }

    void PageStyleParser::pullTextInputFieldStyle(Json::Value& object,
                                                  const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle) {
        auto style = std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::TextInputFieldStyle>(widgetStyle);

        pullButtonStyle(object, style);

        if (object.isMember("input")) {
            auto input = object["input"];
            style->inputParams = {.color = getColor(input["color"].asString()), .size = input["size"].asFloat()};
        }
    }

    void PageStyleParser::pullImageBoxStyle(Json::Value& object,
                                            const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle) {
        auto style = std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::ImageBoxStyle>(widgetStyle);

        if (object.isMember("label")) {
            auto label = object["label"];
            style->labelParams = {.color = getColor(label["color"].asString()), .size = label["size"].asFloat()};
        }
        if (object.isMember("scale")) {
            auto scale = object["scale"];
            style->scale = {scale["x"].asFloat(), scale["y"].asFloat()};
        }
        if (object.isMember("figure")) {
            auto type = object["figure"]["type"].asString();
            if (type == "rectangle") {
                style->figure = _rectangle;
            } else if (type == "texture_rectangle") {
                auto defaultTexture = object["figure"]["default_texture"];
                auto path = defaultTexture["config_path"].asString();

                style->defaultTexturePath = _config.getTexturePath(path);
                style->defaultTextureIndex = defaultTexture["index"].asInt();
                style->figure = _textureRectangle;
            }
        }
    }

    void PageStyleParser::pullTextBoxStyle(Json::Value& object,
                                           const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& widgetStyle) {
        auto style = std::dynamic_pointer_cast<GraphicLib::Widgets::Styles::TextBoxStyle>(widgetStyle);

        if (object.isMember("color")) {
            style->color = getColor(object["color"].asString());
        }
        if (object.isMember("label")) {
            auto label = object["label"];
            style->textLabelParams = {.color = getColor(label["color"].asString()), .size = label["size"].asFloat()};
        }
        if (object.isMember("scale")) {
            auto scale = object["scale"];
            style->scale = {scale["x"].asFloat(), scale["y"].asFloat()};
        }
    }

    void PageStyleParser::pullMenuBarStyle(Json::Value& object,
                                           const GraphicLib::Widgets::Styles::WidgetStyle::Ptr& style) {
        if (object.isMember("scale")) {
            auto scale = object["scale"];
            style->scale = {scale["x"].asFloat(), scale["y"].asFloat()};
        }
    }

    void PageStyleParser::pullLayoutStyle(Json::Value& object,
                                          const GraphicLib::Widgets::Styles::LayoutStyle::Ptr& style) {
        if (object.isMember("widgets")) {
            style->widgetOffset = object["widgets"]["offset"].asFloat();
        }
    }

    GraphicLib::Widgets::WidgetBuilder::Ptr PageStyleParser::getWidgetBuilder(const std::string& page) {
        auto it = _pageWidgetBuilders.find(page);
        if (it != _pageWidgetBuilders.end()) {
            return it->second;
        } else {
            return nullptr;
        }
    }
}    //namespace Pages
