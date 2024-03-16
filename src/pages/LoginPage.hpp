//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include "BasePage.hpp"
#include "../data/User.hpp"

namespace Pages {
    class LoginPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW,
            EDIT,
        };

        using Ptr = std::shared_ptr<LoginPage>;

        explicit LoginPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::GuiObjects::WidgetBuilder::Ptr builder);
        ~LoginPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toStart();
        void toView();
        void toEdit();

        bool validate(const std::u16string& login, const std::u16string& password);
        bool validate(const std::u16string& login, const std::u16string& password, const std::u16string& nickname);

        Net::ApiClient::Result logIn(const std::u16string& login, const std::u16string& password);
        Net::ApiClient::Result pullUserData();
        Net::ApiClient::Result changeUserData(const std::u16string& login,
                                                const std::u16string& password,
                                                const std::u16string& nickname);
        void showResultError(Net::ApiClient::Result& result);

        StateTag _nextState = START;

        GraphicLib::GuiObjects::Button::Ptr _logInButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _loginInputField;
        GraphicLib::GuiObjects::TextInputField::Ptr _passwordInputField;
        GraphicLib::GuiObjects::TextBox::Ptr _messageBox{};

        GraphicLib::GuiObjects::Button::Ptr _editButton;
        GraphicLib::GuiObjects::Button::Ptr _exitButton;
        GraphicLib::GuiObjects::TextBox::Ptr _emailLabel{};
        GraphicLib::GuiObjects::TextBox::Ptr _nicknameLabel{};
        GraphicLib::GuiObjects::TextBox::Ptr _emailBox{};
        GraphicLib::GuiObjects::TextBox::Ptr _nicknameBox{};

        GraphicLib::GuiObjects::Button::Ptr _saveButton;
        GraphicLib::GuiObjects::TextInputField::Ptr _nicknameInputField;

        GraphicLib::GuiObjects::VerticalLayout::Ptr _startLayout;
        GraphicLib::GuiObjects::VerticalLayout::Ptr _viewLayout;
        GraphicLib::GuiObjects::VerticalLayout::Ptr _editLayout;

        Data::User _user{};
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_LOGINPAGE_HPP
