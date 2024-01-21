//
// Created by VerOchka on 25.10.2023.
//

#ifndef ROLLANDPLAY_SYSTEMPAGE_HPP
#define ROLLANDPLAY_SYSTEMPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>
#include <utility>

#include "../config/Config.hpp"
#include "../data/DataStorage.hpp"
#include "../data/System.hpp"
#include "BasePage.hpp"

namespace Pages {
    class SystemPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW
        };

        using Ptr = std::shared_ptr<SystemPage>;

        explicit SystemPage(GraphicLib::PickableTexture::Ptr canvas);
        ~SystemPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;

        void toStart();
        void toView();

        StateTag _currentTag = START;

        Data::System::Ptr _system;

        Forms::Button::Ptr _createButton;
        Forms::Button::Ptr _saveButton;
        Forms::InputField::Ptr _nameInputField;
        Forms::ImageButton::Ptr _iconButton;
        Forms::InputField::Ptr _iconPathInputField;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_SYSTEMPAGE_HPP
