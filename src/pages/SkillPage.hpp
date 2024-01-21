//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"

namespace Pages {
    class SkillPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        explicit SkillPage(GraphicLib::PickableTexture::Ptr canvas);
        ~SkillPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Forms::Button::Ptr _createButton;
        Forms::Button::Ptr _saveButton;
        Forms::InputField::Ptr _nameInputField;
        Forms::ImageButton::Ptr _iconButton;
        Forms::InputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
