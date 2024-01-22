//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../data/User.hpp"
#include "../widgets/TextForm.hpp"
#include "../widgets/ImageButton.hpp"

namespace Pages {
    class LoginPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW,
            EDIT,
        };

        using Ptr = std::shared_ptr<LoginPage>;

        explicit LoginPage(const GraphicLib::PickableTexture::Ptr& canvas);
        ~LoginPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toStart();
        void toView();
        void toEdit();

        bool validate(const std::u16string& login, const std::u16string& password);
        bool validate(const std::u16string& login, const std::u16string& password, const std::u16string& nickname);
        Net::HttpSession::Result logIn(const std::u16string& login, const std::u16string& password);
        Net::HttpSession::Result pullUserData();
        Net::HttpSession::Result changeUserData(const std::u16string& login,
                                                const std::u16string& password,
                                                const std::u16string& nickname);
        void showResultError(Net::HttpSession::Result& result);

        StateTag _nextState = START;

        Widgets::Button::Ptr _logInButton;
        Widgets::TextForm::Ptr _loginInputField;
        Widgets::TextForm::Ptr _passwordInputField;
        Widgets::TextBox::Ptr _messageBox;

        Widgets::Button::Ptr _editButton;
        Widgets::Button::Ptr _exitButton;
        Widgets::TextBox::Ptr _emailLabel;
        Widgets::TextBox::Ptr _nicknameLabel;
        Widgets::TextBox::Ptr _emailBox;
        Widgets::TextBox::Ptr _nicknameBox;

        Widgets::Button::Ptr _saveButton;
        Widgets::TextForm::Ptr _nicknameInputField;

        Data::User _user{};
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_LOGINPAGE_HPP
