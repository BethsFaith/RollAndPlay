//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_SKILLPAGE_HPP
#define ROLLANDPLAY_SKILLPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../widgets/TextForm.hpp"
#include "../widgets/ImageButton.hpp"

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

        Widgets::Button::Ptr _createButton;
        Widgets::Button::Ptr _saveButton;
        Widgets::TextForm::Ptr _nameTextForm;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextForm::Ptr _iconPathTextForm;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SKILLPAGE_HPP
