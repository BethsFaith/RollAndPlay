//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_LOGINPAGE_HPP
#define ROLLANDPLAY_LOGINPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../data/User.hpp"
#include "../widgets/ImageButton.hpp"
#include "../widgets/TextInputField.hpp"
#include "../widgets/TextBox.hpp"

namespace Pages {
    class LoginPage : public BasePage {
    public:
        enum StateTag {
            START,
            VIEW,
            EDIT,
        };

        using Ptr = std::shared_ptr<LoginPage>;

        explicit LoginPage(GraphicLib::PickableTexture::Ptr canvas,  Widgets::WidgetBuilder::Ptr builder);
        ~LoginPage() override = default;

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

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
        Widgets::TextInputField::Ptr _loginInputField;
        Widgets::TextInputField::Ptr _passwordInputField;
        Widgets::TextBox::Ptr _messageBox{};

        Widgets::Button::Ptr _editButton;
        Widgets::Button::Ptr _exitButton;
        Widgets::TextBox::Ptr _emailLabel{};
        Widgets::TextBox::Ptr _nicknameLabel{};
        Widgets::TextBox::Ptr _emailBox{};
        Widgets::TextBox::Ptr _nicknameBox{};

        Widgets::Button::Ptr _saveButton;
        Widgets::TextInputField::Ptr _nicknameInputField;

        Widgets::VerticalLayout::Ptr _startLayout;
        Widgets::VerticalLayout::Ptr _viewLayout;
        Widgets::VerticalLayout::Ptr _editLayout;

        Data::User _user{};
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_LOGINPAGE_HPP
