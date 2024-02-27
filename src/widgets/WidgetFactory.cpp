//
// Created by BethsFaith on 31.01.2024.
//

#include "WidgetFactory.hpp"

namespace Widgets {
    Widget::Ptr WidgetFactory::create(WidgetType type, const Styles::WidgetStyle::Ptr& style) {
        Widget::Ptr result;
        switch (type) {
            case TEXT_INPUT_FIELD:{
                auto textInputFieldStyle = std::dynamic_pointer_cast<Styles::TextInputFieldStyle>(style);
                auto textInputField = std::make_shared<TextInputField>
                    (std::dynamic_pointer_cast<GraphicLib::Primitives::Rectangle>(textInputFieldStyle->figure),
                                                                       textInputFieldStyle->inputParams);

                if (textInputField != nullptr && textInputFieldStyle != nullptr) {
                    textInputField->setLabelParams(textInputFieldStyle->labelParams);
                    textInputField->setColor(textInputFieldStyle->color);
                    textInputField->setTraceColor(textInputFieldStyle->traceColor);
                }

                result = textInputField;

                break;
            }
            case NUM_INPUT_FIELD: {
                auto inputFieldStyle = std::dynamic_pointer_cast<Styles::TextInputFieldStyle>(style);
                auto numInputField = std::make_shared<NumericInputField>
                    (std::dynamic_pointer_cast<GraphicLib::Primitives::Rectangle>(inputFieldStyle->figure),
                    inputFieldStyle->inputParams);

                if (numInputField != nullptr && inputFieldStyle != nullptr) {
                    numInputField->setLabelParams(inputFieldStyle->labelParams);
                    numInputField->setColor(inputFieldStyle->color);
                    numInputField->setTraceColor(inputFieldStyle->traceColor);
                }

                result = numInputField;

                break;
            }
            case IMAGE_BUTTON: {
                auto imageButtonStyle = std::dynamic_pointer_cast<Styles::ImageButtonStyle>(style);
                auto imageButton = std::make_shared<ImageButton>(imageButtonStyle->figure);

                if (imageButton != nullptr && imageButtonStyle != nullptr) {
                    imageButton->setLabelParams(imageButtonStyle->labelParams);
                    imageButton->setTraceColor(imageButtonStyle->traceColor);
                    imageButton->setDefaultImage(imageButtonStyle->defaultTexturePath,
                                          imageButtonStyle->defaultTextureIndex);
                }

                result = imageButton;

                break;
            }
            case TEXT_BOX: {
                auto textBoxStyle = std::dynamic_pointer_cast<Styles::TextBoxStyle>(style);
                auto textBox = std::make_shared<TextBox>();

                if (textBox != nullptr && textBoxStyle != nullptr) {
                    textBox->setColor(textBoxStyle->color);
                    textBox->setTextParams(textBoxStyle->textLabelParams);
                }

                result = textBox;

                break;
            }
            case IMAGE_BOX: {
                auto imageBoxStyle = std::dynamic_pointer_cast<Styles::ImageBoxStyle>(style);
                auto imageBox = std::make_shared<ImageBox>(imageBoxStyle->figure);

                if (imageBox != nullptr && imageBoxStyle != nullptr) {
                    imageBox->setImage(imageBoxStyle->defaultTexturePath, imageBoxStyle->defaultTextureIndex);
                    imageBox->setLabelParams(imageBoxStyle->labelParams);
                }

                result = imageBox;

                break;
            }
            case MENU_BAR: {
                auto menuBarStyle = std::dynamic_pointer_cast<Styles::MenuBarStyle>(style);
                auto menuBar = std::make_shared<MenuBar>(menuBarStyle->defaultPosition,
                                                         menuBarStyle->scale);

                if (menuBar != nullptr && menuBarStyle != nullptr) {
                }

                result = menuBar;

                break;
            }
            case BUTTON: {
                auto buttonStyle = std::dynamic_pointer_cast<Styles::ButtonStyle>(style);
                auto button = std::make_shared<Button>(buttonStyle->figure);

                if (button != nullptr && buttonStyle != nullptr) {
                    button->setLabelParams(buttonStyle->labelParams);
                    button->setColor(buttonStyle->color);
                    button->setTraceColor(buttonStyle->traceColor);
                }

                result = button;

                break;
            }
            default:
                break;
        }

        if (result != nullptr) {
            result->setScale(style->scale);
        }

        return result;
    }

    Layout::Ptr WidgetFactory::create(LayoutType type, const Styles::LayoutStyle::Ptr& style) {
        Layout::Ptr result;

        switch (type) {
            case VERTICAL: {
                auto layoutStyle = std::dynamic_pointer_cast<Styles::LayoutStyle>(style);
                auto verticalLayout = std::make_shared<VerticalLayout>();

                if (verticalLayout != nullptr && layoutStyle != nullptr) {
                    verticalLayout->setWidgetOffset(layoutStyle->widgetOffset);
                }

                result = verticalLayout;

                break;
            }
            case HORIZONTAL: {
                auto layoutStyle = std::dynamic_pointer_cast<Styles::LayoutStyle>(style);
                auto horizontalLayout = std::make_shared<HorizontalLayout>();

                if (horizontalLayout != nullptr && layoutStyle != nullptr) {
                    horizontalLayout->setWidgetOffset(layoutStyle->widgetOffset);
                }

                result = horizontalLayout;

                break;
            }
        }

        return result;
    }
}    //namespace Widgets
