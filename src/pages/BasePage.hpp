//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_BASEPAGE_HPP
#define ROLLANDPLAY_BASEPAGE_HPP

#include <utility>

#include "APage.hpp"
#include "Common.hpp"
#include "threads/Worker.hpp"
#include "Anchors.hpp"
#include "../Gui.hpp"
#include "../controllers/CommonController.hpp"
#include "../widgets/WidgetBuilder.hpp"

namespace Pages {
    class BasePage : public APage {
    public:
        explicit BasePage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~BasePage() override;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

        void draw() override;
        void update() override;

        void start() override;
        void stop() override;

        Controllers::GLController::Ptr getController() override;

        static void setCommonData(const Common& common);

    protected:
        Widgets::Widget::Ptr createStyledWidget(Widgets::WidgetType type, glm::vec2 pos);
        Widgets::Widget::Ptr createStyledWidget(Widgets::WidgetType type, glm::vec2 pos, glm::vec2 scale);
        Widgets::Button::Ptr createStyledButton(glm::vec2 pos);
        Widgets::Button::Ptr createStyledButton(glm::vec2 pos, glm::vec2 scale);
        Widgets::TextInputField::Ptr createStyledInputField(glm::vec2 pos);
        Widgets::TextInputField::Ptr createStyledInputField(glm::vec2 pos, glm::vec2 scale);
        Widgets::ImageButton::Ptr createStyledImageButton(glm::vec2 pos);
        Widgets::ImageButton::Ptr createStyledImageButton(glm::vec2 pos, glm::vec2 scale);
        Widgets::TextBox::Ptr createStyledTextBox(glm::vec2 pos);
        Widgets::TextBox::Ptr createStyledTextBox(glm::vec2 pos, glm::vec2 scale);
        Widgets::ImageBox::Ptr createStyledImageBox(glm::vec2 pos);
        Widgets::ImageBox::Ptr createStyledImageBox(glm::vec2 pos, glm::vec2 scale);
        Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout(glm::vec2 pos);
        Widgets::VerticalLayout::Ptr createStyledVerticalLayout(glm::vec2 pos);

        Widgets::Widget::Ptr createStyledWidget(Widgets::WidgetType type);
        Widgets::Button::Ptr createStyledButton();
        Widgets::TextInputField::Ptr createStyledInputField();
        Widgets::ImageButton::Ptr createStyledImageButton();
        Widgets::TextBox::Ptr createStyledTextBox();
        Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout();
        Widgets::VerticalLayout::Ptr createStyledVerticalLayout();
        Widgets::ImageBox::Ptr createStyledImageBox();

        void createTaskThread(const std::shared_ptr<std::mutex>& mutex,
                              std::condition_variable& conditionVariable,
                              const std::function<void()>& func);

        void addWidget(const Widgets::Widget::Ptr& widget);
        void addWidget(const Widgets::Widget::Ptr& widget, glm::vec2 pos);
        void addLayout(const Widgets::Layout::Ptr& layout);
        void removeWidget(const Widgets::Widget::Ptr& widget);
        void updateWidget(const Widgets::Widget::Ptr& widget);

        glm::vec2 ScreenOffset{};
        glm::vec2 min{};
        glm::vec2 max{};

        static inline Common CommonData{};

    private:
        Controllers::CommonController::Ptr _controller;
        Gui _gui;
        Widgets::WidgetBuilder::Ptr _builder;

        std::vector<Threads::Worker::Ptr> _tasks;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_BASEPAGE_HPP
