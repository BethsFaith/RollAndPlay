//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_BASEPAGE_HPP
#define ROLLANDPLAY_BASEPAGE_HPP

#include <utility>

#include "Common.hpp"
#include "../Gui.hpp"
#include "../controllers/CommonController.hpp"
#include "../widgets/WidgetBuilder.hpp"
#include "APage.hpp"

namespace Pages {
    class BasePage : public APage {
    public:
        explicit BasePage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~BasePage() override = default;

        Controllers::GLController::Ptr getController() override;

        void draw() override;

        void update() override;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

        static void setCommonData(const Common& common);
    protected:
        Widgets::Widget::Ptr createStyledWidget(Widgets::WidgetType type, glm::vec2 pos);
        Widgets::Button::Ptr createStyledButton(glm::vec2 pos);
        Widgets::TextInputField::Ptr createStyledInputField(glm::vec2 pos);
        Widgets::ImageButton::Ptr createStyledImageButton(glm::vec2 pos);
        Widgets::TextBox::Ptr createStyledTextBox(glm::vec2 pos);
        Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout(glm::vec2 pos);
        Widgets::VerticalLayout::Ptr createStyledVerticalLayout(glm::vec2 pos);

        Widgets::Widget::Ptr createStyledWidget(Widgets::WidgetType type);
        Widgets::Button::Ptr createStyledButton();
        Widgets::TextInputField::Ptr createStyledInputField();
        Widgets::ImageButton::Ptr createStyledImageButton();
        Widgets::TextBox::Ptr createStyledTextBox();
        Widgets::HorizontalLayout::Ptr createStyledHorizontalLayout();
        Widgets::VerticalLayout::Ptr createStyledVerticalLayout();

        void addWidget(const Widgets::Widget::Ptr& widget);

        glm::vec2 ScreenOffset{};
        glm::vec2 min{};
        glm::vec2 max{};

        static inline Common CommonData{};

    private:
        Controllers::CommonController::Ptr _controller;
        Gui _gui;
        Widgets::WidgetBuilder::Ptr _builder;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_BASEPAGE_HPP
