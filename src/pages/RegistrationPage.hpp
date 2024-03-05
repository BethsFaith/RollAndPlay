//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include "../data/User.hpp"
#include "../net/HttpSession.hpp"
#include "BasePage.hpp"

namespace Pages {
    class RegistrationPage : public BasePage {
    public:
        enum StateTag {
            CREATE,
            VIEW,
        };

        using Ptr = std::shared_ptr<RegistrationPage>;

        explicit RegistrationPage(GraphicLib::Objects::PickableTexture::Ptr canvas, GraphicLib::Widgets::WidgetBuilder::Ptr builder);
        ~RegistrationPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toCreate();
        void toView();

        static Net::ApiClient::Result registerUser(const std::u16string& login,
                                                     const std::u16string& password,
                                                     const std::u16string& nickname);

        bool validate(const std::u16string& login,
                      const std::u16string& password,
                      const std::u16string& repeatedPassword,
                      const std::u16string& nickname);
        void showResultRegistrationError(Net::ApiClient::Result& result);

        StateTag _currentTag = CREATE;

        GraphicLib::Widgets::Button::Ptr _saveButton;
        GraphicLib::Widgets::Button::Ptr _createButton;
        GraphicLib::Widgets::TextInputField::Ptr _loginInputField;
        GraphicLib::Widgets::TextInputField::Ptr _nicknameInputField;
        GraphicLib::Widgets::TextInputField::Ptr _passwordInputField;
        GraphicLib::Widgets::TextInputField::Ptr _repeatedPasswordInputField;
        GraphicLib::Widgets::TextBox::Ptr _creatingMessageBox;
        GraphicLib::Widgets::TextBox::Ptr _viewMessageBox;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_REGISTRATIONPAGE_HPP
