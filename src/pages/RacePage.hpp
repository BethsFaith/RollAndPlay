//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_RACEPAGE_HPP
#define ROLLANDPLAY_RACEPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../widgets/ImageButton.hpp"
#include "../widgets/TextInputField.hpp"

namespace Pages {
    class RacePage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<RacePage>;

        explicit RacePage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~RacePage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();

        void toCreate();

        StateTag _currentTag = START;

        Widgets::Button::Ptr _createButton;
        Widgets::Button::Ptr _saveButton;
        Widgets::TextInputField::Ptr _nameInput;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInput;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_RACEPAGE_HPP
