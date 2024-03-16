//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_BASEPAGE_HPP
#define ROLLANDPLAY_BASEPAGE_HPP

#include <utility>
#include <GraphicLib/GuiObjects/Gui.hpp>
#include <GraphicLib/GuiObjects/WidgetBuilder.hpp>
#include <GraphicLib/Controllers/CommonController.hpp>

#include "APage.hpp"
#include "Common.hpp"
#include "threads/Worker.hpp"
#include "Anchors.hpp"
#include "../logger/Logger.hpp"

namespace Pages {
    class BasePage : public APage {
    public:
        explicit BasePage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~BasePage() override;

        void init(const glm::vec2& screenOffset) override;

        void draw() override;
        void update() override;

        void start() override;
        void stop() override;

        GraphicLib::Controllers::GLController::Ptr getController() override;

        static void setCommonData(const Common& common);

    protected:
        GraphicLib::GuiObjects::Widget::Ptr createStyledWidget(GraphicLib::GuiObjects::WidgetType type, glm::vec2 pos);
        GraphicLib::GuiObjects::Button::Ptr createStyledButton(glm::vec2 pos);
        GraphicLib::GuiObjects::TextInputField::Ptr createStyledInputField(glm::vec2 pos);
        GraphicLib::GuiObjects::NumericInputField::Ptr createStyledNumericInputField(glm::vec2 pos);
        GraphicLib::GuiObjects::ImageButton::Ptr createStyledImageButton(glm::vec2 pos);
        GraphicLib::GuiObjects::TextBox::Ptr createStyledTextBox(glm::vec2 pos);
        GraphicLib::GuiObjects::ImageBox::Ptr createStyledImageBox(glm::vec2 pos);
        GraphicLib::GuiObjects::HorizontalLayout::Ptr createStyledHorizontalLayout(glm::vec2 pos);
        GraphicLib::GuiObjects::VerticalLayout::Ptr createStyledVerticalLayout(glm::vec2 pos);
        GraphicLib::GuiObjects::VerticalScrollBox::Ptr createStyledVerticalScrollBox(glm::vec2 pos);

        GraphicLib::GuiObjects::Widget::Ptr createStyledWidget(GraphicLib::GuiObjects::WidgetType type, const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::Button::Ptr createStyledButton(const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::TextInputField::Ptr createStyledInputField(const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::NumericInputField::Ptr createStyledNumericInputField(const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::ImageButton::Ptr createStyledImageButton(const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::TextBox::Ptr createStyledTextBox(const std::string& className, glm::vec2 pos);
        GraphicLib::GuiObjects::ImageBox::Ptr createStyledImageBox(const std::string& className, glm::vec2 pos);
//        GraphicLib::Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout(const std::string& className, glm::vec2 pos);
//        GraphicLib::Widgets::VerticalLayout::Ptr createStyledVerticalLayout(const std::string& className, glm::vec2 pos);

        GraphicLib::GuiObjects::Widget::Ptr createStyledWidget(GraphicLib::GuiObjects::WidgetType type, glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::Button::Ptr createStyledButton(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::TextInputField::Ptr createStyledInputField(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::NumericInputField::Ptr createStyledNumericInputField(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::ImageButton::Ptr createStyledImageButton(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::TextBox::Ptr createStyledTextBox(glm::vec2 pos, glm::vec2 scale);
        GraphicLib::GuiObjects::ImageBox::Ptr createStyledImageBox(glm::vec2 pos, glm::vec2 scale);

        GraphicLib::GuiObjects::Widget::Ptr createStyledWidget(GraphicLib::GuiObjects::WidgetType type, const std::string& className);
        GraphicLib::GuiObjects::Button::Ptr createStyledButton(const std::string& className);
        GraphicLib::GuiObjects::TextInputField::Ptr createStyledInputField(const std::string& className);
        GraphicLib::GuiObjects::NumericInputField::Ptr createStyledNumericInputField(const std::string& className);
        GraphicLib::GuiObjects::ImageButton::Ptr createStyledImageButton(const std::string& className);
        GraphicLib::GuiObjects::TextBox::Ptr createStyledTextBox(const std::string& className);
        GraphicLib::GuiObjects::ImageBox::Ptr createStyledImageBox(const std::string& className);

        GraphicLib::GuiObjects::Widget::Ptr createStyledWidget(GraphicLib::GuiObjects::WidgetType type);
        GraphicLib::GuiObjects::Button::Ptr createStyledButton();
        GraphicLib::GuiObjects::TextInputField::Ptr createStyledInputField();
        GraphicLib::GuiObjects::NumericInputField::Ptr createStyledNumericInputField();
        GraphicLib::GuiObjects::ImageButton::Ptr createStyledImageButton();
        GraphicLib::GuiObjects::TextBox::Ptr createStyledTextBox();
        GraphicLib::GuiObjects::HorizontalLayout::Ptr createStyledHorizontalLayout();
        GraphicLib::GuiObjects::VerticalLayout::Ptr createStyledVerticalLayout();
        GraphicLib::GuiObjects::ImageBox::Ptr createStyledImageBox();

        void createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                              std::condition_variable& conditionVariable,
                              const std::function<void()>& func);

        void addWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget);
        void addWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget, glm::vec2 pos);
        void addLayout(const GraphicLib::GuiObjects::Layout::Ptr& layout);
        void removeWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget);
        void updateWidget(const GraphicLib::GuiObjects::Widget::Ptr& widget);

        static inline Common CommonData{};

    private:
        glm::vec2 ScreenOffset{};

        GraphicLib::Controllers::CommonController::Ptr _controller;
        GraphicLib::GuiObjects::Gui _gui;
        GraphicLib::GuiObjects::WidgetBuilder::Ptr _builder;

        std::vector<Threads::Worker::Ptr> _tasks;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_BASEPAGE_HPP
