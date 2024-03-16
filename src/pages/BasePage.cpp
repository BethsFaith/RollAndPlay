//
// Created by VerOchka on 30.10.2023.
//

#include "BasePage.hpp"

#include <utility>

namespace Pages {
    BasePage::BasePage(GraphicLib::Objects::PickableTexture::Ptr canvas,
                       GraphicLib::GuiObjects::WidgetBuilder::Ptr builder)
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

    GraphicLib::GuiObjects::Widget::Ptr BasePage::createStyledWidget(GraphicLib::GuiObjects::WidgetType type,
                                                                  const std::string& className,
                                                                  glm::vec2 pos) {
        auto widget = _builder->createWidget(type, className);

//        auto scale = widget->getScale();
//        pos.x = pos.x + (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::GuiObjects::Widget::Ptr BasePage::createStyledWidget(GraphicLib::GuiObjects::WidgetType type, glm::vec2 pos) {
        auto widget = _builder->createWidget(type);

//        auto scale = widget->getScale();
//        pos.x = pos.x + (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::GuiObjects::Widget::Ptr BasePage::createStyledWidget(GraphicLib::GuiObjects::WidgetType type,
                                                                  glm::vec2 pos,
                                                                  glm::vec2 scale) {
        auto widget = _builder->createWidget(type);

//        widget->setScale(scale);
//        pos.x = pos.x + (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        return widget;
    }

    GraphicLib::GuiObjects::Widget::Ptr BasePage::createStyledWidget(GraphicLib::GuiObjects::WidgetType type) {
        return createStyledWidget(type, glm::vec2{0.0f});
    }

    GraphicLib::GuiObjects::Widget::Ptr BasePage::createStyledWidget(GraphicLib::GuiObjects::WidgetType type,
                                                                  const std::string& className) {
        return _builder->createWidget(type, className);
    }

    GraphicLib::GuiObjects::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout(glm::vec2 pos) {
        auto layout = _builder->createLayout(GraphicLib::GuiObjects::HORIZONTAL);

//        auto scale = layout->getScale();
//        pos.x = pos.x + (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);

        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::HorizontalLayout>(layout);
    }

    GraphicLib::GuiObjects::VerticalLayout::Ptr BasePage::createStyledVerticalLayout(glm::vec2 pos) {
        auto layout = _builder->createLayout(GraphicLib::GuiObjects::VERTICAL);

//        auto scale = layout->getScale();
//        pos.x = pos.x + (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        layout->setTransform(ScreenOffset + pos);

        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::VerticalLayout>(layout);
    }

