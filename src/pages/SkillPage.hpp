//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../widgets/ImageButton.hpp"
#include "../widgets/TextInputField.hpp"

namespace Pages {
    class SkillPage : public BasePage {
    public:
        enum StateTag {
            START,
            CREATE_SKILL,
            CREATE_CATEGORY,
            VIEW
        };

        explicit SkillPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~SkillPage() override = default;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

    private:
        void update() override;

        void toStart();
        void toCategoryCreate();
        void toSkillCreate();

        Net::HttpSession::Result pushCategory();
        Net::HttpSession::Result pushSkills();

        static Net::HttpSession::Result pullCategories();
        static Net::HttpSession::Result pullSkills();

        StateTag _currentTag = START;

        Widgets::TextBox::Ptr _categoriesLabel;
        Widgets::TextBox::Ptr _skillLabel;

        Widgets::HorizontalLayout::Ptr _createButtonLayout;
        Widgets::HorizontalLayout::Ptr _createCategoryLayout;
        Widgets::HorizontalLayout::Ptr _createSkillLayout;
        Widgets::HorizontalLayout::Ptr _viewCategoryLayout;
        Widgets::HorizontalLayout::Ptr _viewSkillLayout;
        Widgets::VerticalLayout::Ptr _createLayout;

        Widgets::TextInputField::Ptr _nameInputField;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
