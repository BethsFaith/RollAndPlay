//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

#include <utility>

namespace Pages {
    BasePage::BasePage(GraphicLib::Objects::PickableTexture::Ptr canvas,
                       GraphicLib::Widgets::WidgetBuilder::Ptr builder)
        : _gui(std::move(canvas)),
          _builder(std::move(builder)) {
        _controller = std::make_shared<GraphicLib::Controllers::CommonController>();
    }

    BasePage::~BasePage() {
        for (auto& task : _tasks) {
            task.reset();
        }
    }

    void BasePage::init(const glm::vec2& screenOffset) {
        ScreenOffset = screenOffset;
    }

    void BasePage::draw() {
        glEnable(GL_DEPTH_TEST);
        _gui.draw();
        glDisable(GL_DEPTH_TEST);
    }

    void BasePage::start() {
        // запуск потоков
        for (auto& task : _tasks) {
            task->start(1000);
        }
    }

    void BasePage::stop() {
        // остановка потоков
        for (auto& task : _tasks) {
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

    GraphicLib::Controllers::GLController::Ptr BasePage::getController() {
        return _controller;
    }

    GraphicLib::Widgets::Widget::Ptr BasePage::createStyledWidget(GraphicLib::Widgets::WidgetType type,
                                                                  const std::string& className,
                                                                  glm::vec2 pos) {
        auto widget = _builder->createWidget(type, className);

        auto scale = widget->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::Widgets::Widget::Ptr BasePage::createStyledWidget(GraphicLib::Widgets::WidgetType type, glm::vec2 pos) {
        auto widget = _builder->createWidget(type);

        auto scale = widget->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::Widgets::Widget::Ptr BasePage::createStyledWidget(GraphicLib::Widgets::WidgetType type,
                                                                  glm::vec2 pos,
                                                                  glm::vec2 scale) {
        auto widget = _builder->createWidget(type);

        widget->setScale(scale);
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::Widgets::Widget::Ptr BasePage::createStyledWidget(GraphicLib::Widgets::WidgetType type) {
        return _builder->createWidget(type);
    }

    GraphicLib::Widgets::Widget::Ptr BasePage::createStyledWidget(GraphicLib::Widgets::WidgetType type,
                                                                  const std::string& className) {
        return _builder->createWidget(type, className);
    }

    GraphicLib::Widgets::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout(glm::vec2 pos) {
        auto layout = _builder->createLayout(GraphicLib::Widgets::HORIZONTAL);

        auto scale = layout->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);

        return std::dynamic_pointer_cast<GraphicLib::Widgets::HorizontalLayout>(layout);
    }

    GraphicLib::Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout(glm::vec2 pos) {
        auto layout = _builder->createLayout(GraphicLib::Widgets::VERTICAL);

        auto scale = layout->getScale();
        pos.x = pos.x + (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);

        return std::dynamic_pointer_cast<GraphicLib::Widgets::VerticalLayout>(layout);
    }

    GraphicLib::Widgets::Button::Ptr BasePage::createStyledButton(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::Button>(
            createStyledWidget(GraphicLib::Widgets::BUTTON, className, pos));
    }

    GraphicLib::Widgets::Button::Ptr BasePage::createStyledButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::Button>(
            createStyledWidget(GraphicLib::Widgets::BUTTON, pos));
    }

    GraphicLib::Widgets::Button::Ptr BasePage::createStyledButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::Button>(
            createStyledWidget(GraphicLib::Widgets::BUTTON, pos, scale));
    }


    GraphicLib::Widgets::Button::Ptr BasePage::createStyledButton(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::Button>(createStyledWidget(GraphicLib::Widgets::BUTTON, className));
    }

    GraphicLib::Widgets::Button::Ptr BasePage::createStyledButton() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::Button>(createStyledWidget(GraphicLib::Widgets::BUTTON));
    }

    GraphicLib::Widgets::TextInputField::Ptr BasePage::createStyledInputField(const std::string& className,
                                                                              glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextInputField>(
            createStyledWidget(GraphicLib::Widgets::TEXT_INPUT_FIELD, className, pos));
    }

    GraphicLib::Widgets::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextInputField>(
            createStyledWidget(GraphicLib::Widgets::TEXT_INPUT_FIELD, pos));
    }

