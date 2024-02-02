//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

#include <utility>

namespace Pages {
    BasePage::BasePage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder)
        : _gui(std::move(canvas)), _builder(std::move(builder)) {
        _controller = std::make_shared<Controllers::CommonController>();
    }

    void BasePage::update() {
        _controller->clear();
        _gui.clear();
        _controller->addSubController(_gui.getController());
    }

    Controllers::GLController::Ptr BasePage::getController() {
        return _controller;
    }

    Widgets::Widget::Ptr BasePage::createStyledWidget(Widgets::WidgetType type) {
        return _builder->createWidget(type);
    }

    Widgets::Button::Ptr BasePage::createStyledButton() {
        return std::dynamic_pointer_cast<Widgets::Button>(createStyledWidget(Widgets::BUTTON));
    }

    Widgets::TextInputField::Ptr BasePage::createStyledInputField() {
        return std::dynamic_pointer_cast<Widgets::TextInputField>(createStyledWidget(Widgets::TEXT_INPUT_FIELD));
    }

    Widgets::ImageButton::Ptr BasePage::createStyledImageButton() {
        return std::dynamic_pointer_cast<Widgets::ImageButton>(createStyledWidget(Widgets::IMAGE_BUTTON));
    }

    Widgets::TextBox::Ptr BasePage::createStyledTextBox() {
        return std::dynamic_pointer_cast<Widgets::TextBox>(createStyledWidget(Widgets::TEXT_BOX));
    }

    Widgets::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout() {
        return std::dynamic_pointer_cast<Widgets::TextBox>(createStyledWidget(Widgets::HORIZONTAL_LAYOUT));
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout() {
        return std::dynamic_pointer_cast<Widgets::TextBox>(createStyledWidget(Widgets::VERTICAL_LAYOUT));
    }

    void BasePage::addWidget(const Widgets::Widget::Ptr& widget) {
        _gui.addWidget(widget);
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    void BasePage::init(const glm::vec2& screenOffset) {
        ScreenOffset = screenOffset;
    }

    void BasePage::setCommonData(const Common& common) {
        CommonData = common;
    }
}    //namespace Pages
