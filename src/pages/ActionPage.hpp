//
// Created by BethsFaith on 25.02.2024.
//

#ifndef INC_1_BIN_ACTIONPAGE_HPP
#define INC_1_BIN_ACTIONPAGE_HPP

#include "BasePage.hpp"
#include "../data/Action.hpp"

namespace Pages {
    class ActionPage : public BasePage {
    public:
        enum StateTag {
            START,
            CREATE_ACTION,
            VIEW_ACTION,
            EDIT_ACTION,
            CHOOSE_SKILL,
        };

        struct Buffer {
            Data::Action::Ptr action;
            Data::Skill::Ptr skill;
        };

        explicit ActionPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::Widgets::WidgetBuilder::Ptr builder);
        ~ActionPage() override = default;

        void update() override;
        void init(const glm::vec2& screenOffset) override;

    private:
        void toStart();
        void toActionCreating();
        void toActionViewing();
        void toActionEditing();
        void toActionSkillChoice();

        bool checkInput();

        Net::ApiClient::Result createAction();
        Net::ApiClient::Result updateAction();

        StateTag _currentTag = START;

        Buffer _buf;

        GraphicLib::Widgets::TextInputField::Ptr _nameInputField;
        GraphicLib::Widgets::ImageButton::Ptr _iconButton;
        GraphicLib::Widgets::NumericInputField::Ptr _pointsInputField;
        GraphicLib::Widgets::TextInputField::Ptr _iconPathInputField;
        GraphicLib::Widgets::TextBox::Ptr _messageBox;
    };
}    //namespace Pages

#endif    //INC_1_BIN_ACTIONPAGE_HPP
