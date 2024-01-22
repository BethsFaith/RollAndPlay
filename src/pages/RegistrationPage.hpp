//
// Created by VerOchka on 06.01.2024.
//

#ifndef ROLLANDPLAY_REGISTRATIONPAGE_HPP
#define ROLLANDPLAY_REGISTRATIONPAGE_HPP

#include <GraphicLib/Primitives/Rectangle.hpp>

#include "../data/User.hpp"
#include "../widgets/TextBox.hpp"
#include "../net/ApiClient.hpp"
#include "BasePage.hpp"

namespace Pages {
    class RegistrationPage : public BasePage {
    public:
        enum StateTag {
            CREATE,
            VIEW,
        };

        using Ptr = std::shared_ptr<RegistrationPage>;

        explicit RegistrationPage(const GraphicLib::PickableTexture::Ptr& canvas);
        ~RegistrationPage() override = default;

        void init(const glm::vec2& screenOffset) override;

    private:
        void update() override;
        void toCreate();
        void toView();

        static Net::HttpSession::Result registerUser(const std::u16string& login, const std::u16string& password);

        bool validate(const std::u16string& login,
                      const std::u16string& password,
                      const std::u16string& repeatedPassword);
        void showResultRegistrationError(Net::HttpSession::Result& result);

        StateTag _currentTag = CREATE;

        Widgets::Button::Ptr _saveButton;
        Widgets::Button::Ptr _createButton;
        Widgets::TextForm::Ptr _loginInputField;
        Widgets::TextForm::Ptr _passwordInputField;
        Widgets::TextForm::Ptr _repeatedPasswordInputField;
        Widgets::TextBox::Ptr _creatingMessageBox;
        Widgets::TextBox::Ptr _viewMessageBox;
    };
}    //namespace Pages

#endif    //ROLLANDPLAY_REGISTRATIONPAGE_HPP
