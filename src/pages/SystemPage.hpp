//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMPAGE_HPP
#define ROLLANDPLAY_SYSTEMPAGE_HPP

#include <utility>

#include "BasePage.hpp"
#include "../config/Config.hpp"
#include "../data/DataStorage.hpp"
#include "../data/System.hpp"

namespace Pages {
    class SystemPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<SystemPage>;

        explicit SystemPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~SystemPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Data::System::Ptr _system;

        GraphicLib::GuiObjects::Button::Ptr _createButton;
        GraphicLib::GuiObjects::Button::Ptr _saveButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _nameInputField;
        GraphicLib::GuiObjects::ImageButton::Ptr _iconButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SYSTEMPAGE_HPP
