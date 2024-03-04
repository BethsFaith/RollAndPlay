//
// Created by VerOchka on 30.10.2023.
//

#ifndef ROLLANDPLAY_RACEPAGE_HPP
#define ROLLANDPLAY_RACEPAGE_HPP

#include "BasePage.hpp"

namespace Pages {
    class RacePage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<RacePage>;

        explicit RacePage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::Widgets::WidgetBuilder::Ptr builder);
        ~RacePage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();

        void toCreate();

        StateTag _currentTag = START;

        GraphicLib::Widgets::Button::Ptr _createButton;
        GraphicLib::Widgets::Button::Ptr _saveButton;
        GraphicLib::Widgets::TextInputField::Ptr _nameInput;
        GraphicLib::Widgets::ImageButton::Ptr _iconButton;
        GraphicLib::Widgets::TextInputField::Ptr _iconPathInput;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_RACEPAGE_HPP
