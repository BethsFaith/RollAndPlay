//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

#include <utility>

namespace Pages {
    BasePage::BasePage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder)
        : _gui(std::move(canvas)),
          _builder(std::move(builder)) {
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

    Widgets::Widget::Ptr BasePage::createStyledWidget(Widgets::WidgetType type, glm::vec2 pos) {
        auto widget = _builder->createWidget(type);

        auto scale = widget->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);
        widget->setProjection(min.x, max.x, min.y, max.y);

        return widget;
    }

    Widgets::Widget::Ptr BasePage::createStyledWidget(Widgets::WidgetType type, glm::vec2 pos, glm::vec2 scale) {
        auto widget = _builder->createWidget(type);

        widget->setScale(scale);
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);
        widget->setProjection(min.x, max.x, min.y, max.y);

        return widget;
    }

    Widgets::Button::Ptr BasePage::createStyledButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::Button>(createStyledWidget(Widgets::BUTTON, pos));
    }

    Widgets::Button::Ptr BasePage::createStyledButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::Button>(createStyledWidget(Widgets::BUTTON, pos, scale));
    }

    Widgets::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::TextInputField>(createStyledWidget(Widgets::TEXT_INPUT_FIELD, pos));
    }

    Widgets::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::TextInputField>(
            createStyledWidget(Widgets::TEXT_INPUT_FIELD, pos, scale));
    }

    Widgets::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::ImageButton>(createStyledWidget(Widgets::IMAGE_BUTTON, pos));
    }

    Widgets::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::ImageButton>(createStyledWidget(Widgets::IMAGE_BUTTON, pos, scale));
    }

    Widgets::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::TextBox>(createStyledWidget(Widgets::TEXT_BOX, pos));
    }

    Widgets::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::TextBox>(createStyledWidget(Widgets::TEXT_BOX, pos, scale));
    }

    Widgets::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::HorizontalLayout>(
            createStyledWidget(Widgets::HORIZONTAL_LAYOUT, pos));
    }

    Widgets::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::HorizontalLayout>(
            createStyledWidget(Widgets::HORIZONTAL_LAYOUT, pos, scale));
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::VerticalLayout>(createStyledWidget(Widgets::VERTICAL_LAYOUT, pos));
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::VerticalLayout>(
            createStyledWidget(Widgets::VERTICAL_LAYOUT, pos, scale));
    }

    Widgets::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<Widgets::ImageBox>(
            createStyledWidget(Widgets::IMAGE_BOX, pos));
    }

    Widgets::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<Widgets::ImageBox>(
            createStyledWidget(Widgets::IMAGE_BOX, pos));
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
        return std::dynamic_pointer_cast<Widgets::HorizontalLayout>(createStyledWidget(Widgets::HORIZONTAL_LAYOUT));
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout() {
        return std::dynamic_pointer_cast<Widgets::VerticalLayout>(createStyledWidget(Widgets::VERTICAL_LAYOUT));
    }

    Widgets::ImageBox::Ptr BasePage::createStyledImageBox() {
        return std::dynamic_pointer_cast<Widgets::ImageBox>(
            createStyledWidget(Widgets::IMAGE_BOX));
    }

    void BasePage::addWidget(const Widgets::Widget::Ptr& widget) {
        _gui.addWidget(widget);
    }

    void BasePage::addWidget(const Widgets::Widget::Ptr& widget, glm::vec2 pos) {
        auto scale = widget->getScale();

        pos.x = pos.x - (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);
        widget->setProjection(min.x, max.x, min.y, max.y);

        _gui.addWidget(widget);
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    void BasePage::init(const glm::vec2& screenOffset, const glm::vec2& min_, const glm::vec2& max_) {
        ScreenOffset = screenOffset;

        min = min_;
        max = max_;
    }

    void BasePage::setCommonData(const Common& common) {
        CommonData = common;
    }
}    //namespace Pages
