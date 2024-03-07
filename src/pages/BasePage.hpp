//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_BASEPAGE_HPP
#define ROLLANDPLAY_BASEPAGE_HPP

#include <utility>
#include <GraphicLib/Widgets/Gui.hpp>
#include <GraphicLib/Widgets/WidgetBuilder.hpp>
#include <GraphicLib/Controllers/CommonController.hpp>

#include "APage.hpp"
#include "Common.hpp"
#include "threads/Worker.hpp"
#include "Anchors.hpp"
#include "../logger/Logger.hpp"

namespace Pages {
    class BasePage : public APage {
    public:
        explicit BasePage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::Widgets::WidgetBuilder::Ptr builder);
        ~BasePage() override;

        void init(const glm::vec2& screenOffset) override;

        void draw() override;
        void update() override;

        void start() override;
        void stop() override;

        GraphicLib::Controllers::GLController::Ptr getController() override;

        static void setCommonData(const Common& common);

    protected:
        GraphicLib::Widgets::Widget::Ptr createStyledWidget(GraphicLib::Widgets::WidgetType type, glm::vec2 pos);
        GraphicLib::Widgets::Button::Ptr createStyledButton(glm::vec2 pos);
        GraphicLib::Widgets::TextInputField::Ptr createStyledInputField(glm::vec2 pos);
        GraphicLib::Widgets::NumericInputField::Ptr createStyledNumericInputField(glm::vec2 pos);
        GraphicLib::Widgets::ImageButton::Ptr createStyledImageButton(glm::vec2 pos);
        GraphicLib::Widgets::TextBox::Ptr createStyledTextBox(glm::vec2 pos);
        GraphicLib::Widgets::ImageBox::Ptr createStyledImageBox(glm::vec2 pos);
        GraphicLib::Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout(glm::vec2 pos);
        GraphicLib::Widgets::VerticalLayout::Ptr createStyledVerticalLayout(glm::vec2 pos);

        GraphicLib::Widgets::Widget::Ptr createStyledWidget(GraphicLib::Widgets::WidgetType type, const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::Button::Ptr createStyledButton(const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::TextInputField::Ptr createStyledInputField(const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::NumericInputField::Ptr createStyledNumericInputField(const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::ImageButton::Ptr createStyledImageButton(const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::TextBox::Ptr createStyledTextBox(const std::string& className, glm::vec2 pos);
        GraphicLib::Widgets::ImageBox::Ptr createStyledImageBox(const std::string& className, glm::vec2 pos);
//        GraphicLib::Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout(const std::string& className, glm::vec2 pos);
//        GraphicLib::Widgets::VerticalLayout::Ptr createStyledVerticalLayout(const std::string& className, glm::vec2 pos);

        GraphicLib::Widgets::Widget::Ptr createStyledWidget(GraphicLib::Widgets::WidgetType type, glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::Button::Ptr createStyledButton(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::TextInputField::Ptr createStyledInputField(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::NumericInputField::Ptr createStyledNumericInputField(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::ImageButton::Ptr createStyledImageButton(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::TextBox::Ptr createStyledTextBox(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::Widgets::ImageBox::Ptr createStyledImageBox(glm::vec2 pos, glm::vec2 scale);

        GraphicLib::Widgets::Widget::Ptr createStyledWidget(GraphicLib::Widgets::WidgetType type, const std::string& className);
        GraphicLib::Widgets::Button::Ptr createStyledButton(const std::string& className);
        GraphicLib::Widgets::TextInputField::Ptr createStyledInputField(const std::string& className);
        GraphicLib::Widgets::NumericInputField::Ptr createStyledNumericInputField(const std::string& className);
        GraphicLib::Widgets::ImageButton::Ptr createStyledImageButton(const std::string& className);
        GraphicLib::Widgets::TextBox::Ptr createStyledTextBox(const std::string& className);
        GraphicLib::Widgets::ImageBox::Ptr createStyledImageBox(const std::string& className);

        GraphicLib::Widgets::Widget::Ptr createStyledWidget(GraphicLib::Widgets::WidgetType type);
        GraphicLib::Widgets::Button::Ptr createStyledButton();
        GraphicLib::Widgets::TextInputField::Ptr createStyledInputField();
        GraphicLib::Widgets::NumericInputField::Ptr createStyledNumericInputField();
        GraphicLib::Widgets::ImageButton::Ptr createStyledImageButton();
        GraphicLib::Widgets::TextBox::Ptr createStyledTextBox();
        GraphicLib::Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout();
        GraphicLib::Widgets::VerticalLayout::Ptr createStyledVerticalLayout();
        GraphicLib::Widgets::ImageBox::Ptr createStyledImageBox();

        void createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                              std::condition_variable& conditionVariable,
                              const std::function<void()>& func);

        void addWidget(const GraphicLib::Widgets::Widget::Ptr& widget);
        void addWidget(const GraphicLib::Widgets::Widget::Ptr& widget, glm::vec2 pos);
        void addLayout(const GraphicLib::Widgets::Layout::Ptr& layout);
        void removeWidget(const GraphicLib::Widgets::Widget::Ptr& widget);
        void updateWidget(const GraphicLib::Widgets::Widget::Ptr& widget);

        static inline Common CommonData{};

    private:
        glm::vec2 ScreenOffset{};

        GraphicLib::Controllers::CommonController::Ptr _controller;
        GraphicLib::Widgets::Gui _gui;
        GraphicLib::Widgets::WidgetBuilder::Ptr _builder;

        std::vector<Threads::Worker::Ptr> _tasks;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_BASEPAGE_HPP
