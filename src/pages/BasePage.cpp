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

    BasePage::~BasePage() {
        for (auto &task : _tasks) {
            task.reset();
        }
    }

    void BasePage::init(const glm::vec2& screenOffset, const glm::vec2& min_, const glm::vec2& max_) {
        ScreenOffset = screenOffset;

        min = min_;
        max = max_;
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    void BasePage::start() {
        // запуск потоков
        for (auto &task : _tasks) {
            task->start(10000);
        }
    }

    void BasePage::stop() {
        // остановка потоков
        for (auto &task : _tasks) {
            task->stop();
        }
    }

    void BasePage::update() {
        _controller->clear();
        _gui.clear();
        _controller->addSubController(_gui.getController());
    }

    void BasePage::setCommonData(const Common& common) {
        CommonData = common;
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
        auto layout = _builder->createLayout(Widgets::HORIZONTAL);

        auto scale = layout->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);
        layout->setProjection(min.x, max.x, min.y, max.y);



        return std::dynamic_pointer_cast<Widgets::HorizontalLayout>(layout);
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout(glm::vec2 pos) {
        auto layout = _builder->createLayout(Widgets::VERTICAL);

        auto scale = layout->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);
        layout->setProjection(min.x, max.x, min.y, max.y);



        return std::dynamic_pointer_cast<Widgets::VerticalLayout>(layout);
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
        return std::dynamic_pointer_cast<Widgets::HorizontalLayout>(_builder->createLayout(Widgets::HORIZONTAL));
    }

    Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout() {
        return std::dynamic_pointer_cast<Widgets::VerticalLayout>(_builder->createLayout(Widgets::VERTICAL));
    }

    Widgets::ImageBox::Ptr BasePage::createStyledImageBox() {
        return std::dynamic_pointer_cast<Widgets::ImageBox>(
            createStyledWidget(Widgets::IMAGE_BOX));
    }

    void BasePage::createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                                    std::condition_variable& conditionVariable,
                                    const std::function<void()>& func) {
        _tasks.push_back(std::make_unique<Threads::Worker>(mutex, conditionVariable, func));
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

    void BasePage::addLayout(const Widgets::Layout::Ptr& layout) {
        for (const auto& widget : layout->getWidgets()) {
            _gui.addWidget(widget);
        }
    }

    void BasePage::removeWidget(const Widgets::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
    }

    void BasePage::updateWidget(const Widgets::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
        _gui.addWidget(widget);
    }
}    //namespace Pages
