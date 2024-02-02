//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMPAGE_HPP
#define ROLLANDPLAY_SYSTEMPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "BasePage.hpp"
#include "../config/Config.hpp"
#include "../data/DataStorage.hpp"
#include "../data/System.hpp"
#include "../widgets/ImageButton.hpp"
#include "../widgets/TextInputField.hpp"

namespace Pages {
    class SystemPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<SystemPage>;

        explicit SystemPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~SystemPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Data::System::Ptr _system;

        Widgets::Button::Ptr _createButton;
        Widgets::Button::Ptr _saveButton;
        Widgets::TextInputField::Ptr _nameInputField;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SYSTEMPAGE_HPP
