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

        explicit LoginPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::Widgets::WidgetBuilder::Ptr builder);
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

        GraphicLib::Widgets::Button::Ptr _logInButton;
        GraphicLib::Widgets::TextInputField::Ptr _loginInputField;
        GraphicLib::Widgets::TextInputField::Ptr _passwordInputField;
        GraphicLib::Widgets::TextBox::Ptr _messageBox{};

        GraphicLib::Widgets::Button::Ptr _editButton;
        GraphicLib::Widgets::Button::Ptr _exitButton;
        GraphicLib::Widgets::TextBox::Ptr _emailLabel{};
        GraphicLib::Widgets::TextBox::Ptr _nicknameLabel{};
        GraphicLib::Widgets::TextBox::Ptr _emailBox{};
        GraphicLib::Widgets::TextBox::Ptr _nicknameBox{};

        GraphicLib::Widgets::Button::Ptr _saveButton;
        GraphicLib::Widgets::TextInputField::Ptr _nicknameInputField;

        GraphicLib::Widgets::VerticalLayout::Ptr _startLayout;
        GraphicLib::Widgets::VerticalLayout::Ptr _viewLayout;
        GraphicLib::Widgets::VerticalLayout::Ptr _editLayout;

        Data::User _user{};
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_LOGINPAGE_HPP