    GraphicLib::Widgets::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextInputField>(
            createStyledWidget(GraphicLib::Widgets::TEXT_INPUT_FIELD, pos, scale));
    }

    GraphicLib::Widgets::TextInputField::Ptr BasePage::createStyledInputField(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextInputField>(
            createStyledWidget(GraphicLib::Widgets::TEXT_INPUT_FIELD, className));
    }

    GraphicLib::Widgets::TextInputField::Ptr BasePage::createStyledInputField() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextInputField>(
            createStyledWidget(GraphicLib::Widgets::TEXT_INPUT_FIELD));
    }

    GraphicLib::Widgets::NumericInputField::Ptr BasePage::createStyledNumericInputField(const std::string& className,
                                                                                        glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::NumericInputField>(
            createStyledWidget(GraphicLib::Widgets::NUM_INPUT_FIELD, className, pos));
    }

    GraphicLib::Widgets::NumericInputField::Ptr BasePage::createStyledNumericInputField(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::NumericInputField>(
            createStyledWidget(GraphicLib::Widgets::NUM_INPUT_FIELD, pos));
    }

    GraphicLib::Widgets::NumericInputField::Ptr BasePage::createStyledNumericInputField(glm::vec2 pos,
                                                                                        glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::NumericInputField>(
            createStyledWidget(GraphicLib::Widgets::NUM_INPUT_FIELD, pos, scale));
    }

    GraphicLib::Widgets::NumericInputField::Ptr BasePage::createStyledNumericInputField(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::NumericInputField>(
            createStyledWidget(GraphicLib::Widgets::NUM_INPUT_FIELD, className));
    }

    GraphicLib::Widgets::NumericInputField::Ptr BasePage::createStyledNumericInputField() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::NumericInputField>(
            createStyledWidget(GraphicLib::Widgets::NUM_INPUT_FIELD));
    }

    GraphicLib::Widgets::ImageButton::Ptr BasePage::createStyledImageButton(const std::string& className,
                                                                            glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageButton>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BUTTON, className, pos));
    }

    GraphicLib::Widgets::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageButton>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BUTTON, pos));
    }

    GraphicLib::Widgets::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageButton>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BUTTON, pos, scale));
    }

    GraphicLib::Widgets::ImageButton::Ptr BasePage::createStyledImageButton(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageButton>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BUTTON, className));
    }

    GraphicLib::Widgets::ImageButton::Ptr BasePage::createStyledImageButton() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageButton>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BUTTON));
    }

    GraphicLib::Widgets::TextBox::Ptr BasePage::createStyledTextBox(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextBox>(
            createStyledWidget(GraphicLib::Widgets::TEXT_BOX, className, pos));
    }

    GraphicLib::Widgets::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextBox>(
            createStyledWidget(GraphicLib::Widgets::TEXT_BOX, pos));
    }

    GraphicLib::Widgets::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextBox>(
            createStyledWidget(GraphicLib::Widgets::TEXT_BOX, pos, scale));
    }

    GraphicLib::Widgets::TextBox::Ptr BasePage::createStyledTextBox(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextBox>(
            createStyledWidget(GraphicLib::Widgets::TEXT_BOX, className));
    }

    GraphicLib::Widgets::TextBox::Ptr BasePage::createStyledTextBox() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::TextBox>(
            createStyledWidget(GraphicLib::Widgets::TEXT_BOX));
    }

    GraphicLib::Widgets::ImageBox::Ptr BasePage::createStyledImageBox(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageBox>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BOX, className, pos));
    }

    GraphicLib::Widgets::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageBox>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BOX, pos));
    }

    GraphicLib::Widgets::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageBox>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BOX, pos));
    }

    GraphicLib::Widgets::ImageBox::Ptr BasePage::createStyledImageBox(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageBox>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BOX, className));
    }

    GraphicLib::Widgets::ImageBox::Ptr BasePage::createStyledImageBox() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::ImageBox>(
            createStyledWidget(GraphicLib::Widgets::IMAGE_BOX));
    }

    GraphicLib::Widgets::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::HorizontalLayout>(
            _builder->createLayout(GraphicLib::Widgets::HORIZONTAL));
    }

    GraphicLib::Widgets::VerticalLayout::Ptr BasePage::createStyledVerticalLayout() {
        return std::dynamic_pointer_cast<GraphicLib::Widgets::VerticalLayout>(
            _builder->createLayout(GraphicLib::Widgets::VERTICAL));
    }

    void BasePage::createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                                    std::condition_variable& conditionVariable,
                                    const std::function<void()>& func) {
        _tasks.push_back(std::make_unique<Threads::Worker>(mutex, conditionVariable, func));
    }

    void BasePage::addWidget(const GraphicLib::Widgets::Widget::Ptr& widget) {
        _gui.addWidget(widget);
    }

    void BasePage::addWidget(const GraphicLib::Widgets::Widget::Ptr& widget, glm::vec2 pos) {
        auto scale = widget->getScale();

        pos.x = pos.x - (scale.x / 2);
        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        _gui.addWidget(widget);
    }

    void BasePage::addLayout(const GraphicLib::Widgets::Layout::Ptr& layout) {
        for (const auto& widget : layout->getWidgets()) {
            _gui.addWidget(widget);
        }
    }

    void BasePage::removeWidget(const GraphicLib::Widgets::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
    }

    void BasePage::updateWidget(const GraphicLib::Widgets::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
        _gui.addWidget(widget);
    }
}    //namespace Pages