    GraphicLib::GuiObjects::VerticalScrollBox::Ptr BasePage::createStyledVerticalScrollBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::VerticalScrollBox>(
            createStyledWidget(GraphicLib::GuiObjects::SCROLL_BOX, pos));
    }

    GraphicLib::GuiObjects::Button::Ptr BasePage::createStyledButton(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::Button>(
            createStyledWidget(GraphicLib::GuiObjects::BUTTON, className, pos));
    }

    GraphicLib::GuiObjects::Button::Ptr BasePage::createStyledButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::Button>(
            createStyledWidget(GraphicLib::GuiObjects::BUTTON, pos));
    }

    GraphicLib::GuiObjects::Button::Ptr BasePage::createStyledButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::Button>(
            createStyledWidget(GraphicLib::GuiObjects::BUTTON, pos, scale));
    }


    GraphicLib::GuiObjects::Button::Ptr BasePage::createStyledButton(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::Button>(createStyledWidget(GraphicLib::GuiObjects::BUTTON, className));
    }

    GraphicLib::GuiObjects::Button::Ptr BasePage::createStyledButton() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::Button>(createStyledWidget(GraphicLib::GuiObjects::BUTTON));
    }

    GraphicLib::GuiObjects::TextInputField::Ptr BasePage::createStyledInputField(const std::string& className,
                                                                              glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextInputField>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_INPUT_FIELD, className, pos));
    }

    GraphicLib::GuiObjects::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextInputField>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_INPUT_FIELD, pos));
    }

    GraphicLib::GuiObjects::TextInputField::Ptr BasePage::createStyledInputField(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextInputField>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_INPUT_FIELD, pos, scale));
    }

    GraphicLib::GuiObjects::TextInputField::Ptr BasePage::createStyledInputField(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextInputField>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_INPUT_FIELD, className));
    }

    GraphicLib::GuiObjects::TextInputField::Ptr BasePage::createStyledInputField() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextInputField>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_INPUT_FIELD));
    }

    GraphicLib::GuiObjects::NumericInputField::Ptr BasePage::createStyledNumericInputField(const std::string& className,
                                                                                        glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::NumericInputField>(
            createStyledWidget(GraphicLib::GuiObjects::NUM_INPUT_FIELD, className, pos));
    }

    GraphicLib::GuiObjects::NumericInputField::Ptr BasePage::createStyledNumericInputField(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::NumericInputField>(
            createStyledWidget(GraphicLib::GuiObjects::NUM_INPUT_FIELD, pos));
    }

    GraphicLib::GuiObjects::NumericInputField::Ptr BasePage::createStyledNumericInputField(glm::vec2 pos,
                                                                                        glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::NumericInputField>(
            createStyledWidget(GraphicLib::GuiObjects::NUM_INPUT_FIELD, pos, scale));
    }

    GraphicLib::GuiObjects::NumericInputField::Ptr BasePage::createStyledNumericInputField(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::NumericInputField>(
            createStyledWidget(GraphicLib::GuiObjects::NUM_INPUT_FIELD, className));
    }

    GraphicLib::GuiObjects::NumericInputField::Ptr BasePage::createStyledNumericInputField() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::NumericInputField>(
            createStyledWidget(GraphicLib::GuiObjects::NUM_INPUT_FIELD));
    }

    GraphicLib::GuiObjects::ImageButton::Ptr BasePage::createStyledImageButton(const std::string& className,
                                                                            glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageButton>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BUTTON, className, pos));
    }

    GraphicLib::GuiObjects::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageButton>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BUTTON, pos));
    }

    GraphicLib::GuiObjects::ImageButton::Ptr BasePage::createStyledImageButton(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageButton>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BUTTON, pos, scale));
    }

    GraphicLib::GuiObjects::ImageButton::Ptr BasePage::createStyledImageButton(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageButton>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BUTTON, className));
    }

    GraphicLib::GuiObjects::ImageButton::Ptr BasePage::createStyledImageButton() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageButton>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BUTTON));
    }

    GraphicLib::GuiObjects::TextBox::Ptr BasePage::createStyledTextBox(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextBox>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_BOX, className, pos));
    }

    GraphicLib::GuiObjects::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextBox>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_BOX, pos));
    }

    GraphicLib::GuiObjects::TextBox::Ptr BasePage::createStyledTextBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextBox>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_BOX, pos, scale));
    }

    GraphicLib::GuiObjects::TextBox::Ptr BasePage::createStyledTextBox(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextBox>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_BOX, className));
    }

    GraphicLib::GuiObjects::TextBox::Ptr BasePage::createStyledTextBox() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::TextBox>(
            createStyledWidget(GraphicLib::GuiObjects::TEXT_BOX));
    }

    GraphicLib::GuiObjects::ImageBox::Ptr BasePage::createStyledImageBox(const std::string& className, glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageBox>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BOX, className, pos));
    }

    GraphicLib::GuiObjects::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageBox>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BOX, pos));
    }

    GraphicLib::GuiObjects::ImageBox::Ptr BasePage::createStyledImageBox(glm::vec2 pos, glm::vec2 scale) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageBox>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BOX, pos));
    }

    GraphicLib::GuiObjects::ImageBox::Ptr BasePage::createStyledImageBox(const std::string& className) {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageBox>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BOX, className));
    }

    GraphicLib::GuiObjects::ImageBox::Ptr BasePage::createStyledImageBox() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::ImageBox>(
            createStyledWidget(GraphicLib::GuiObjects::IMAGE_BOX));
    }

    GraphicLib::GuiObjects::HorizontalLayout::Ptr BasePage::createStyledHorizontalLayout() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::HorizontalLayout>(
            _builder->createLayout(GraphicLib::GuiObjects::HORIZONTAL));
    }

    GraphicLib::GuiObjects::VerticalLayout::Ptr BasePage::createStyledVerticalLayout() {
        return std::dynamic_pointer_cast<GraphicLib::GuiObjects::VerticalLayout>(
            _builder->createLayout(GraphicLib::GuiObjects::VERTICAL));
    }

    void BasePage::createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                                    std::condition_variable& conditionVariable,
                                    const std::function<void()>& func) {
        _tasks.push_back(std::make_unique<Threads::Worker>(mutex, conditionVariable, func));
    }

    void BasePage::addWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget) {
        _gui.addWidget(widget);
    }

    void BasePage::addWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget, glm::vec2 pos) {
        auto scale = widget->getScale();

//        pos.x = pos.x - (scale.x / 2);
//        pos.y = pos.y - (scale.y / 2);

        widget->setTransform(ScreenOffset + pos);

        _gui.addWidget(widget);
    }

    void BasePage::addLayout(const GraphicLib::GuiObjects::Layout::Ptr& layout) {
        for (const auto& widget : layout->getWidgets()) {
            _gui.addWidget(widget);
        }
    }

    void BasePage::removeWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
    }

    void BasePage::updateWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget) {
        _gui.removeWidget(widget);
        _gui.addWidget(widget);
    }
}    //namespace Pages
