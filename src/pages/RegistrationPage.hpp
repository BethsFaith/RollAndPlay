//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "../data/User.hpp"
#include "../net/HttpSession.hpp"
#include "../widgets/VerticalLayout.hpp"
#include "BasePage.hpp"

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

        void init(const glm::vec2& screenOffset, const glm::vec2& min, const glm::vec2& max) override;

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
