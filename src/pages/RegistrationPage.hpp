//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "BasePage.hpp"
#include "../data/User.hpp"
#include "../widgets/VerticalLayout.hpp"
#include "../net/ApiClient.hpp"

namespace Pages {
    class RegistrationPage : public BasePage {
    public:
        enum StateTag {
            CREATE,
            VIEW,
        };

        using Ptr = std::shared_ptr<RegistrationPage>;

        explicit RegistrationPage(GraphicLib::PickableTexture::Ptr canvas, Widgets::WidgetBuilder::Ptr builder);
        ~RegistrationPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toCreate();
        void toView();

        static Net::HttpSession::Result registerUser(const std::u16string& login,
                                                     const std::u16string& password,
                                                     const std::u16string& nickname);

        bool validate(const std::u16string& login,
                      const std::u16string& password,
                      const std::u16string& repeatedPassword,
                      const std::u16string& nickname);
        void showResultRegistrationError(Net::HttpSession::Result& result);

        StateTag _currentTag = CREATE;

        Widgets::VerticalLayout::Ptr _inputFieldsLayout;
        Widgets::Button::Ptr _saveButton;
        Widgets::Button::Ptr _createButton;
        Widgets::TextInputField::Ptr _loginInputField;
        Widgets::TextInputField::Ptr _nicknameInputField;
        Widgets::TextInputField::Ptr _passwordInputField;
        Widgets::TextInputField::Ptr _repeatedPasswordInputField;
        Widgets::TextBox::Ptr _creatingMessageBox;
        Widgets::TextBox::Ptr _viewMessageBox;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_REGISTRATIONPAGE_HPP
