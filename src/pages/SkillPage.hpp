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

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Widgets::Button::Ptr _createCategoryButton;
        Widgets::Button::Ptr _saveButton;
        Widgets::TextInputField::Ptr _nameInputField;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
