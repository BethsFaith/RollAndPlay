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

        explicit RacePage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~RacePage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();

        void toCreate();

        StateTag _currentTag = START;

        GraphicLib::GuiObjects::Button::Ptr _createButton;
        GraphicLib::GuiObjects::Button::Ptr _saveButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _nameInput;
        GraphicLib::GuiObjects::ImageButton::Ptr _iconButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _iconPathInput;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_RACEPAGE_HPP
