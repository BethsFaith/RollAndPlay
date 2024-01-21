//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_RACEPAGE_HPP
#define ROLLANDPLAY_RACEPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"

namespace Pages {
    class RacePage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<RacePage>;

        explicit RacePage(GraphicLib::PickableTexture::Ptr canvas);
        ~RacePage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();

        void toCreate();

        StateTag _currentTag = START;

        Forms::Button::Ptr _createButton;
        Forms::Button::Ptr _saveButton;
        Forms::InputField::Ptr _nameInputField;
        Forms::ImageButton::Ptr _iconButton;
        Forms::InputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_RACEPAGE_HPP
