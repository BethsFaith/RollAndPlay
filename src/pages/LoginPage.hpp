//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

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

        explicit LoginPage(const GraphicLib::PickableTexture::Ptr &canvas);
        ~LoginPage() override = default;

        void init(const glm::vec2 &screenOffset) override;

    private:
        void update() override;
        void toStart();
        void toView();
        void toEdit();

        bool validate(const std::u16string& login, const std::u16string& password);
        bool validate(const std::u16string& login, const std::u16string& password, const std::u16string& nickname);
        Net::HttpSession::Result logIn(const std::u16string& login, const std::u16string& password);
        Net::HttpSession::Result pullUserData();
        Net::HttpSession::Result changeUserData(const std::u16string& login, const std::u16string& password,
                                                const std::u16string& nickname);
        void showResultError(Net::HttpSession::Result& result);

        StateTag _nextState = START;

        Forms::Button::Ptr _logInButton;
        Forms::InputField::Ptr _loginInputField;
        Forms::InputField::Ptr _passwordInputField;
        Forms::TextBox::Ptr _messageBox;

        Forms::Button::Ptr _editButton;
        Forms::Button::Ptr _exitButton;
        Forms::TextBox::Ptr _emailLabel;
        Forms::TextBox::Ptr _nicknameLabel;
        Forms::TextBox::Ptr _emailBox;
        Forms::TextBox::Ptr _nicknameBox;

        Forms::Button::Ptr _saveButton;
        Forms::InputField::Ptr _nicknameInputField;

        Data::User _user{};
    };
}

#endif //ROLLANDPLAY_LOGINPAGE_HPP
