//
// Created by BethsFaith on 04.03.2024.
//

#ifndef INC_1_BIN_CHARACTERISTICPAGE_HPP
#define INC_1_BIN_CHARACTERISTICPAGE_HPP

#include "BasePage.hpp"

#include "../data/Characteristic.hpp"

namespace Pages {
    class CharacteristicPage : public BasePage {
    public:
        using Ptr = std::shared_ptr<CharacteristicPage>;

        enum StateTag {
            START,
            CREATE,
            VIEW,
            EDIT,
        };

        explicit CharacteristicPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~CharacteristicPage() override = default;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;
        void draw() override;
        void update() override;

    private:
        void toStart();
        void toCreate();
        void toView();
        void toEdit();

        bool checkInput();

        Net::ApiClient::Result createCharacteristic();
        Net::ApiClient::Result updateCharacteristic();

        StateTag _currentTag{};

        Data::Characteristic::Ptr _bufCharacteristic;

        Widgets::TextInputField::Ptr _nameInputField;
        Widgets::ImageButton::Ptr _iconButton;
        Widgets::TextInputField::Ptr _iconPathInputField;
        Widgets::TextBox::Ptr _messageBox;
    };
}
#endif    //INC_1_BIN_CHARACTERISTICPAGE_HPP
